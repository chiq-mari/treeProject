#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>
#include ".\treeKingdom\tree\tree.cpp"

using namespace std;

void generateTree(Tree<Person> &myTree); //function that will insert the people to the tree
// i.e. Tree must be empty clearly, i.e. have a null root

int main()
{
    Tree<Person> myKTree;

    generateTree(myKTree);
    
    Node<Person>* testingRoot = myKTree.findNodeInTree(9977012);
    myKTree.printing(testingRoot);
}

void generateTree(Tree<Person> &myTree)
{
    fstream inPeople("../bin/data.csv", ios::in);
    
    if(!inPeople.is_open())
    {
        cout<<"The requested file could not be open"<<endl;
        return;
    }
    // declaring holders  
    string idString;
    int id;
    string name;
    string lastName;
    string gender;
    string ageString;
    int age;
    string idFatherString;
    int idFather;
    string isDeadString;
    int isDeadInt;
    bool isDead;
    string wasKingString;
    int wasKingInt;
    bool wasKing;
    string isKingString;
    int isKingInt;
    bool isKing;
    string dataLine;  // csv lineholder
    getline(inPeople, dataLine); // file header
    Person personTree; // person holder

    while(!inPeople.eof())
    {
        getline(inPeople, dataLine);
        stringstream s(dataLine);
        getline(s, idString, ',');
        id = stoi(idString);
        getline(s, name, ',');
        getline(s, lastName, ',');
        getline(s, gender, ',');
        getline(s, ageString, ',');
        age = stoi(ageString);
        getline(s, idFatherString, ',');
        idFather = stoi(idFatherString);
        getline(s, isDeadString, ',');
        isDeadInt = stoi(isDeadString);
        isDead = (bool)isDeadInt;
        getline(s, wasKingString, ',');
        wasKingInt = stoi(wasKingString);
        wasKing = (bool)wasKingInt;
        getline(s, isKingString, ',');
        isKingInt = stoi(isKingString);
        isKing = (bool)isKingInt;
        // stores a kingdom citizen atributes at a class Person
        personTree = {id, name, lastName, gender, age, idFather, isDead, wasKing, isKing};
        
        myTree.insert(personTree);
    }

    inPeople.close();
}