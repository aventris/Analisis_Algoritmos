def encontrar_f_fallos(cadena):
	indice=0
	comparar=0
	fallos=[]
	fallos.append(-1)
	fallos.append(0)
	for caracter in cadena:
		if indice==0 or (indice+1)==len(cadena):
			pass
		else:
			if cadena[indice]==cadena[comparar]:
				comparar+=1
				fallos.append(comparar)
			else:
				while comparar>0:
					comparar-=1
					if cadena[indice]==cadena[comparar]:
						comparar+=1
						break
				fallos.append(comparar)
		indice+=1
	return fallos

def encontrar_cadena(secuencia,patron,funcion_fallo):
	i=0
	indice=0
	while i<len(secuencia):
		if secuencia[i]==patron[indice]:
			if indice+1==len(patron):
				return "Patron encontrado"
			i+=1
			indice+=1
		else:
			mover=funcion_fallo[indice]
			if mover==-1:
				indice=0
				i+=1
			if mover==0:
				indice=0
			if mover>0:
				indice=mover
	return "Patron no encontrado"

secuencia="CTCACTGCCTGCCTAG"
patron="CTGCCTAG"
funcion_fallo=encontrar_f_fallos(patron)
print(funcion_fallo)
print(encontrar_cadena(secuencia,patron,funcion_fallo))
