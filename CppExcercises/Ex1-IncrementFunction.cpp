/*Se debe implementar la función increment, que recibiendo un int lo incrementa 
sobre el mismo parámetro.

NT: Resolution oriented to pointers.*/
#include <cstdio>
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

void increment(int*&);

//int* globalPointer;
//size_t addresGlobal;

int main()
{
	int i = 2;
//	globalPointer = &i;
//	cout<<"First value Addres In function: " << &globalPointer << " and it's value: " << *globalPointer << endl;
    increment(i);	
  //  cout<<"Value Addres In Main: "<<&i<<endl;
	printf("%d\n", i); // Print 3
}

void increment(int*& value)
{
  //  *globalPointer = value++;
    *value++;
    //cout<<"Second value Addres In function: " << &globalPointer << " and it's value: " << *globalPointer << endl;
}

