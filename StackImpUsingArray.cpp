#include<iostream>
using namespace std;
class Stack{

    public:
    int *arr;
    int top;
    int size;

    Stack(int size){
        this->size=size;
        arr= new int[size];
        this->top=-1;
    }

    void push(int element){
        if(size-top>1){
            top++;
            arr[top]=element;
        }else{
            cout<<"Stack is overflow"<<endl;
        }
    }

    void pop(){
        if(top>=0){
            top--;
        }else{
            cout<<"Stack is underflow "<<endl;
        }
    }

    int Top(){
        if(top>=0){
            return arr[top];
        }else{
            return -1;
        }
    }

    int Size(){
        return top+1;
    }

    bool isEmpty(){
        if(top==-1){
            return true;
        }else{
            return false;
        }
    }

};
int main(){

    //Creation of stack
    Stack st(5);

    //push operation
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    //pop operation
    st.pop();
    st.pop();

    //Print top element of stack
    if(st.Top()==-1){
        cout<<"Stack is empty"<<endl;
    }else{
        cout<<"Top element of stack is => "<<st.Top()<<endl;
    }

    //Print size of stack
    cout<<"Size of stack is => "<<st.Size()<<endl;

    //Print stack is empty or not
    if(st.isEmpty()){
        cout<<"Stack is empty "<<endl;
    }else{
        cout<<"Stack is not empty"<<endl;
    }
}