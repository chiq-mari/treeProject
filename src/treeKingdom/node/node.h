#include<iostream>
using namespace std;

template<class T>
class Node{
    private:
    T data;
    Node<T>* left=nullptr;
    Node<T>* right=nullptr;

    public:
    //constructor
    Node();
    Node(T, Node<T>*, Node<T>*);
    //desctructor
    ~Node();
    //data
    void setData(T);
    T getData();
    //left
    void setLeftChild(Node<T>*);
    Node<T>* getLeftChild();
    //right
    void setRightChild(Node<T>*);
    Node<T>* getRightChild();
    //show
    void printNode();
};