#include".\tree.cpp"
/*
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
*/

int main()
{
    Person person1(3205117,"Tootsie","Bainbridge","Female",71,5688792,0,1,0);
    Person person2(4690818,"Ginelle","Kingsley","Female",70,3205117,0,1,0);
    Person person3(4911800,"Ariadne","Marchenko","Female",69,3205117,0,0,0);
    Person person4(6171932,"Roch","Jillard","Female",65,4911800,0,0,0);
    Person person5(6577415,"Andree","Dupre","Female",68,4911800,0,0,0);

    Tree<Person> arbol;
    
    arbol.insert(person1);
    arbol.insert(person2);
    arbol.insert(person3);
    arbol.insert(person4);
    arbol.insert(person5);

    Node<Person>* k= arbol.findNodeInTree(4911800);

    arbol.printing(k);



}