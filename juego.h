#ifndef JUEGO_H
#define JUEGO_H

#define FILAS 60
#define COLUMNAS 60

#define VISTA_FILAS 20
#define VISTA_COLUMNAS 20

typedef struct
{
    int fila;
    int columna;

    int monedas;
    int tieneLlave;
    int pasos;

} Jugador;

/*=============================
    FUNCIONES EN C
=============================*/

void ejecutarJuego();

void jugarNivel(
    char mapa[FILAS][COLUMNAS],
    int nivel
);

void mostrarVentana(
    char mapa[FILAS][COLUMNAS],
    Jugador jugador
);

void encontrarJugador(
    char mapa[FILAS][COLUMNAS],
    Jugador *jugador
);

void moverJugador(
    char mapa[FILAS][COLUMNAS],
    Jugador *jugador,
    char movimiento
);

void mostrarResumenNivel(
    int nivel,
    int monedasRecolectadas,
    int monedasTotales,
    int pasos
);

void mostrarResumenFinal(
    int monedasRecolectadas,
    int monedasTotales,
    int pasosTotales,
    int nivelesCompletados,
    int puntaje
);

/*=============================
    FUNCIONES NASM
=============================*/

extern long contarCaracteres(
    char *mapa,
    long totalCeldas,
    char caracter
);

extern long validarMovimiento(
    char *mapa,
    long columnas,
    long fila,
    long columna
);

extern long calcularPuntaje(
    long monedas,
    long pasos,
    long niveles
);

extern long detectarObjeto(
    char *mapa,
    long columnas,
    long fila,
    long columna,
    long objeto
);

extern long contarCeldasLibres(
    char *mapa,
    long totalCeldas
);

#endif