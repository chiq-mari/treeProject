#include <iostream>
#include "../node/node.cpp"
using namespace std;

int main()
{
    Person people1;
    people1 = {30355203, "Marielv", "Mavarez", "female", 20, 7831758, 0, 0, 0};
    Person people2{30392967, "Mariangeles", "Mavarez", "female", 21, 7831758, 1, 1, 1};
    Person people3{7831758, "Ana", "Rangel", "female", 56, 3565988, 0, 1, 0};
    Person people4{7831758, "Amy", "Rochester", "male", 60, 4000000, 1, 1, 0};

    Node<Person> p1(people1, nullptr, nullptr);
    Node<Person> p2(people2, nullptr, nullptr);
    Node<Person> p3(people3, nullptr, nullptr);
    Node<Person> p4(people4, nullptr, nullptr);
    

    p1.printNode();
    p2.printNodeLong();

    cout<<p2.getData().hasFather(p3.getData());

    p3.getData().firstborn(p1.getData(), p2.getData()).printPerson();

    cout<<people2.hasFather(people1);
}