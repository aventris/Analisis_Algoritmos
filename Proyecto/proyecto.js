function encontrar_f_fallos(cadena){
	var indice=0;
	var comparar=0;
	var fallos=[];
	fallos.push(-1);
	fallos.push(0);
	var arreglo=Array.from(cadena);
	//Creamos los divs de la función fallo
	var contenedor=document.getElementById("contenedor");
	for (var i=0;i<cadena.length;i++){
		var elemento=document.createElement("div");
		var texto=document.createTextNode(arreglo[i]);
		elemento.appendChild(texto);
		elemento.id=""+i;
		contenedor.appendChild(elemento);
	}
	$("#1").animate({
		left:'200px'
	},5000,function(){
		alert("Termine");
	});
	//calculamos función fallo
	for(var i=0;i<cadena.length;i++){
		if (indice==0 || (indice+1)==cadena.length){
			1+1;
		}else{
			if (arreglo[indice]==arreglo[comparar]){
				comparar++;
				fallos.push(comparar);
			}else{
				while (comparar>0){
					comparar--;
					if (arreglo[indice]==arreglo[comparar]){
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

function main(){
	var secuencia=document.getElementById("secuencia").value;
	var patron=document.getElementById("patron").value;
	var fallos=encontrar_f_fallos(patron);
	console.log(fallos);
}