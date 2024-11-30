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
    Person person2(4690818,"Ginelle","Kingsley","Female",70,3205117,1,1,0);
    Person person3(4911800,"Ariadne","Marchenko","Female",69,3205117,0,0,0);
    Person person4(6171932,"Roch","Jillard","Female",65,4911800,0,0,0);
    Person person5(6577415,"Andree","Dupre","Female",68,4911800,1,0,0);
    Person person6(7652970,"Hilary","Murrie","Male",67,4690818,1,0,1);
    Person person7(9054378,"Lilllie","Collister","Female",66,4690818,0,0,0);
    Person person8(9648860,"Binky","Leggen","Male",60,7652970,0,0,0);
    Person person9(9669780,"Daniella","Cockburn","Female",65,7652970,1,0,0);
    Person person10(9977012,"Michel","Burless","Female",64,9054378,1,0,0);
    Person person11(10816975,"Fifine","Wigfall","Female",60,6171932,1,0,0);
    Person person12(12938948,"Yoko","Bracci","Female",55,6171932,0,0,0);
    Person person13(13057926,"Merell","Millsap","Male",54,9054378,0,0,0);
    Person person14(15088813,"Doug","Garbutt","Male",53,6577415,1,0,0);
    Person person15(16788635,"Mallory","Cordova","Male",52,6577415,0,0,0);
    Person person16(17057430,"Angeline","Whear","Female",51,9669780,1,0,0);
    Person person17(17813938,"Kari","Remmers","Female",50,13057926,1,0,0);
    Person person18(19092938,"Barbie","Fludder","Female",20,10816975,0,0,0);
    Person person19(19477947,"Garner","Jira","Male",20,9648860,0,0,0);
    Person person20(21769756,"Hi","Ivashev","Male",49,9648860,1,0,0);
    Person person21(23039858,"Rania","Lepick","Female",48,9669780,0,0,0);
    Person person22(23431360,"Martguerita","Gero","Female",47,13057926,0,0,0);
    Person person23(23831391,"Dodi","Cowins","Female",44,9977012,0,0,0);
    Person person24(23949766,"Alvy","Sheppard","Male",46,9977012,1,0,0);
    Person person25(25314402,"Franny","Phillcock","Male",45,16788635,1,0,0);
    Person person26(27092143,"Chad","Freckleton","Female",44,10816975,1,0,0);
    Person person27(27389927,"Kay","Gallimore","Female",43,15088813,1,0,0);
    Person person28(28461813,"Nanni","Rymmer","Female",42,16788635,0,0,0);
    Person person29(29076978,"Dreddy","Scinelli","Female",40,15088813,0,0,0);
    Person person30(29182614,"Lea","Hussy","Female",39,12938948,1,0,0);
    Person person31(29344611,"Daniel","Presswell","Male",38,12938948,0,0,0);

    Tree<Person> arbol;
    
    arbol.insert(person1);
    arbol.insert(person2);
    arbol.insert(person3);
    arbol.insert(person4);
    arbol.insert(person5);
    arbol.insert(person6);
    arbol.insert(person7);
    arbol.insert(person8);
    arbol.insert(person9);
    arbol.insert(person10);
    arbol.insert(person11);
    arbol.insert(person12);
    arbol.insert(person13);
    arbol.insert(person14);
    arbol.insert(person15);

    arbol.insert(person16);
    arbol.insert(person17);
    arbol.insert(person18);
    arbol.insert(person19);
    arbol.insert(person20);
    arbol.insert(person21);
    arbol.insert(person22);
    arbol.insert(person23);
    arbol.insert(person24);
    arbol.insert(person25);
    arbol.insert(person26);
    arbol.insert(person27);
    arbol.insert(person28);
    arbol.insert(person29);
    arbol.insert(person30);
    arbol.insert(person31);
    

    Node<Person>* k= arbol.findNodeInTree(3205117);

    arbol.printing(k);

    
    arbol.findKingToTheRight(k)->printNode();
}