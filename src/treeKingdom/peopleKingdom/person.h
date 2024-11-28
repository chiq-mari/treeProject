#include <iostream>
using namespace std;

class Person
{
    private: 
       int id;
       string name;
       string lastName;
       string gender;
       int age;
       int idFather;
       bool isDead;
       bool wasKing;
       bool isKing;
    public:
       Person(); //
       Person(int, string, string, string, int, int, bool, bool, bool);//
       ~Person();//

       // getting displayable data
       string getName();//
       string getLastName();//
       int getAge();//
       int getId();//
       int getIdFather();//
       
       string getGender();//
       
       // changing atributes
       void changeName(string);  //
       void changeLastName(string);  //
       void changeGender(string);  //
       void changeAge(int);  //
       void changeToDead();  //
       void changeWasKing(bool);  //
       void changeIsKing(bool);  //
       
       // useful functions
       bool isAlive();  //
       bool isActualKing(); //
       bool wasSomeKing(); //

       bool hasFather(Person); // //compares passed id with the person's father id
       bool hasChild(Person); // //tells whether the argument is a Child
       Person firstborn(Person, Person); // passed two children, returns firstborn*/
       // to use prior function, make sure both arguments are children of the person
       void printPerson();//
       void printWholePerson();//
};

