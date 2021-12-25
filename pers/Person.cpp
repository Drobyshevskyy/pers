#include "Person.h"
using namespace std;
int Person::_nextID = 0;

Person::Person(const char* name, gender gend, Person* mother, Person* father):_ID(++_nextID) {
	aname = new char [strlen(name) + 1];
	strcpy(aname, name);
	aGender = gend;
	aMother = mother;
	aFather = father;
	
		if (name == nullptr) {
			throw logic_error("person should have a name");
		}
		if (_ID > 2 && mother == nullptr) {
			throw logic_error("one of the parents must be mother");
		}
		if (mother != nullptr && mother->aGender == gender::male) {
			throw logic_error("mother must be female");
		}
		if (father != nullptr && father->aGender == gender::female) {
			throw logic_error("father must be male");
		}
	

}
const char* Person::getGender() const {
	return this->aGender == gender::male ? "male" : "female";
}
char* Person::getName() const {
	return aname;
}
int Person::getID() const {
	return _ID;
}
char* Person::getMother() const {
	return aMother->getName();
}
char* Person::getFather() const {
	return aFather->getName();
}
void Person::erase() {
	delete[] aname;
}
void Person::print() {
	cout << "person's name: " << getName() << endl;
	cout << "person's ID: " << getID() << endl;
	cout << "person's gender: " << getGender() << endl;
	if (_ID > 2)
	{
			cout << "person's mother name: " << getMother() << endl;
		if (aFather != nullptr) {
			cout << "person's father name: " << getFather() << endl;
		}
		else {
			cout << "no father for this person" << endl;
		}
	}
	
}
Person Person::operator=(const Person p) {
	return Person(aname, aGender, aMother, aFather);
}
Person *Person::giveBirth(const char* name, gender gend, Person* father) {
	const char* addname = "";
	if (name != nullptr) {
		addname = name;
	}
	else {
		throw logic_error("baby should have a name");
	}
	auto child = new Person(addname, gend, this, father);
	return child;
}

