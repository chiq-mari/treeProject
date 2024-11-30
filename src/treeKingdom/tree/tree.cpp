#include "./tree.h"

//used for functions that are not specific for a child
enum ramas{IZQ,DER}; //izq=0; der=1

//constructores
template<class T>
Tree<T>::Tree()
{//creates empty tree
    this->root=nullptr;
}

template<class T>
Tree<T>::Tree(T data)
{  //creates tree with root T data given
    Node<T>* newNode= new Node<T>(data, nullptr, nullptr); //creates newNode
    this->root= newNode;    //sets given root as such newNode   
}


//destructor
template<class T>
Tree<T>::~Tree()
{  
    this->root=nullptr;
}

template<class T>
bool Tree<T>::isEmpty()
{
    return root==NULL;
}

/*
//inserts in the tree for the given Root of the tree to insert into
template<class T>
void Tree<T>::insertGivenRoot(Node<T>*& nodeRoot, T data)
{
    if(nodeRoot==nullptr)
    {  //if your root is null--> tree is empty
        Node<T>* newNode= new Node<T>(data, nullptr, nullptr); //creates newNode
        nodeRoot=newNode;
    }
    else
    {   //tree isn't empty
        T nodeRootValue = nodeRoot->getData(); //get data from given root
        if(data< nodeRootValue) //data belongs to the left
        {   
            //if the one to the left is null, creates node and add it
            if(nodeRoot->getLeftChild()==nullptr)
            {
                Node<T>* newNode= new Node<T>(data, nullptr, nullptr);
                nodeRoot->setLeftChild(newNode);
            }
            else
            {
            Node<T>* newRoot= nodeRoot->getLeftChild();
            //cout<<"Went to left\n";
            insertGivenRoot(newRoot, data);
            }
        }
        else //data belongs to the right
        {  
            //if the one to the right is null
            if(nodeRoot->getRightChild()==nullptr)
            {
                Node<T>* newNode= new Node<T>(data, nullptr, nullptr);
                nodeRoot->setRightChild(newNode);
            }
            else
            {
                Node<T>* newRoot= nodeRoot->getRightChild();
                insertGivenRoot(newRoot, data);
            }
        }
    }
}
*/

//original insert
template<class T>   //applies prev but with root the root of the tree
void Tree<T>:: insert(T data)
{   
    //insertGivenRoot(root, data);
    //-----------------------------

    Node<T>* nodeToInsert= new Node<T>(data, nullptr, nullptr); //creates node
    int fatherIdOfData= data.getIdFather();   //get id of father

    //searches node of his father
    Node<T>* father= findNodeInTree(fatherIdOfData);

    if(father==nullptr || this->root==nullptr) //there's no father and tree is empty
    {
      this->root=nodeToInsert; 
      return; 
    }
    else if(father==nullptr) // there's no father and tree isn't empty
    {
       cout<<"Such person does not have his father within the tree\n";
       return; 
    }
    else    //father isn't nullptr, so it's inside the tree
    {
        if(father->getRightChild()==nullptr)
        {   //if there's no first child
            father->setRightChild(nodeToInsert);    //just set it as the right one
            return;
        }
        else   // there is a first child inserted
        {
            if(father->getLeftChild()!= nullptr) //if there is other child--> impossible
            {
                cout<<"The father node cannot have more than 2 children\n";
                return;
            }
            //=>left child will be nullptr
            if(data.getAge()<=father->getRightChild()->getData().getAge())   // if age of new is smaller than age of right one
            {
                father->setLeftChild(nodeToInsert); //just set it as the left child;
                return;
            }
            else    //age of the person to insert is greater than age of the one inserted -=> he is the firstborn
            {
                Node<T>* temp= father->getRightChild(); // right child is 2nd child(the one to the left)
                father->setRightChild(nodeToInsert); //inserts newNode in right child
                father->setLeftChild(temp);
                return;
            }

        }

    }

}

//
template<class T>
void Tree<T>::printTree(int orden)
{
    switch (orden)
    {
    case 0:
        postOrden(root);
        break;
    case 1:
        inOrden(root);
        break;
    default:
        preOrden(root);
        break;
    }
};

//
template<class T>
void Tree<T>::postOrden(Node<T> *node)
{     //left/right/father
    if(node==NULL) return;      //if this is empty/ do nothing
   
    postOrden(node->getChildren(0));    //print postorden for left subtree
    postOrden(node->getChildren(1));    //print postorden for right subtree
    node->printNode();          //prints father
}

//
template<class T>
void Tree<T>::inOrden(Node<T> *node)
{   //left/father/right
    if(node==NULL) return;  //if this is empty/ do nothing
    inOrden(node->getChildren(0)); //start by doing inorden for the left subtree
    node->printNode();  //prints father
    inOrden(node->getChildren(1)); //then, inorden for the right subtree
    
}

//
template<class T>
void Tree<T>::preOrden(Node<T> *node)
{  //father/iz/der
    if(node==NULL) return;  //if this is empty/ do nothing
    node->printNode();  //start by printing the father
    preOrden(node->getChildren(0)); //then print starting from the left subtree 
    preOrden(node->getChildren(1)); //then print from the right subtree 
}

//
//In tree, will find address for node with person where the Id is the data given
template<class T>
Node<T>* Tree<T>::findNodeFromRoot(Node<T>* nodeRoot, int idGiven)
{
    if(nodeRoot==NULL)
    {
        return nullptr;  //if this is empty, it won't find the node with person of such id/ do nothing
    }   //tree isn't empty-> there is a root
    if (nodeRoot->getData().getId()==idGiven)
    {
        return nodeRoot;
    }  
    //if not in root, search in children
    Node<T>* ans1= findNodeFromRoot(nodeRoot->getChildren(0), idGiven); //then print starting from the left subtree 
    Node<T>* ans2= findNodeFromRoot(nodeRoot->getChildren(1), idGiven); //then print from the right subtree 
    if(ans1!=nullptr)
    {
        return ans1;
    }else if(ans2!=nullptr)
    {
        return ans2;
    }
    else
    {
        return nullptr;
    }
}

//find node with such id in the tree
template<class T>
Node<T>* Tree<T>::findNodeInTree(int idGiven)
{
    return findNodeFromRoot(this->root, idGiven);
}


//
template<class T>
void Tree<T>:: printAsTreeFromRoot(Node<T>* node, int cont)
{
    if(node==nullptr)
    {
        return;
    }
    else
    {
        printAsTreeFromRoot(node->getRightChild(), cont+1);
        for(int i=0; i<cont; i++){
            cout<<"   ";
        }
        node->printNode();
        cout<<endl;
        printAsTreeFromRoot(node->getLeftChild(), cont+1);
    }
}

//
template<class T>
void Tree<T>:: printAsTree()
{
    printAsTreeFromRoot(this->root, 0);
}

template<class T>
void Tree<T>:: printing(Node<T>* nodeRoot)
{
 nodeRoot->printNode();
 
 if(nodeRoot->getRightChild()!=nullptr)
 {
 nodeRoot->getRightChild()->printNode();
 }

 if(nodeRoot->getLeftChild()!=nullptr)
 {
 nodeRoot->getLeftChild()->printNode();
 }
}

//finding king- related
template<class T>
Node<T>* Tree<T>:: getKing()
{
    return this->king;
}

template<class T>        
void Tree<T>::setKing(Node<T>* king)
{
    this->king= king;
}

//finding king
template<class T>
Node<T>* Tree<T>:: findKingToTheRight(Node<T>* nodeRoot)
{
    if(nodeRoot==nullptr) //if there is no tree
    {
        return nullptr;
    }
    else    //if tree does exist
    {
        Node<T>* RightChildOfRoot= nodeRoot->getRightChild();
        Node<T>* LeftChildOfRoot = nodeRoot->getLeftChild();

        if(RightChildOfRoot==nullptr && LeftChildOfRoot==nullptr)   //if the old king did not have children
        {
            return nullptr; //-> no successor for the crown in his offspring
        }
        else    // if the old king did have children --> the first child (i.e the right one exists)
        {
            // first child alive and with appropriate age
            if(RightChildOfRoot->getData().isAlive() &&  RightChildOfRoot->getData().getAge()<71)
            {

                return RightChildOfRoot;
            }
            // first child not alive or with age over 70
            else
            {   
                //find king in the subtree of the first child
                Node<T>* rootOpt1= findKingToTheRight(RightChildOfRoot);
                if ( rootOpt1!=nullptr)
                {
                    return rootOpt1;
                }
                //if nothing was found in subtree of the right child
                /*else  //search in subtree of left child
                {
                  //Node<T>* rootOpt2= findKingToTheRight(LeftChildOfRoot);
                  //return rootOpt2;
                  continue;
                }
                continue;*/
            }
            Node<T>* rootOpt2= findKingToTheRight(LeftChildOfRoot);
            return rootOpt2;
        }
    }
}

template<class T>
Node<T>* Tree<T>:: findKingToTheLeft(Node<T>* nodeRoot)
{
    //get children of Root first
    Node<T>* RightChildOfRoot = nodeRoot->getRightChild();
    Node<T>* LeftChildOfRoot= nodeRoot->getLeftChild();

    if(nodeRoot==nullptr)   // tree does not exist
    {
        return nullptr;
    }
    //tree does exist --|
                      //V
    //if root does not have children
    if(RightChildOfRoot ==nullptr && LeftChildOfRoot==nullptr)
    {
        return nullptr;
    }
    // nodeRoot exists and is a father 

        //if the root does have children, but their children are leaves => nodeRoot isn't grandpa
        if (!nodeRoot->isGrandpa()){
            // 1 children leaf (right)
            if(LeftChildOfRoot == nullptr && RightChildOfRoot->isLeaf())
            {
                return nullptr;
            }
            //both children
            else //Left isn't null -->  2 children --> both leaves
            {
                if(LeftChildOfRoot->canBeKing())
                {
                    return LeftChildOfRoot;
                }
                else
                {
                    return nullptr;
                }
            }
        }
        else    // the children have children => nodeRoot is grandpa
        {
            //right child will always exist
            if(!RightChildOfRoot->isLeaf()) // right Child has children
            {
                //right child has one or two child => starts evaluating from right subtree of right child
                Node<T>* ansFromRightSubtreeOfRightSubtree = findKingToTheLeft(RightChildOfRoot->getRightChild());
                if(ansFromRightSubtreeOfRightSubtree!= nullptr)
                {
                    return ansFromRightSubtreeOfRightSubtree;
                }
            
                if(RightChildOfRoot->getLeftChild()!=nullptr)    // right Child has left child too
                {
                    Node<T>* ansFromLeftSubtreeOfRightSubtree = findKingToTheLeft(RightChildOfRoot->getLeftChild());
                    if(ansFromLeftSubtreeOfRightSubtree!= nullptr)
                    {
                        return ansFromLeftSubtreeOfRightSubtree;
                    }    

                    if(RightChildOfRoot->getLeftChild()->canBeKing()){
                        return RightChildOfRoot->getLeftChild();
                    }
                }
            }
            // either the right child did not have children or it just did not find a second born

            // move on to the left child of the given root

            if(LeftChildOfRoot ==nullptr)   // if there is not left child
            {
                return nullptr;     //return nothing
            }
            else    // if there is left child
            {   
                if(!LeftChildOfRoot->isLeaf())  // if then-> left child had children
                {
                    //if Left child has one or two children --> right one
                    Node<T>* ansFromRightSubtreeOfLeftSubtree= findKingToTheLeft(LeftChildOfRoot->getRightChild());
                    if(ansFromRightSubtreeOfLeftSubtree!=nullptr)
                    {
                        return ansFromRightSubtreeOfLeftSubtree;
                    }
                    
                    if(LeftChildOfRoot->getLeftChild()!= nullptr)    //left child has left child too
                    {
                        Node<T>* ansFromLeftSubtreeOfLeftSubtree= findKingToTheLeft(LeftChildOfRoot->getLeftChild());
                        if(ansFromLeftSubtreeOfLeftSubtree!=nullptr)
                        {
                            return ansFromLeftSubtreeOfLeftSubtree;
                        }

                        if (LeftChildOfRoot->getLeftChild()->canBeKing())
                        {
                            return LeftChildOfRoot->getLeftChild();
                        }
                        
                        if (LeftChildOfRoot->canBeKing())   // if it can be king, take it
                        {
                            return LeftChildOfRoot;
                        }

                    }
                }
                else    // if then--> left child was a leaf (no children)
                {
                    if (LeftChildOfRoot->canBeKing())   // if it can be king, take it
                    {
                        return LeftChildOfRoot;
                    }
                }

            }

        }// the children have children => nodeRoot is grandpa

   return nullptr;
}//nodeRoot exists and is a father

template<class T>
Node<T>* Tree<T>::findKingDown(Node<T>* nodeRoot)
{

}

template<class T>
Node<T>*Tree<T>:: findKing()
{

}