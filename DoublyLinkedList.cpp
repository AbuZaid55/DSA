#include<iostream>
using namespace std;

class Node {
    public:
    Node* pre;
    int value;
    Node* next;

    Node(int value){
        this->pre=NULL;
        this->value=value;
        this->next=NULL;
    }
};

void printLinkedList(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->value<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void insertAtHead(Node* &head,int value){

    Node* newNode = new Node(value);
    head->pre = newNode;
    newNode->next=head;
    head=newNode;
}

void insetAtTail(Node* &tail,int value){
    Node* newNode = new Node(value);
    newNode->pre=tail;
    tail->next=newNode;
    tail=newNode;
}

void insetAtPostiion(Node* &head, Node* &tail,int position, int value){
    if(position==1){
        insertAtHead(head,value);
        return;
    }
    Node * temp = head;
    int cnt=1;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }
    
    if(temp->next==NULL){
        insetAtTail(tail,value);
        return;
    }

    Node* newNode = new Node(value);
    newNode->next=temp->next;
    newNode->pre=temp;
    temp->next->pre=newNode;
    temp->next= newNode;
}

void deleteNode(Node* &head, Node* &tail, int position){
    
    if(position==1){
        Node* temp = head;
        head=head->next;
        temp->pre=NULL;
        delete temp;
        return;
    }

    Node* current = head;
    int cnt=1;
    while(cnt<position){
        current=current->next;
        cnt++;
    }

    if(current->next==NULL){
        current->pre->next=NULL;
        tail=current->pre;
        current->pre=NULL;
        delete current;
        return;
    }

    current->pre->next=current->next;
    current->next->pre=current->pre;
    current->pre=NULL;
    current->next=NULL;
    delete current;

}

void updateNodeValue(Node* head,int postion, int value){
    
    Node* temp = head;
    int cnt = 1;
    while (cnt<postion)
    {
        temp = temp->next;
        cnt++;
    }
    temp->value=value;
    
}

int main(){
   
    Node* newNode = new Node(20);
    Node*head = newNode;
    Node*tail = newNode;

    printLinkedList(head); // Output=>20
    
    insertAtHead(head,25);
    insertAtHead(head,30);
    insertAtHead(head,35);

    printLinkedList(head); // Output=>35 30 25 20

    insetAtTail(tail,15);
    insetAtTail(tail,10);
    insetAtTail(tail,5);

    printLinkedList(head); // Output=>35 30 25 20 15 10 5

    insetAtPostiion(head,tail,1,40);
    insetAtPostiion(head,tail,3,38);
    insetAtPostiion(head,tail,10,0);

    printLinkedList(head); // Output=>40 35 38 30 25 20 15 10 5 0
    
    deleteNode(head,tail,1);
    deleteNode(head,tail,2);
    deleteNode(head,tail,8);

    printLinkedList(head); // Output=>35 30 25 20 15 10 5

    updateNodeValue(head,2,36);

    printLinkedList(head); // Output=>35 36 25 20 15 10 5
}