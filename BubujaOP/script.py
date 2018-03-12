#! /usr/bin/env python
#Librerias
import os


"""
En esta seccion se mandan el arreglo como argumentos para el 
ordenamiento de los numeros.
Esta seccion se puede modicar para empezar con el text con
el nombre del ejecutable desado 100,1000,5000,10000,50000,100000,
200000,400000,600000,800000,1000000,2000000,
3000000,4000000,5000000,6000000,7000000,
8000000,9000000,10000000
"""
pruebas = [100,1000,5000,50000,10000,50000,100000,
200000,400000,600000,800000,1000000]
for i in range(len(pruebas)):
	n = str(pruebas[i])
	text = './a.out '+n +' < numeros10millones.txt >> salBurbujaOP.txt'
	os.system(text)
