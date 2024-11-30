#include "../node/node.cpp"
template<class T>
class Tree{
    private:
        Node<T>* root=nullptr; //unico atributo root
        Node<T>* king=nullptr;  //node of king in actual tree

        //inserta un dato tipo T, en arbol de raiz (ptr a nodo en arg)
        //y retorna un ptr al nodo 
    public:
        //constructores
        Tree(); //creates empty tree
        Tree(T);   //creates tree with root T data given
        //destructores
        ~Tree();
        //other methods
        //void insertGivenRoot(Node<T>*& , T);
        bool isEmpty(); //indica si el arbol esta vacio
        void insert(T); //inserta un dato del tipo T
        //void eliminate(T);  //elimina un dato del tipo T
        void printTree(int); //prints the tree in some given order
        void postOrden(Node<T>*);   //
        void inOrden(Node<T>*); //
        void preOrden(Node<T>*);    //

        void printAsTreeFromRoot(Node<T>*, int); //added for simple datatypes
        void printAsTree();
        void printing(Node<T>*);
        //recorrido
        Node<T>* findNodeFromRoot(Node<T>*, int);
        Node<T>* findNodeInTree(int);

        //for king
        Node<T>* getKing();
        void setKing(Node<T>*);
        //finding king

        bool isLeaf(Node<T>*);

        Node<T>* findKingToTheRight(Node<T>*);
        Node<T>* findKingToTheLeft(Node<T>*);
        Node<T>* findKingDown(Node<T>*);

        Node<T>* findKing();
};