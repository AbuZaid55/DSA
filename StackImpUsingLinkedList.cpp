#include<iostream>
using namespace std;

class Node{
    public:
    int value;
    Node* next;

    Node(int value){
        this->value=value;
        Node* next=NULL;
    }

};

void push(Node* &head,int value){
    Node* newNode = new Node(value);
    newNode->next=head;
    head=newNode;
}

int pop(Node* &head){
    if(head!=NULL){
        Node* temp = head;
        head=head->next;
        temp->next=NULL;
        delete temp;
        return temp->value;
    }else{
        cout<<"Stack is underflow"<<endl;
    }
}

int top(Node* head){
    if(head!=NULL){
        cout<<"Top element of stack is => "<<head->value<<endl;
        return head->value;
    }else{
        cout<<"Stack is empty"<<endl;
    }
}

int size(Node* head){
    int cnt = 0;
    Node* temp = head;
    while(temp!=NULL){
        temp=temp->next;
        cnt++;
    }
    return cnt;
}

bool isEmpty(Node* head){
    if(head==NULL){
        return true;
    }else{
        return false;
    }
}

int main(){
    
    Node* head = NULL;

    push(head,20);
    push(head,40);
    push(head,60);

    pop(head);

    top(head); //Output=>40

    cout<<"Size of stack is => "<<size(head)<<endl; //Output=> 2

    if(isEmpty(head)){
        cout<<"Stack is empty"<<endl; 
    }else{
        cout<<"Stack is not empty"<<endl;
    }

}