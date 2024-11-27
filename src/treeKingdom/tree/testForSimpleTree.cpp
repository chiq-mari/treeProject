#include".\tree.cpp"

int main(){
    Tree<int> arbol;

    arbol.insert(8);
    arbol.printAsTree();
    cout<<"\n\n\n";
    arbol.insert(10);
    arbol.insert(3);
    arbol.printAsTree();
    cout<<"\n\n\n";
    arbol.insert(1);
    arbol.insert(6);
    arbol.insert(4);
    arbol.printAsTree();
    cout<<"\n\n\n";
    arbol.insert(7);
    arbol.insert(14);
    arbol.printAsTree();
    cout<<"\n\n\n";
    arbol.insert(13);
    cout<<"\n\n\n";
    arbol.printAsTree();

    arbol.printTree(0);
    cout<<endl;
    arbol.printTree(1);
    cout<<endl;
    arbol.printTree(2);
    cout<<"\n\n\n";

    Node<int>* ptrFound= arbol.findNodeInTree(14);
    cout<<ptrFound<<endl;
    if(ptrFound!=nullptr){
    cout<<ptrFound->getData()<<endl;
    }
    if(ptrFound->getLeftChild()!=nullptr){
    cout<<ptrFound->getLeftChild()->getData()<<endl;
    }
    if(ptrFound->getRightChild()!=nullptr){
    cout<<ptrFound->getRightChild()->getData()<<endl;
    }

}