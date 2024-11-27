#include"./node.h"

//constructor
template<class T>   //
Node<T>::Node()
{
    this->left=nullptr;
    this->right=nullptr;
    this->height=0;
}

template<class T>   //
Node<T>::Node(T data, Node<T>* left, Node<T>* right)
{
    this->data=data;
    //children
    if(right!=NULL){ //si los hijos son distintos de null--> los cambia
        this->right=right;
    }
    if(left!=NULL){
        this->left=left;
    }
}

//destructor
template<class T>   //
Node<T>::~Node()
{
    this->left=nullptr;
    this->right=nullptr;
}

//data
template<class T>   //
void Node<T>:: setData(T data)
{
    this->data=data;
}

template<class T>   //
T Node<T>:: getData()
{
    return this->data;
}
    
//left
template<class T>
void Node<T>:: setLeftChild(Node<T>* left)
{
    this->left=left;
}

template<class T>   //
Node<T>* Node<T>::getLeftChild()
{
    return this->left;
}

//right
template<class T>
void Node<T>:: setRightChild(Node<T>*right)
{
    this->right=right;
}

template<class T>   //
Node<T>* Node<T>:: getRightChild(){
    return this->right;
}

//show
template<class T>   //
void Node<T>:: printNode(){
    cout<<this->data<<" ";      //solo para datos simples
}

//for both 
template <class T>  //
Node<T>* Node<T>::getChildren(int child){
    switch (child)
    {
    case 0:
        return this->left;
    case 1:
        return this->right;
    }
    return NULL;
}

template <class T>  //
void Node<T>::setChildren(Node<T>* left, Node<T>* right){
    if(right != NULL && left!=NULL){
        this->right=right;
        this->left=left;
    }else if(left!=NULL){
    this->left=left;
    }
    else if(right != NULL){
          this->right=right;
    }else{
        this->right=NULL;
        this->left=NULL;
    }
}

//case of heights
template <class T>  //  
void Node<T>::setHeight(int height){
    this->height=height;
}

template <class T>  //
int Node<T>::getHeight(){
   return this->height;
}