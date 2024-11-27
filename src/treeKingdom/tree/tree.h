#include "../node/node.cpp"
template<class T>
class Tree{
    private:
        Node<T>* root=nullptr; //unico atributo root

        //inserta un dato tipo T, en arbol de raiz (ptr a nodo en arg)
        //y retorna un ptr al nodo 
    public:
        //constructores
        Tree(); //creates empty tree
        Tree(T);   //creates tree with root T data given
        //destructores
        ~Tree();
        //other methods
        void insertGivenRoot(Node<T>*& , T);
        bool isEmpty(); //indica si el arbol esta vacio
        void insert(T); //inserta un dato del tipo T
        //void eliminate(T);  //elimina un dato del tipo T
        void printTree(int); //prints the tree in some given order
        void postOrden(Node<T>*);   //
        void inOrden(Node<T>*); //
        void preOrden(Node<T>*);    //

        void printAsTreeFromRoot(Node<T>*, int); //added for simple datatypes
        void printAsTree();
        void printing();
        //recorrido
        Node<T>* findNodeFromRoot(Node<T>*, T);
        Node<T>* findNodeInTree(T);
};