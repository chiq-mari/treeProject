#include "person.h"
#include <iostream>
using namespace std;
//constructors
Person::Person(){};

Person::Person(int id, string name, string lastName, string gender, int age, int idFather, bool isDead, bool wasKing, bool isKing)
{
    this->id = id;
    this->name = name;
    this->lastName = lastName;
    this->gender = gender;
    this->age = age;
    this->idFather = idFather;
    this->isDead = isDead;
    this->wasKing = wasKing;
    this->isKing = isKing;
}

Person::~Person(){};
// get data
string Person::getName()
{
    return this->name;
}

string Person::getLastName()
{
    return this->lastName;
}

int Person::getAge()
{
    return this->age;
}

int Person::getId()
{
    return this->id;
}

int Person::getIdFather()
{
    return this->idFather;
}

string Person:: getGender()
{
    return this->gender;
}
//set data
void Person::changeName(string name)
{
    this->name = name;
}

void Person::changeLastName(string lastName)
{
    this->lastName = lastName;
}

void Person::changeGender(string gender)
{
    this->gender = gender;
}

void Person::changeAge(int age)
{
    this->age = age;
}

void Person::changeToDead() // if a person is dead,
{                         // they cannot be changed to be alive
    this->isDead = 1;
}

void Person::changeWasKing(bool wasKing)
{
    this->wasKing = wasKing;
}

void Person::changeIsKing(bool isKing)
{
    this->isKing = isKing;
}


//useful fucntions

bool Person::wasSomeKing(){
    return this->wasKing;
}

bool Person::isAlive()
{
    return !(this->isDead);
}

bool Person::isActualKing()
{
    return this->isKing;
}

bool Person::hasFather(Person fatherCandidate)
{
    return this->idFather == fatherCandidate.getId();
}

bool Person::hasChild(Person child)
{
    return child.getIdFather() == this->id;
}

Person Person::firstborn(Person childOne, Person childTwo)
{
    if(childOne.age>=childTwo.age)
    {
        return childOne;
    }
    else
    {
        return childTwo;
    }
}

void Person::printPerson()
{
    cout<<this->getName()<<" "<<this->getLastName()<<endl;
}

void Person::printWholePerson()
{
    cout<<this->id<<", "<<this->getName()<<" "<<this->getLastName()<<", "<<this->gender<<", "<<this->age<<", ";
    cout<<"father id: "<<this->idFather<<", ";
    if(this->isDead)
    {
        cout<<"dead, ";
    }
    else
    {
        cout<<"alive, ";
    }

    if(this->wasKing)
    {
        cout<<"was King, ";
    }
    else
    {
        cout<<"wasn't a King, ";
    }
    
    if(this->isKing)
    {
        cout<<"actual King"<<endl;
    }
    else
    {
        cout<<"not actual King"<<endl;
    }
}

