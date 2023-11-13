#include<iostream>
#include <stack>
using namespace std;
int main(){
    
    //creation of stack
    stack<int>s;

    //push operation
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    //pop operation
    s.pop();
    s.pop();

    //print top element
    cout<<"Top Element => "<<s.top()<<endl;

    //print size of stack
    cout<<"Size of stack => "<<s.size()<<endl;

    //check stack is empty or not
    if(s.empty()){
        cout<<"Stack is empty"<<endl;
    }else{
        cout<<"Stack is not empty"<<endl;
    }
}