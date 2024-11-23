#include"./node.h"

//constructor
template<class T>
Node<T>::Node()
{
    this->left=nullptr;
    this->right=nullptr;
}

template<class T>
Node<T>::Node(T data, Node<T>* left, Node<T>* right)
{
    this->data=data;
    this->left=left;
    this->right=right;
}

//desctructor
template<class T>
Node<T>::~Node()
{
    this->left=nullptr;
    this->right=nullptr;
}

//data
template<class T>
void Node<T>:: setData(T data)
{
    this->data=data;
}

template<class T>
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

template<class T>
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

template<class T>
Node<T>* Node<T>:: getRightChild(){
    return this->right;
}

//show
template<class T>
void Node<T>:: printNode(){
    cout<<this->data;
}