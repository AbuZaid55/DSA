#include<iostream>
#include<queue>
using namespace std;
int main(){

    queue<int>q;

    q.push(10);
    q.push(15);
    q.push(20);

    cout<<"Size of queue is => "<<q.size()<<endl;

    q.pop();

    cout<<"Size of queue is => "<<q.size()<<endl;

    cout<<"Front element of queue => "<<q.front()<<endl;
    cout<<"Rear element of queue => "<<q.back()<<endl;

    if(q.empty()){
        cout<<"Queue is empty"<<endl;
    }else{
        cout<<"Queue is not empty"<<endl;
    }
}