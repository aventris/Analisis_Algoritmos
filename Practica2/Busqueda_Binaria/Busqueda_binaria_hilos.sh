#!/bin/bash
# -*- ENCODING: UTF-8 -*-
#Script para ABB

gcc -Wall Busqueda_binaria_hilos.c tiempo.c -lm -pthread

./a.out 100 4 < Numeros_Ordenados.txt >> salida_Binario_hilos.txt
./a.out 1000 4 < Numeros_Ordenados.txt >> salida_Binario_hilos.txt
./a.out 5000 4 < Numeros_Ordenados.txt >> salida_Binario_hilos.txt
./a.out 10000 4 < Numeros_Ordenados.txt >> salida_Binario_hilos.txt
./a.out 50000 4 < Numeros_Ordenados.txt >> salida_Binario_hilos.txt
./a.out 100000 4 < Numeros_Ordenados.txt >> salida_Binario_hilos.txt
./a.out 200000 4 < Numeros_Ordenados.txt >> salida_Binario_hilos.txt
./a.out 400000 4 < Numeros_Ordenados.txt >> salida_Binario_hilos.txt
./a.out 600000 4 < Numeros_Ordenados.txt >> salida_Binario_hilos.txt
./a.out 800000 4 < Numeros_Ordenados.txt >> salida_Binario_hilos.txt
./a.out 1000000 4 < Numeros_Ordenados.txt >> salida_Binario_hilos.txt
./a.out 2000000 4 < Numeros_Ordenados.txt >> salida_Binario_hilos.txt
./a.out 3000000 4 < Numeros_Ordenados.txt >> salida_Binario_hilos.txt
./a.out 4000000 4 < Numeros_Ordenados.txt >> salida_Binario_hilos.txt
./a.out 5000000 4 < Numeros_Ordenados.txt >> salida_Binario_hilos.txt
./a.out 6000000 4 < Numeros_Ordenados.txt >> salida_Binario_hilos.txt
./a.out 7000000 4 < Numeros_Ordenados.txt >> salida_Binario_hilos.txt
./a.out 8000000 4 < Numeros_Ordenados.txt >> salida_Binario_hilos.txt
./a.out 9000000 4 < Numeros_Ordenados.txt >> salida_Binario_hilos.txt
./a.out 10000000 4 < Numeros_Ordenados.txt >>	 salida_Binario_hilos.txt

exit