#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>
#include ".\treeKingdom\tree\tree.cpp"

using namespace std;

void generateTree(Tree<Person> &); //function that will insert the people to the tree
// i.e. Tree must be empty clearly, i.e. have a null root

void optionPanel(Tree<Person> &);
void changeDataPanel(int, Tree<Person>&);

// modify personal information field options in csv
void modifyField(int, int, string);

int main()
{
    Tree<Person> myKTree;

    generateTree(myKTree);
    
    Node<Person>* testingRoot = myKTree.findNodeInTree(9977012);
    myKTree.printing(testingRoot);

    optionPanel(myKTree);
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

void optionPanel(Tree<Person> &myTree)
{
    int option;
    bool keepExe = true;

  do
  {
    cout<<"Tell us: What would you like to do? "<<endl;
    cout<<"To know: Who is the actual King? (Option 1)"<<endl;
    cout<<"Visualize the crown's sucession line from actual King (Option 2)"<<endl;
    cout<<"Modify data in the tree (Option 3)"<<endl;
    cout<<"Add new member to the kingdom (Option 4)"<<endl;
    cout<<"Exit this program (Option 5)"<<endl;
    cout<<"Enter the number of your option here: ";

    cin>>option;
    switch(option)
    {
        case 1:
            cout<<"I currently don't know the actual king"<<endl<<endl;
            break;

        case 2: 
            cout<<"I currently can't tell you the crown's succesion line in the kingdom"<<endl<<endl;;
            break;


        case 3: 
            int personID;
            cout<<"Enter the ID of the person whose data you want to modify: ";
            cin>>personID;
            cout<<endl;
            changeDataPanel(personID, myTree);
            break;

        case 4: 
            cout<<"So, there is a new member in this kingdom eh?"<<endl;
            break; 

        case 5:
            cout<<"You'll exit this program now"<<endl;
            return;

        default: 
            cout<<"That is not a valid option, please try again"<<endl<<endl;
    }

  }
  while(true); 
}

void changeDataPanel(int idChangingPerson, Tree<Person> &myTree)
{
    int changingData;
    string newData;

    if(myTree.findNodeInTree(idChangingPerson) == nullptr)
    {
        cout<<"Such ID does not match any person at this Kingdom"<<endl;
        return;
    }
    else 
    {
        cout<<"You have entered ";
        myTree.findNodeInTree(idChangingPerson)->getData().printPerson();
        cout<<"'s ID"<<endl;
        cout<<"Please tell us which of the following fields of their personal information you would like to modify:"<<endl;
        cout<<"(Option 1) Name"<<endl;
        cout<<"(Option 2) Last Name"<<endl;
        cout<<"(Option 3) Gender"<<endl;
        cout<<"(Option 4) Age"<<endl;
        cout<<"(Option 5) Update life status to dead"<<endl;
        cout<<"(Option 6) Was king?"<<endl;
        cout<<"(Option 7) Is current king?"<<endl;
        cout<<"Enter your the number of your option here: ";
        cin>>changingData;
        
        switch(changingData)
        {
            case 1:
               {
                cout<<"Enter the new name: ";
                cin>>newData;
                modifyField(idChangingPerson, changingData, newData);
                cout<<endl;
                break;
               }
            case 2:
                {
                cout<<"Enter the new last name: ";
                cin>>newData;
                modifyField(idChangingPerson, changingData, newData);
                cout<<endl;
                break;
                }
            case 3:
                {
                cout<<"Enter the new gender: ";
                cin>>newData;
                modifyField(idChangingPerson, changingData, newData);
                cout<<endl;
                break;
                }
            case 4:
                {
                cout<<"Enter the new age: ";
                cin>>newData;
                modifyField(idChangingPerson, changingData, newData);
                cout<<endl;
                break;
                }
            case 5:
                {
                newData = "1";  // since this person status could only be updated if the person dies
                modifyField(idChangingPerson, changingData, newData);
                cout<<endl;
                break;
                }
            case 6:
                {
                  cout<<endl<<"Was ";
                  myTree.findNodeInTree(idChangingPerson)->getData().printPerson();
                  cout<<" a king?"<<endl<<"(Option 1) Yes"<<endl<<"(Option 2) No"<<endl<<"Enter the number of your option here: ";
                  cin>>newData;
                  int newDataInt = stoi(newData);
                  switch(newDataInt)
                  {
                    case 1:
                    {
                      modifyField(idChangingPerson, changingData, newData);
                      cout<<endl;
                      break;
                    }
                    case 2: 
                    { 
                      newData = "0";
                      modifyField(idChangingPerson, changingData, newData);
                      cout<<endl;
                      break;
                    }
                    default:
                    {
                      cout<<"That is not a valid option, please try again."<<endl;
                      break;
                    }
                  }
                  cout<<endl;
                  break;
                }
            case 7:
                {
                  cout<<endl<<"Is ";
                  myTree.findNodeInTree(idChangingPerson)->getData().printPerson();
                  cout<<" the current king?"<<endl<<"(Option 1) Yes"<<endl<<"(Option 2) No"<<endl<<"Enter the number of your option here: ";
                  cin>>newData;
                  cout<<"DATA TAKEN HOLDER";
                  break;
                }
            default: 
                {
                cout<<"That is not a valid option, please try again"<<endl<<endl;
                return;
                }
        }
    }
}

// functions to modify data
void modifyField(int idChPerson, int field, string newData)
{
    fstream inPeople("../bin/data.csv", ios::in);
    fstream outPeople("../bin/alternativeData.csv", ios::out);
    
    if(!inPeople.is_open())
    {
        cout<<"The requested file could not be open"<<endl;
        return;
    }
    // declaring holders  
    string idString;
    string name;
    string lastName;
    string gender;
    string ageString;
    string idFatherString;
    string isDeadString;
    string wasKingString;
    string isKingString;
    string dataLine;  // csv lineholder

    getline(inPeople, dataLine); // file header
    outPeople<<dataLine;
    bool foundData = false; 

    Person personTree;
    while(!inPeople.eof())
    {   
        outPeople<<endl;
        getline(inPeople, dataLine);
        stringstream s(dataLine);
        getline(s, idString, ',');
        getline(s, name, ',');
        getline(s, lastName, ',');
        getline(s, gender, ',');
        getline(s, ageString, ',');
        getline(s, idFatherString, ',');
        getline(s, isDeadString, ',');
        getline(s, wasKingString, ',');
        getline(s, isKingString, ',');
        
        if(foundData == false)
        {
            // check whether which field of information will be changed 
           switch(field)  // check whether we are in the line of the person whose information will be changed
           {              // change the  information field and whether the data was changed
               case 1: 
                  if(stoi(idString) == idChPerson)
                  {
                    name = newData;
                    cout<<"Name updated succesfully"<<endl;
                    foundData = true;
                  }
                  break;
                
                case 2: 
                   if(stoi(idString) == idChPerson)
                  {
                    lastName = newData;
                    cout<<"Last name updated succesfully"<<endl;
                    foundData = true;
                  }
                  break;

                case 3: 
                   if(stoi(idString) == idChPerson)
                  {
                    gender = newData;
                    cout<<"Gender updated succesfully"<<endl;
                    foundData = true;
                  }
                  break;
                
                case 4: 
                   if(stoi(idString) == idChPerson)
                  {
                    ageString = newData;
                    cout<<"Age updated succesfully"<<endl;
                    foundData = true;
                  }
                  break;

                case 5: 
                   if(stoi(idString) == idChPerson)
                  {
                    isDeadString = newData; 
                    cout<<"Updated to be dead succesfully"<<endl;
                    foundData = true;
                  }
                  break;

                case 6:
                   if(stoi(idString) == idChPerson)
                  {
                    wasKingString = newData;
                    cout<<"Was king field updated succesfully"<<endl;
                    foundData = true;
                  }
                  break;

                case 7: 
                   if(stoi(idString) == idChPerson)
                  {
                    isKingString = newData;
                    foundData = true;
                  }
                  break;
                
                default: 
                   break;
           }
        }
        outPeople<<idString<<","<<name<<","<<lastName<<","<<gender<<","<<ageString<<","<<idFatherString<<","<<isDeadString<<","<<wasKingString<<","<<isKingString;
    }  

    inPeople.close();
    outPeople.close();  

    fstream newOutPeople("../bin/data.csv", ios::out);
    fstream newInPeople("../bin/alternativeData.csv", ios::in);

    getline(newInPeople, dataLine);
    newOutPeople<<dataLine;

    do
    {
        newOutPeople<<endl;
        getline(newInPeople, dataLine);
        newOutPeople<<dataLine;
    }
    while (!newInPeople.eof());
    
    newInPeople.close();
    newOutPeople.close();  
}


