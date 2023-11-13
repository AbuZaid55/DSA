#include <iostream>
using namespace std;
class Queue{
    
    public:
    int *arr;
    int size;
    int front;
    int rear;

    Queue(int size){
        this->size=size;
        arr = new int[size];
        front=0;
        rear=0;
    }

    void enqueue (int value){
        if(rear==size-1){
            cout<<"Queue is full"<<endl;
        }else{
            arr[rear]=value;
            rear++;
        }
    }

    int dequeue(){
        
        if(front==rear){
            return -1;
        }else{
            arr[front]=-1;
            front++;
            if(front==rear){
                front=0;
                rear=0;
            }
        }
    }

    int Front(){
        if(front>=rear){
            cout<<"Queue is empty"<<endl;
            return -1;
        }else{
            cout<<"Front element of queue is => "<<arr[front]<<endl;
            return arr[front];
        }
    }
    int Rear(){
        if(front>=rear){
            cout<<"Queue is empty"<<endl;
            return -1;
        }else{
            cout<<"Rear element of queue is => "<<arr[rear-1]<<endl;
            return arr[rear];
        }
    }

    bool isEmpty(){
        if(front==rear){
            return true;
        }else{
            return false;
        }
    }
};
int main(){

    Queue qu(5);

    qu.enqueue(20);
    qu.enqueue(30);

    qu.dequeue();

    qu.Front();
    qu.Rear();

    if(qu.isEmpty()){
        cout<<"Queue is empty"<<endl;
    }else{
        cout<<"Queue is not empty"<<endl;
    }

}