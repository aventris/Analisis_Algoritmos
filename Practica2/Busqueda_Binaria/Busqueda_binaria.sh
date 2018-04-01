#!/bin/bash
# -*- ENCODING: UTF-8 -*-
#Script para ABB

gcc -Wall Busqueda_binaria.c tiempo.c -lm

./a.out 100 < Numeros_Ordenados.txt >> salida_Binario.txt
./a.out 1000 < Numeros_Ordenados.txt >> salida_Binario.txt
./a.out 5000 < Numeros_Ordenados.txt >> salida_Binario.txt
./a.out 10000 < Numeros_Ordenados.txt >> salida_Binario.txt
./a.out 50000 < Numeros_Ordenados.txt >> salida_Binario.txt
./a.out 100000 < Numeros_Ordenados.txt >> salida_Binario.txt
./a.out 200000 < Numeros_Ordenados.txt >> salida_Binario.txt
./a.out 400000 < Numeros_Ordenados.txt >> salida_Binario.txt
./a.out 600000 < Numeros_Ordenados.txt >> salida_Binario.txt
./a.out 800000 < Numeros_Ordenados.txt >> salida_Binario.txt
./a.out 1000000 < Numeros_Ordenados.txt >> salida_Binario.txt
./a.out 2000000 < Numeros_Ordenados.txt >> salida_Binario.txt
./a.out 3000000 < Numeros_Ordenados.txt >> salida_Binario.txt
./a.out 4000000 < Numeros_Ordenados.txt >> salida_Binario.txt
./a.out 5000000 < Numeros_Ordenados.txt >> salida_Binario.txt
./a.out 6000000 < Numeros_Ordenados.txt >> salida_Binario.txt
./a.out 7000000 < Numeros_Ordenados.txt >> salida_Binario.txt
./a.out 8000000 < Numeros_Ordenados.txt >> salida_Binario.txt
./a.out 9000000 < Numeros_Ordenados.txt >> salida_Binario.txt
./a.out 10000000 < Numeros_Ordenados.txt >>	 salida_Binario.txt

exit