#include "../peopleKingdom/person.cpp"
#include<iostream>
using namespace std;

template<class T>
class Node{
    private:
        T data;
        int height=0;
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
        //height
        void setHeight(int);
        int getHeight();
        //show
        void printNode();

        void printNodeLong();

        //for both
        Node<T>* getChildren(int);  // if int is 0--> left child, int=1-->rigth child
        void setChildren(Node<T>*,Node<T>*); //first sets left, then right

        // added to find king
        bool isLeaf();
        bool canBeKing();
        bool isGrandpa();
};