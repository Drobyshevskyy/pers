#pragma once
#pragma warning (disable:4996)
#include <iostream>


enum class gender {male, female};
class Person
{
private:
	const int _ID;
	char* aname;
	gender aGender;
	Person* aMother;
	Person* aFather;
	void erase();
	static int _nextID;
public:     
	int getID() const;
	char* getName() const;
	Person(const char*, gender, Person* = nullptr, Person* = nullptr);
	Person* giveBirth(const char*, gender, Person* = nullptr);
	void print();
	char* getMother() const;
	char* getFather() const;
	const char* getGender() const;
	Person operator = (const Person);
};
