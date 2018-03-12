#!/bin/bash
# -*- ENCODING: UTF-8 -*-
#Script para ABB

gcc -Wall Shell.c tiempo.c -lm

./a.out 100 < numeros10millones.txt >> salida_Shell.txt
./a.out 1000 < numeros10millones.txt >> salida_Shell.txt
./a.out 5000 < numeros10millones.txt >> salida_Shell.txt
./a.out 10000 < numeros10millones.txt >> salida_Shell.txt
./a.out 50000 < numeros10millones.txt >> salida_Shell.txt
./a.out 100000 < numeros10millones.txt >> salida_Shell.txt
./a.out 200000 < numeros10millones.txt >> salida_Shell.txt
./a.out 400000 < numeros10millones.txt >> salida_Shell.txt
./a.out 600000 < numeros10millones.txt >> salida_Shell.txt
./a.out 800000 < numeros10millones.txt >> salida_Shell.txt
./a.out 1000000 < numeros10millones.txt >> salida_Shell.txt
./a.out 2000000 < numeros10millones.txt >> salida_Shell.txt
./a.out 3000000 < numeros10millones.txt >> salida_Shell.txt
./a.out 4000000 < numeros10millones.txt >> salida_Shell.txt
./a.out 5000000 < numeros10millones.txt >> salida_Shell.txt
./a.out 6000000 < numeros10millones.txt >> salida_Shell.txt
./a.out 7000000 < numeros10millones.txt >> salida_Shell.txt
./a.out 8000000 < numeros10millones.txt >> salida_Shell.txt
./a.out 9000000 < numeros10millones.txt >> salida_Shell.txt
./a.out 10000000 < numeros10millones.txt >> salida_Shell.txt

exit