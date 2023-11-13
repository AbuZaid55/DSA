//Implementation of Queue using Linkedlist
#include<iostream>
using namespace std;
class Node{
    public:
    int value;
    Node* next;

    Node(int value){
        this->value=value;
        Node* next= NULL;
    }

};

void enqueue(Node* &front, Node* &rear,int value){
    
    Node* newNode = new Node(value);
    newNode->next=NULL;
    if(front==NULL){
        front=newNode;
        rear=newNode;
        return;
    }
    rear->next=newNode;
    rear=newNode;  
}

int dequeue(Node* &front,Node* &rear){
    if(front==NULL){
        cout<<"Queue is empty"<<endl;
        return -1;
    }else{
        Node*temp = front;
        int value = temp->value;
        if(temp->next==NULL){
            front=NULL;
            rear=NULL;
        }else{
            front=front->next;
        }
        temp->next=NULL;
        delete temp;
        return value;
    }
}
int size(Node* front, Node* rear){

    Node* temp = front;
    if(temp==NULL){
        return 0;
    }else{
        int cnt=1;
        while(temp->next!=NULL){
            temp=temp->next;
            cnt++;
        }
        return cnt;
    }

}
int Front(Node* front){
    if(front==NULL){
        cout<<"Queue is empty"<<endl;
        return -1;
    }else{
        cout<<"Front element of queue is => "<<front->value<<endl;
        return front->value;
    }
}
int Rear(Node* rear){
    if(rear==NULL){
        cout<<"Queue is empty"<<endl;
    }else{
        cout<<"Rear element of queue is => "<<rear->value<<endl;
        return rear->value;
    }
}
bool isEmpty(Node* front){
    if(front==NULL){
        return true;
    }else{
        return false;
    }
}
void display(Node* front) {
      if (front == NULL) {
        cout<<"Queue is empty"<<endl;
      } else {
        Node *temp = front;
        while (temp != NULL) {
          cout << temp->value << " ";
          temp = temp->next;
        }
        cout << endl;
      }
    }
int main(){
    
    Node* front = NULL;
    Node* rear = NULL;

    enqueue(front,rear,20);
    enqueue(front,rear,30);
    enqueue(front,rear,40);
    enqueue(front,rear,50);

    dequeue(front,rear);
    dequeue(front,rear);
    dequeue(front,rear);
    dequeue(front,rear);

    cout<<"Size of queue is =>"<<size(front,rear)<<endl;

    Front(front);
    Rear(rear);

    if(isEmpty(front)){
        cout<<"Queue is empty"<<endl;
    }else{
        cout<<"Queue is not empty"<<endl;
    }

    display(front);

}