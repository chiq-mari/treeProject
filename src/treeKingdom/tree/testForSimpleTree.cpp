#include".\tree.cpp"

int main(){
    Tree<int> arbol;

    arbol.insert(8);
    arbol.printAsTree();
    cout<<"\n\n\n";
    arbol.insert(10);
    arbol.insert(1);
    arbol.printAsTree();
    cout<<"\n\n\n";
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
}