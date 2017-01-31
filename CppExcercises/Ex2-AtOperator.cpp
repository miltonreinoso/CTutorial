/*En desarrollo embebido en C, se usa una extensión llamada "at" (@) operator. 
Consiste en decir en qué posición poner una variable (generalmente porque 
corresponde a una dirección de memoria no física, en donde hay un puerto de hardware). 

Ejemplo:
	int pepe @ 0x123;
Hacer algo lo más parecido posible en C++:
	declare_at(type,name,address)
Notar que si la dirección que se pasa como tercer argumento no ha sido reservada,
declare_at ocasionará un error de ejecución. La memoria debe ser previamente reservada:
	int initialized[1];
	declare_at(int, pepe, &initialized);

NT: It could be any type of data but the array caus some errors that must be taken
care, that's why are in the example.*/