#ifndef MAPAS_H
#define MAPAS_H

#include "juego.h"


/*=================================
    NIVEL 1
=================================*/
void crearNivel1(char mapa[FILAS][COLUMNAS])
{
    int i, j;

    for(i=0;i<FILAS;i++)
    {
        for(j=0;j<COLUMNAS;j++)
        {
            if(i==0 || i==FILAS-1 ||
               j==0 || j==COLUMNAS-1)
                mapa[i][j]='#';
            else
                mapa[i][j]='.';
        }
    }

    for(i=5;i<55;i++)
        mapa[10][i]='#';

    for(i=5;i<50;i++)
        mapa[20][i]='#';

    for(i=10;i<55;i++)
        mapa[35][i]='#';

    mapa[1][1]='P';

    mapa[5][15]='M';
    mapa[7][25]='M';
    mapa[12][35]='M';
    mapa[18][45]='M';
    mapa[25][15]='M';

    mapa[30][10]='K';

    mapa[40][40]='D';

    mapa[55][55]='E';
}

/*=================================
    NIVEL 2
=================================*/
void crearNivel2(char mapa[FILAS][COLUMNAS])
{
    int i,j;

    for(i=0;i<FILAS;i++)
    {
        for(j=0;j<COLUMNAS;j++)
        {
            if(i==0 || i==FILAS-1 ||
               j==0 || j==COLUMNAS-1)
                mapa[i][j]='#';
            else
                mapa[i][j]='.';
        }
    }

    for(i=2;i<58;i+=4)
    {
        for(j=5;j<55;j++)
        {
            mapa[i][j]='#';
        }

        mapa[i][10]='.';
        mapa[i][30]='.';
        mapa[i][50]='.';
    }

    mapa[1][1]='P';

    mapa[8][12]='M';
    mapa[14][20]='M';
    mapa[22][42]='M';
    mapa[28][50]='M';
    mapa[36][25]='M';
    mapa[45][15]='M';
    mapa[52][40]='M';

    mapa[15][8]='K';

    mapa[45][45]='D';

    mapa[58][58]='E';
}

/*=================================
    NIVEL 3
=================================*/
void crearNivel3(char mapa[FILAS][COLUMNAS])
{
    int i,j;

    for(i=0;i<FILAS;i++)
    {
        for(j=0;j<COLUMNAS;j++)
        {
            if(i==0 || i==FILAS-1 ||
               j==0 || j==COLUMNAS-1)
                mapa[i][j]='#';
            else
                mapa[i][j]='.';
        }
    }

    for(i=4;i<56;i+=3)
    {
        for(j=3;j<57;j++)
        {
            mapa[i][j]='#';
        }

        mapa[i][8]='.';
        mapa[i][20]='.';
        mapa[i][35]='.';
        mapa[i][50]='.';
    }

    for(j=10;j<55;j+=5)
    {
        mapa[25][j]='#';
    }

    mapa[1][1]='P';

    mapa[6][15]='M';
    mapa[12][22]='M';
    mapa[18][30]='M';
    mapa[24][40]='M';
    mapa[30][18]='M';
    mapa[36][48]='M';
    mapa[42][25]='M';
    mapa[50][50]='M';

    mapa[10][45]='K';

    mapa[45][10]='D';

    mapa[58][58]='E';
}

#endif