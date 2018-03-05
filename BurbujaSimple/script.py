#! /usr/bin/env python
#Librerias
import os

n = raw_input("Ingrese la cantidad de numeros que desea: ")

"""
En esta seccion se mandan el arreglo como argumentos para el 
ordenamiento de los numeros.
Esta seccion se puede modicar para empezar con el text con
el nombre del ejecutable desado
"""
text = './Sbubble.o '+n +' < numeros10millones.txt > salBurbuja.txt'
print text

os.system(text)
