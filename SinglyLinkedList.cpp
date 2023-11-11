// Singly Linked List 
#include <iostream>
using namespace std;

class Node {

    public:
    int value;
    Node* ptr;

    Node(int value){
        this -> value = value;
        this -> ptr = NULL;
    }
};

void printLinkedList(Node* &head){
    Node* temp = head;
    while (temp!=NULL){
        cout<<temp->value<<" ";
        temp = temp -> ptr;
    }
    cout<<endl;
};

void insertAtHead(Node* &head , int value){

    //create new Node 
    Node* newNode = new Node(value);
    newNode->ptr=head;
    head=newNode;
};

void insertAtTail(Node* &tail,int value){
    
    //create new Node
    Node* newNode = new Node(value);
    tail->ptr=newNode;
    tail = newNode;
}

void insetAtPostion(Node* &head,Node* tail, int postion,int value){

    Node* temp = head;

    // if postion is equal to 1
    if(postion==1){
        insertAtHead(head,value);
        return;
    }

    //find Node on give postion
    int cnt = 1;
    while (cnt<postion-1)
    {
        temp = temp->ptr;
        cnt++;
    }

    //create new Node 
    Node* newNode = new Node(value);

    if(temp->ptr==NULL){
        insertAtTail(tail,value);
        return;
    }

    //Add new not on give postion
    newNode->ptr=temp->ptr;
    temp->ptr=newNode;
    
}

void deleteNode(Node* &head, int postion){

    if(postion==1){
        Node* temp = head;
        head=head->ptr;
        temp->ptr=NULL;
        delete temp;
    }else{

        Node* currNode = head;
        Node* preNode = NULL;

        int cnt = 1;
        while(cnt<postion){
            preNode = currNode;
            currNode=currNode->ptr;
            cnt++;
        }
        preNode->ptr = currNode->ptr;
        currNode->ptr=NULL;
        delete currNode;
    }
}

void updateNodeValue(Node* head,int postion, int value){
    
    Node* temp = head;
    int cnt = 1;
    while (cnt<postion)
    {
        temp = temp->ptr;
        cnt++;
    }
    temp->value=value;
    
}

int main(){
    
    //crate first Node
    Node* newNode = new Node(10);

    //Linkedlist head
    Node* head = newNode;
    Node* tail = newNode;

    //print Linkedlist
    printLinkedList(head); // Output=> 10

    //insert at head
    insertAtHead(head,15);
    insertAtHead(head,20);
    insertAtHead(head,25);

    //print Linkedlist
    printLinkedList(head); //Output=> 25 20 15 10

    //inset at tail
    insertAtTail(tail,5);
    insertAtTail(tail,0);

    //print Linkedlist
    printLinkedList(head); //Output=> 25 20 15 10 5 0

    // inset at any position 
    insetAtPostion(head,tail,1,30);
    insetAtPostion(head,tail,4,18);
    insetAtPostion(head,tail,9,-5);

     //print Linkedlist
    printLinkedList(head); //Output=> 30 25 20 18 15 10 5 0 -5

    //delete node
    deleteNode(head,1);
    deleteNode(head,3);
    deleteNode(head,7);

    //print Linkedlist
    printLinkedList(head); //Output=> 25 20 15 10 5 0 

    updateNodeValue(head,1,26);
    updateNodeValue(head,3,16);
    updateNodeValue(head,6,1);

    //print Linkedlist
    printLinkedList(head); //Output=> 26 20 16 10 5 1 
}