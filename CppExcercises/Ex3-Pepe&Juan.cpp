/*Dadas las siguientes estructuras:
Struct Pepe
{
	int x;
	int y;
	int z;
};
Struct Juan
{
	Pepe& pp;
	int a;
};

Lograr que esto compile y sea posible crear un objeto Juan. Imprimir por pantalla 
sizeof(Juan) y sizeof(Pepe).

¿Es válida la siguiente afirmación: “sizeof(Juan) == sizeof(Pepe) + sizeof(int)”?
Rta: No, porque sizeof(Pepe) != sizeof(Pepe&) que corresponde a una dirección.*/