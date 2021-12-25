#include <iostream>
#include "Person.h"

using namespace std;

int main() 
{
		Person Adam("Adam", gender::male);
		Person Eva("Eva", gender::female);
		Person Masha = *Eva.giveBirth("Masha", gender::female, &Adam);
		Person Ivan = *Eva.giveBirth("Ivan", gender::male, &Adam);
		Person Anya = *Masha.giveBirth("Anya", gender::female, &Ivan);
		Person Jenya = *Anya.giveBirth("Jenya", gender::male);
	Adam.print();
	cout << endl;
	Eva.print();
	cout << endl;
	Masha.print();
	cout << endl;
	Ivan.print();
	cout << endl;
	Anya.print();
	cout << endl;
	Jenya.print();
	system("PAUSE");
	return 0;
}