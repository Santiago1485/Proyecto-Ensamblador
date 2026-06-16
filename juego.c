#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

#include "juego.h"
#include "mapas.h"

int monedasTotalesJuego = 0;
int monedasRecolectadasJuego = 0;
int pasosTotalesJuego = 0;

/* Guarda el contenido de la casilla
   que pisa el jugador */
char objetoPisado = '.';


/*=========================================
    EJECUTAR JUEGO
=========================================*/

void ejecutarJuego()
{
    char nivel1[FILAS][COLUMNAS];
    char nivel2[FILAS][COLUMNAS];
    char nivel3[FILAS][COLUMNAS];

    crearNivel1(nivel1);
    crearNivel2(nivel2);
    crearNivel3(nivel3);

    jugarNivel(nivel1,1);
    jugarNivel(nivel2,2);
    jugarNivel(nivel3,3);

    long puntaje;

    puntaje =
        calcularPuntaje(
            monedasRecolectadasJuego,
            pasosTotalesJuego,
            3
        );

    mostrarResumenFinal(
        monedasRecolectadasJuego,
        monedasTotalesJuego,
        pasosTotalesJuego,
        3,
        puntaje
    );
}


/*=========================================
    BUSCAR JUGADOR
=========================================*/

void encontrarJugador(
    char mapa[FILAS][COLUMNAS],
    Jugador *jugador
)
{
    int i,j;

    for(i=0;i<FILAS;i++)
    {
        for(j=0;j<COLUMNAS;j++)
        {
            if(mapa[i][j]=='P')
            {
                jugador->fila=i;
                jugador->columna=j;

                jugador->monedas=0;
                jugador->tieneLlave=0;
                jugador->pasos=0;

                return;
            }
        }
    }
}


/*=========================================
    MOSTRAR VENTANA 20x20
=========================================*/

void mostrarVentana(
    char mapa[FILAS][COLUMNAS],
    Jugador jugador
)
{
    int inicioFila;
    int inicioColumna;

    int i,j;

    inicioFila = jugador.fila - 10;
    inicioColumna = jugador.columna - 10;

    if(inicioFila < 0)
        inicioFila = 0;

    if(inicioColumna < 0)
        inicioColumna = 0;

    if(inicioFila > FILAS - VISTA_FILAS)
        inicioFila = FILAS - VISTA_FILAS;

    if(inicioColumna > COLUMNAS - VISTA_COLUMNAS)
        inicioColumna = COLUMNAS - VISTA_COLUMNAS;

    for(i=0;i<VISTA_FILAS;i++)
    {
        for(j=0;j<VISTA_COLUMNAS;j++)
        {
            putchar(
                mapa[inicioFila+i]
                    [inicioColumna+j]
            );
        }

        printf("\n");
    }
}


/*=========================================
    MOVER JUGADOR
=========================================*/

void moverJugador(
    char mapa[FILAS][COLUMNAS],
    Jugador *jugador,
    char movimiento
)
{
    int nuevaFila;
    int nuevaColumna;

    nuevaFila = jugador->fila;
    nuevaColumna = jugador->columna;

    movimiento = tolower(movimiento);

    switch(movimiento)
    {
        case 'w':
            nuevaFila--;
            break;

        case 's':
            nuevaFila++;
            break;

        case 'a':
            nuevaColumna--;
            break;

        case 'd':
            nuevaColumna++;
            break;

        default:
            return;
    }

    if(nuevaFila < 0 ||
       nuevaFila >= FILAS)
        return;

    if(nuevaColumna < 0 ||
       nuevaColumna >= COLUMNAS)
        return;

    if(
        !validarMovimiento(
            &mapa[0][0],
            COLUMNAS,
            nuevaFila,
            nuevaColumna
        )
    )
    {
        return;
    }

    objetoPisado =
        mapa[nuevaFila][nuevaColumna];

    mapa
    [
        jugador->fila
    ]
    [
        jugador->columna
    ]='.';

    jugador->fila = nuevaFila;
    jugador->columna = nuevaColumna;

    mapa
    [
        jugador->fila
    ]
    [
        jugador->columna
    ]='P';

    jugador->pasos++;
}

/*=========================================
    JUGAR NIVEL
=========================================*/

void jugarNivel(
    char mapa[FILAS][COLUMNAS],
    int nivel
)
{
    Jugador jugador;

    encontrarJugador(
        mapa,
        &jugador
    );

    int totalMonedas =
        contarCaracteres(
            &mapa[0][0],
            FILAS * COLUMNAS,
            'M'
        );

    monedasTotalesJuego +=
        totalMonedas;

    char tecla;

    while(1)
    {
        system("cls");

        printf("=================================\n");
        printf("BITQUEST - NIVEL %d\n",nivel);
        printf("=================================\n");

        printf(
            "Monedas: %d/%d\n",
            jugador.monedas,
            totalMonedas
        );

        printf(
            "Llave: %s\n",
            jugador.tieneLlave ?
            "SI" :
            "NO"
        );

        printf(
            "Pasos: %d\n\n",
            jugador.pasos
        );

        mostrarVentana(
            mapa,
            jugador
        );

        printf(
            "\nW,A,S,D mover | Q salir\n"
        );

        tecla = getch();

        tecla = tolower(tecla);

        if(tecla=='q')
        {
            exit(0);
        }

        int filaAnterior =
            jugador.fila;

        int columnaAnterior =
            jugador.columna;

        moverJugador(
            mapa,
            &jugador,
            tecla
        );

        /*=========================
            MONEDA
        =========================*/

        if(objetoPisado=='M')
        {
            jugador.monedas++;

            objetoPisado='.';
        }

        /*=========================
            LLAVE
        =========================*/

        if(objetoPisado=='K')
        {
            jugador.tieneLlave=1;

            objetoPisado='.';
        }

        /*=========================
            PUERTA
        =========================*/

        if(objetoPisado=='D')
        {
            if(!jugador.tieneLlave)
            {
                mapa
                [
                    jugador.fila
                ]
                [
                    jugador.columna
                ]='D';

                jugador.fila =
                    filaAnterior;

                jugador.columna =
                    columnaAnterior;

                mapa
                [
                    jugador.fila
                ]
                [
                    jugador.columna
                ]='P';

                printf(
                    "\nNecesitas la llave.\n"
                );

                system("pause");
            }

            objetoPisado='.';
        }

        /*=========================
            SALIDA
        =========================*/

        if(objetoPisado=='E')
        {
            monedasRecolectadasJuego +=
                jugador.monedas;

            pasosTotalesJuego +=
                jugador.pasos;

            mostrarResumenNivel(
                nivel,
                jugador.monedas,
                totalMonedas,
                jugador.pasos
            );

            return;
        }
    }
}
/*=========================================
    RESUMEN NIVEL
=========================================*/
void mostrarResumenNivel(
    int nivel,
    int monedasRecolectadas,
    int monedasTotales,
    int pasos
)
{
    printf("\n=================================\n");
    printf("NIVEL %d COMPLETADO\n", nivel);
    printf("=================================\n");
    printf("Monedas: %d/%d\n",
           monedasRecolectadas,
           monedasTotales);
    printf("Pasos: %d\n", pasos);
    printf("=================================\n");

    system("pause");
}

/*=========================================
    RESUMEN FINAL
=========================================*/
void mostrarResumenFinal(
    int monedasRecolectadas,
    int monedasTotales,
    int pasosTotales,
    int nivelesCompletados,
    int puntaje
)
{
    system("cls");

    printf("=================================\n");
    printf("RESUMEN FINAL\n");
    printf("=================================\n");
    printf("Niveles completados: %d\n",
           nivelesCompletados);
    printf("Monedas: %d/%d\n",
           monedasRecolectadas,
           monedasTotales);
    printf("Pasos totales: %d\n",
           pasosTotales);
    printf("Puntaje final: %ld\n",
           (long)puntaje);
    printf("=================================\n");

    system("pause");
}