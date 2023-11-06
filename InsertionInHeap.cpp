// Heap insertion

#include<iostream>
using namespace std;
void insertHeap(int arr[],int &size,int value){

    int index = size;
    arr[index]=value;
    size=size+1;

    while(index>0){
        int parent = index/2;
        if(arr[parent]<arr[index]){
            swap(arr[parent],arr[index]);
            index=parent;
        }else{
            return;
        }
    }
}
int main(){
    int arr[100];
    int size = 0;

    insertHeap(arr,size,50);
    insertHeap(arr,size,55);
    insertHeap(arr,size,53);
    insertHeap(arr,size,52);
    insertHeap(arr,size,54);
    insertHeap(arr,size,60);

    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}