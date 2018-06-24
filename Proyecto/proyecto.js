function wait(ms){
   var start = new Date().getTime();
   var end = start;
   while(end < start + ms) {
     end = new Date().getTime();
  }
}
function limpiar(){
	var contenedor=document.getElementById("contenedor");
	contenedor.innerHTML="";
}
function addContenedor(caracter,i){
	var contenedor=document.getElementById("contenedor");
	elemento=document.createElement("div");
	texto=document.createTextNode(caracter);
	elemento.appendChild(texto);
	elemento.id=""+i;
	contenedor.appendChild(elemento);
}
function addContenedor2(num){
	var contenedor=document.getElementById("contenedor2");
	elemento=document.createElement("div");
	texto=document.createTextNode(num.toString());
	elemento.appendChild(texto);
	contenedor.appendChild(elemento);
	move('#contenedor2 div').set('background-color', 'green').duration('4s').end();
}
function encontrar_f_fallos(cadena){
	limpiar();
	var indice=0;
	var comparar=0;
	var fallos=[];
	//Creamos los dos primeros valores de la tabla de fallos
	fallos.push(-1);
	addContenedor2(-1);
	wait(7000);
	fallos.push(0);
	addContenedor2(0);
	//Creamos los divs de la función fallo
	for (var i=0;i<cadena.length;i++){
		addContenedor(cadena[i],i);
	}
	//calculamos función fallo
	for(var i=0;i<cadena.length;i++){
		if (indice==0 || (indice+1)==cadena.length){
			1+1;
		}else{
			if (cadena[indice]==cadena[comparar]){
				comparar++;
				fallos.push(comparar);
			}else{
				while (comparar>0){
					comparar--;
					if (cadena[indice]==cadena[comparar]){
						comparar++;
						break;
					}
				}
				fallos.push(comparar);
			}
		}
		indice++;
	}
	return fallos;
}
function encontrar_cadena(secuencia,patron,funcion_fallo){
	var i=0;
	var indice=0;
	var mover;
	while (i<secuencia.length){
		if (secuencia[i]==patron[indice]){
			if((indice+1)==patron.length){
				return "Patrón encontrado";
			}
			i++;
			indice++;
		}else{
			mover=funcion_fallo[indice];
			if (mover==-1){
				indice=0;
				i++;
			}
			if(mover==0){
				indice=0;
			}
			if(mover>0){
				indice=mover;
			}
		}
	}
	return "Patron no encontrado";
}
function main(){
	var secuencia=document.getElementById("secuencia").value;
	var patron=document.getElementById("patron").value;
	var fallos=encontrar_f_fallos(patron);
	console.log(fallos);
	console.log(encontrar_cadena(secuencia,patron,fallos));
}
function cargar(){
	document.getElementById("secuencia").value="CTCACTGCCTGCCTAG";
	document.getElementById("patron").value="CTGCCTAG";
}