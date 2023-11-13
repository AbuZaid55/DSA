// Circular Linked List 
#include <iostream>
using namespace std;

class Node {

    public:
    int value;
    Node* next;

    Node(int value){
        this -> value = value;
        this -> next = NULL;
    }
};

void printLinkedList(Node* tail){
    
    Node* head = tail->next;
    do
    {
        cout<<head->value<<" ";
        head=head->next;
    } while (head!=tail->next);
    cout<<endl;
    

};

void insertAtHead(Node* &tail,int value){

    Node* newNode = new Node(value);
    newNode->next=tail->next;
    tail->next=newNode;
}

void insetAtTail(Node* &tail, int value){

    Node* newNode = new Node(value);
    newNode->next=tail->next;
    tail->next=newNode;
    tail = newNode;
}

void insetAtPosition(Node* &tail,int position,int value){

    if(position==1){
        insetAtHead(tail,value);
        return;
    }

    Node* temp = tail->next;
    int cnt=1;
    while (cnt<position-1)
    {
        temp = temp->next;
        cnt++;
    }
    if(temp->next==tail->next){
        insetAtTail(tail,value);
        return;
    }
    Node* newNode = new Node(value);
    newNode->next=temp->next;
    temp->next=newNode;
    
}

void deleteNode(Node* &tail,int position){
    
    if(position==1){
        Node* temp = tail->next;
        tail->next=temp->next;
        temp->next=NULL;
        delete temp;
        return;
    }

    Node* current = tail->next;
    Node* pre = NULL;
    int cnt=1;
    while(cnt<position){
        pre=current;
        current=current->next;
        cnt++;
    }
    if(current->next==tail->next){
        Node*temp = tail;
        pre->next=tail->next;
        tail->next=NULL;
        tail=pre;
        delete temp;
        return;
    }
    pre->next=current->next;
    current->next=NULL;
    delete current;
}

void updateNode(Node* tail,int position, int value){

    Node* current = tail->next;
    int cnt=1;
    while(cnt<position){
        current=current->next;
        cnt++;
    }
    current->value=value;
}

int main(){
    
    Node* newNode = new Node(20);
    newNode->next=newNode;
    Node* tail = newNode;

    printLinkedList(tail); //Output=>20

    insetAtHead(tail,25);
    insetAtHead(tail,30);
    insetAtHead(tail,35);

    printLinkedList(tail); //Output=>35 30 25 20

    insetAtTail(tail,15);
    insetAtTail(tail,10);
    insetAtTail(tail,5);

    printLinkedList(tail); //Output=>35 30 25 20 15 10 5

    insetAtPosition(tail,1,40);
    insetAtPosition(tail,4,26);
    insetAtPosition(tail,10,0);

    printLinkedList(tail); //Output=>40 35 30 26 25 20 15 10 5 0

    deleteNode(tail,1);
    deleteNode(tail,3);
    deleteNode(tail,8);

    printLinkedList(tail); //Output=>35 30 25 20 15 10 5
    
    updateNode(tail,3,26);

    printLinkedList(tail); //Output=>35 30 26 20 15 10 5
  
}