#include "./tree.h"

//used for functions that are not specific for a child
enum ramas{IZQ,DER}; //izq=0; der=1

//constructores
template<class T>
Tree<T>::Tree()
{//creates empty tree
    this->root=nullptr;
}

template<class T>
Tree<T>::Tree(T data)
{  //creates tree with root T data given
    Node<T>* newNode= new Node<T>(data, nullptr, nullptr); //creates newNode
    this->root= newNode;    //sets given root as such newNode   
}


//destructor
template<class T>
Tree<T>::~Tree()
{  
    this->root=nullptr;
}

template<class T>
bool Tree<T>::isEmpty()
{
    return root==NULL;
}

//inserts in the tree for the given Root of the tree to insert into
template<class T>
void Tree<T>::insertGivenRoot(Node<T>*& nodeRoot, T data)
{
    if(nodeRoot==nullptr)
    {  //if your root is null--> tree is empty
        Node<T>* newNode= new Node<T>(data, nullptr, nullptr); //creates newNode
        nodeRoot=newNode;
    }
    else
    {   //tree isn't empty
        T nodeRootValue = nodeRoot->getData(); //get data from given root
        if(data< nodeRootValue) //data belongs to the left
        {   
            //if the one to the left is null, creates node and add it
            if(nodeRoot->getLeftChild()==nullptr)
            {
                Node<T>* newNode= new Node<T>(data, nullptr, nullptr);
                nodeRoot->setLeftChild(newNode);
            }
            else
            {
            Node<T>* newRoot= nodeRoot->getLeftChild();
            //cout<<"Went to left\n";
            insertGivenRoot(newRoot, data);
            }
        }
        else //data belongs to the right
        {  
            //if the one to the right is null
            if(nodeRoot->getRightChild()==nullptr)
            {
                Node<T>* newNode= new Node<T>(data, nullptr, nullptr);
                nodeRoot->setRightChild(newNode);
            }
            else
            {
                Node<T>* newRoot= nodeRoot->getRightChild();
                insertGivenRoot(newRoot, data);
            }
        }
    }
}

//original insert
template<class T>   //applies prev but with root the root of the tree
void Tree<T>:: insert(T data)
{   
    insertGivenRoot(root, data);
}

//
template<class T>
void Tree<T>::printTree(int orden)
{
    switch (orden)
    {
    case 0:
        postOrden(root);
        break;
    case 1:
        inOrden(root);
        break;
    default:
        preOrden(root);
        break;
    }
};

//
template<class T>
void Tree<T>::postOrden(Node<T> *node)
{     //left/right/father
    if(node==NULL) return;      //if this is empty/ do nothing
   
    postOrden(node->getChildren(0));    //print postorden for left subtree
    postOrden(node->getChildren(1));    //print postorden for right subtree
    node->printNode();          //prints father
}

//
template<class T>
void Tree<T>::inOrden(Node<T> *node)
{   //left/father/right
    if(node==NULL) return;  //if this is empty/ do nothing
    inOrden(node->getChildren(0)); //start by doing inorden for the left subtree
    node->printNode();  //prints father
    inOrden(node->getChildren(1)); //then, inorden for the right subtree
    
}

//
template<class T>
void Tree<T>::preOrden(Node<T> *node)
{  //father/iz/der
    if(node==NULL) return;  //if this is empty/ do nothing
    node->printNode();  //start by printing the father
    preOrden(node->getChildren(0)); //then print starting from the left subtree 
    preOrden(node->getChildren(1)); //then print from the right subtree 
}

//
template<class T>
void Tree<T>:: printAsTreeFromRoot(Node<T>* node, int cont)
{
    if(node==nullptr)
    {
        return;
    }
    else
    {
        printAsTreeFromRoot(node->getRightChild(), cont+1);
        for(int i=0; i<cont; i++){
            cout<<"   ";
        }
        node->printNode();
        cout<<endl;
        printAsTreeFromRoot(node->getLeftChild(), cont+1);
    }
}

//
template<class T>
void Tree<T>:: printAsTree()
{
    printAsTreeFromRoot(this->root, 0);
}


template<class T>
void Tree<T>:: printing()
{
 root->printNode();
 
 root->getRightChild()->printNode();

 root->getLeftChild()->printNode();

}