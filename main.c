#include <stdio.h>
#include <stdlib.h>

#include "juego.h"
#include "mapas.h"

int main()
{
    int opcion;

    do
    {
        system("cls");

        printf("====================================\n");
        printf("      BITQUEST - VERSION FINAL\n");
        printf("====================================\n");
        printf("1. Iniciar juego\n");
        printf("2. Salir\n");
        printf("====================================\n");
        printf("Opcion: ");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                ejecutarJuego();
                break;

            case 2:
                printf("\nHasta luego.\n");
                break;

            default:
                printf("\nOpcion invalida.\n");
                system("pause");
        }

    }while(opcion!=2);

    return 0;
}