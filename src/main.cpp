#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>
#include ".\treeKingdom\tree\tree.cpp"
#include ".\treeKingdom\peopleKingdom\person.cpp"

using namespace std;

// void generateTree(Tree &myTree) function that will insert the people to the tree
// i.e. Tree must be empty clearly, i.e. have a null root

void generateTree();  // draft of generateTree(Tree &myTree)
// made to check whether we were extracting the csv data correctly


int main()
{
    generateTree();
}

void generateTree()
{
    fstream inPeople("../bin/data.csv", ios::in);
    
    if(!inPeople.is_open()) // true = false that is open 
    {
        cout<<"The requested file could not be open"<<endl;
        return;
    }

    Person kingdomArray[31];
    
    string idString;  // int
    int id;

    string name;
    string lastName;
    string gender;

    string ageString; // int
    int age;

    string idFatherString; // int
    int idFather;

    string isDeadString; // int
    int isDeadInt;
    bool isDead;

    string wasKingString; // int
    int wasKingInt;
    bool wasKing;

    string isKingString; // int
    int isKingInt;
    bool isKing;

    string dataLine;

    getline(inPeople, dataLine); // file header

    /*getline(inPeople, dataLine); //first person in the entire kingdom, tree root
    stringstream s(dataLine);
    getline(s, idString, ',');
    id = stoi(idString);
    getline(s, name, ',');
    getline(s, lastName, ',');
    getline(s, gender, ',');
    getline(s, ageString, ',');
    age = stoi(ageString);
    getline(s, idFatherString, ',');     // CASE IN WHICH THE ROOT IS INSERTED AT TREE CREATION
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

    Person personRoot{id, name, lastName, gender, age, idFather, isDead, wasKing, isKing};
    kingdomArray[0] = personRoot;*/
    
    Person personTree;
    int counter = 0;
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
        personTree = {id, name, lastName, gender, age, idFather, isDead, wasKing, isKing};
       
       kingdomArray[counter] = personTree;
       counter += 1;
    }
    inPeople.close();

    for(int i = 0; i<31; i++)
    {
        kingdomArray[i].printWholePerson();
    }
}