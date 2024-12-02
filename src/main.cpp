#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>
#include ".\treeKingdom\tree\tree.cpp"

// controller = generate tree, change data panel,
//modify field, newKingdomMember
// view  == option panel
using namespace std;

void generateTree(Tree<Person> &); //function that will insert the people to the tree
// i.e. Tree must be empty clearly, i.e. have a null root

void optionPanel(Tree<Person> &);
void changeDataPanel(int, Tree<Person>&);

// modify personal information field options in csv
void modifyField(int, int, string);
// function to add a new member to the kingdom
void newKingdomMember(Tree<Person>&);

int main()
{
    Tree<Person> myKTree;

    generateTree(myKTree);
    
    optionPanel(myKTree);
}
/////////////////////////////////////////////////////////////////////////////////
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
//////////////////////////////////////////////////////////////////////////////////
void optionPanel(Tree<Person> &myTree)
{
    int option;
    bool keepExe = true;

  do
  {
    for(int i = 0; i<84; i++)
    {
      cout<<"_";
    }
    cout<<endl;
    for(int i = 0; i<25; i++)
    {
      cout<<" ";
    }
    cout<<"Tell us: What would you like to do?"<<endl;
    cout<<"(Option 1) To know: Who is the actual King?"<<endl;
    cout<<"(Option 2) Visualize the crown's sucession line from actual King"<<endl;
    cout<<"(Option 3) Modify data in the tree"<<endl;
    cout<<"(Option 4) Add new member to the kingdom"<<endl;
    cout<<"(Option 5) Exit this program"<<endl;
    cout<<"Enter the number of your option here: ";

    cin>>option;
    cout<<endl;
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
            cout<<"   Enter the ID of the person whose data you want to modify: ";
            cin>>personID;
            cout<<endl;
            changeDataPanel(personID, myTree);
            break;

        case 4: 
            newKingdomMember(myTree);
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
/////////////////////////////////////////////////////////////////////////////////////////
void changeDataPanel(int idChangingPerson, Tree<Person> &myTree)
{
    int changingData;
    string newData;
    int newDataInt;

    if(myTree.findNodeInTree(idChangingPerson) == nullptr)
    {
        cout<<"Such ID does not match any person at this Kingdom"<<endl;
        return;
    }
    else 
    {
        cout<<"          ** You have entered ";
        myTree.findNodeInTree(idChangingPerson)->getData().printPerson();
        cout<<"'s ID **"<<endl<<endl;
        cout<<"   Please tell us which of the following fields of their personal information you would like to modify:"<<endl<<endl;
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
                cout<<"   Enter the new name: ";
                cin>>newData;
                modifyField(idChangingPerson, changingData, newData);
                cout<<endl;
                break;
               }
            case 2:
                {
                cout<<"   Enter the new last name: ";
                cin>>newData;
                modifyField(idChangingPerson, changingData, newData);
                cout<<endl;
                break;
                }
            case 3:
              {
                do
                {
                  cout<<"   Select updated gender: "<<endl;
                  cout<<"   (Option 1) Female"<<endl<<"   (Option 2) Male"<<endl;
                  cout<<"   Enter the number of your option here: ";
                  cin>>newData;
                  newDataInt = stoi(newData);
                  switch(newDataInt)
                  {
                    case 1:
                    {
                      newData = "Female";
                      break;
                    }
                  case 2:
                    {
                      newData = "Male";
                      break;
                    }
                  default:
                  {
                    cout<<"      Invalid option. Please, try again."<<endl;
                    newDataInt = 0;
                    break;
                  }
                } 
                }
                while(newDataInt == 0);
                cout<<endl;  // asks for gender as long as an invalid gender is entered
                modifyField(idChangingPerson, changingData, newData);
                break;
              }

            case 4:
              {
                int fatherID;
                int fatherAge;
                string nameChangingPerson = myTree.findNodeInTree(idChangingPerson)->getData().getName();
                do
                {
                  cout<<"   Enter the updated age: ";
                  cin>>newData;
                  newDataInt = stoi(newData);
                  fatherID = myTree.findNodeInTree(idChangingPerson)->getData().getIdFather();
                  fatherAge = myTree.findNodeInTree(fatherID)->getData().getAge();
                  if(newDataInt>=fatherAge)
                  {
                    cout<<"      Invalid age. ";
                    cout<<nameChangingPerson<<"'s father is "<<fatherAge<<" years old. "<<nameChangingPerson<<"'s age must be smaller."<<endl;
                    cout<<"      Please, try again."<<endl;
                  }
                }
                while(newDataInt>=fatherAge);
                cout<<endl;  // asks for age as long as an invalid age is entered
                modifyField(idChangingPerson, changingData, newData);
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
  return;
}
/////////////////////////////////////////////////////////////////////////////////////////////


// functions to modify data in csv file
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
        {  // check whether the person whose info is to be changed was already found
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





///////////////////////////////////////////////////////////////////////////////////////////////
void newKingdomMember(Tree<Person> &myTree)
{
  fstream outPeople("../bin/data.csv", ios::app);

  if(!outPeople.is_open())
  {
    cout<<"The requested file could not be open"<<endl;
    return;
  }
  string idString;
  int id;
  string name;
  string lastName;
  string gender;
  int genderInt;
  string ageString;
  int age;
  string idFatherString;
  int idFather;
  bool isDead;
  bool wasKing;
  bool isKing;
  
  Person personTree;
  Node<Person>* tempHolder = nullptr;

  do
  {
    cout<<"   Enter the ID of the new family kingdom member: ";
    cin>>idString;
    id = stoi(idString);
    tempHolder = myTree.findNodeInTree(id);
    if(tempHolder != nullptr)
    {
      cout<<"      Such ID can't be used, because it already belongs to a person in this kingdom."<<endl;
      cout<<"      Please, try again."<<endl;
    }
  }
  while(tempHolder != nullptr);
  cout<<endl;  // asks for ID as long as it belongs to a person in the kingdom

  do
  {
    cout<<"   Enter the Father ID of the new family kingdom member: ";
    cin>>idFatherString;
    idFather = stoi(idFatherString);
    tempHolder = myTree.findNodeInTree(idFather);
    int numberChildren = 0;

    if(tempHolder == nullptr)
    {
      cout<<"      Such ID can't be used, because it does not belong to a person in this kingdom."<<endl;
      cout<<"      Please, try again."<<endl;
    }
    else
    {
      if(tempHolder->getRightChild() != nullptr)
      {
        numberChildren++;
      }
      if(tempHolder->getLeftChild() != nullptr)
      {
        numberChildren++;
      }

      if(numberChildren>1)
      {
        cout<<"      Invalid ID. The ID entered belongs to a person with 2 children."<<endl;
        cout<<"      Please, try again."<<endl;
        tempHolder = nullptr;
      }

    }
  }
  while (tempHolder == nullptr); // asks for  Father ID as long as it does not belongs to a person in the kingdom
  cout<<endl;   // and the person has not had two children

  cout<<"   Enter the name of the new member of the family kingdom: ";
  cin>>name;
  cout<<endl;  // Name 

  cout<<"   Enter the last name of the new member of the family kingdom: ";
  cin>>lastName;
  cout<<endl;   // Last Name
  
  do
  {
    cout<<"   Which of the following is the gender of the new family kingdom member? (Option 1) Female, (Option 2) Male"<<endl;
    cout<<"   Enter the number of your option here: ";
    cin>>gender;
    genderInt = stoi(gender);

      switch(genderInt)
      {
        case 1:
        {
          gender = "Female";
          break;
        }
        case 2:
        {
          gender = "Male";
          break;
        }
        default:
        {
          cout<<"      Invalid option. Please, try again."<<endl;
          genderInt = 0;
          break;
        }
      } 
  }
  while(genderInt == 0);
  cout<<endl;  // asks for gender as long as an invalid gender is entered

 int fatherAge;
  do
  {
    cout<<"   Enter the age of the new family kingdom member: ";
    cin>>ageString;
    age = stoi(ageString);
    tempHolder = myTree.findNodeInTree(idFather);
    fatherAge = tempHolder->getData().getAge();
    if(age>=fatherAge)
    {
      cout<<"      Invalid age. ";
      cout<<name<<"'s father is "<<fatherAge<<" years old. "<<name<<"'s age must be smaller."<<endl;
      cout<<"      Please, try again."<<endl;
    }
  }
  while(age>=fatherAge);
  cout<<endl;  // asks for age as long as an invalid age is entered

  isDead = 0; // we assume the new fam member is alive
  wasKing = 0; // we assume the new fam member has not been king
  isKing = 0; // we assume the new fam member is not the current king

  personTree = {id, name, lastName, gender, age, idFather, isDead, wasKing, isKing};

  outPeople<<endl;
  outPeople<<idString<<","<<name<<","<<lastName<<","<<gender<<","<<age<<","<<idFatherString<<","<<isDead<<","<<wasKing<<","<<isKing;
  outPeople.close();

  myTree.insert(personTree);
}
