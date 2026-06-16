BitQuest

Descripcion
BitQuest es un videojuego de consola desarrollado en lenguaje C y NASM para Windows x64. El jugador debe recorrer mapas de 60 × 60 posiciones en un cuadro de visión de 20 posiciones, recolectar monedas, obtener una llave, abrir una puerta y encontrar la salida para completar cada nivel.

Archivos del Proyecto

-main.c
-juego.c
-juego.h
-mapas.h
-rutinas.asm
-comp.bat

Requisitos

-GCC (MinGW)
-NASM
-Windows x64

Compilacion

Compilar el modulo ensamblador:
nasm -f win64 rutinas.asm -o rutinas.obj

Compilar los archivos C:
gcc -c main.c -o main.o
gcc -c juego.c -o juego.o

Generar el ejecutable:
gcc main.o juego.o rutinas.obj -o BitQuest.exe

Compilacion Automatica

Tambien puede utilizarse el archivo:
comp.bat
para realizar todo el proceso de compilación automaticamente.

Ejecucion

Ejecutar el programa:
BitQuest.exe

o ejecutar directamente:
comp.bat

