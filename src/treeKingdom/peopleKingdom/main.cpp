#include <iostream>
#include "person.cpp"
using namespace std;

int main()
{
    Person people1;
    people1 = {30355203, "Marielv", "Mavarez", "female", 20, 7831768, 0, 0, 0};
    Person people2{30392967, "Mariangeles", "Mavarez", "female", 21, 7831758, 1, 1, 1};
    Person people3{7831758, "Ana", "Rangel", "female", 56, 3565988, 0, 1, 0};
    Person people4{7831800, "Amy", "Rochester", "male", 60, 4000000, 1, 1, 0};
    people1.printWholePerson();
    people2.printWholePerson();
    people3.printWholePerson();
    people4.printWholePerson();

    people3.firstborn(people3, people4).printPerson();
}