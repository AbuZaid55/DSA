#include<iostream>
using namespace std;

void heapify(int arr[],int size,int i){

    int largestIndex = i;
    int leftIndex = 2*i+1;
    int rightIndex = 2*i+2;

    if(leftIndex<size && arr[largestIndex]<arr[leftIndex]){
        largestIndex=leftIndex;
    }
    if(rightIndex<size && arr[largestIndex]<arr[rightIndex]){
        largestIndex=rightIndex;
    }

    if(largestIndex!=i){
        swap(arr[i],arr[largestIndex]);
        heapify(arr,size,largestIndex);
    }
}

int main(){

    int arr[]={1,2,3,4,5,6,7,2,3};
    int size = sizeof(arr)/sizeof(arr[0]);

    for(int i=(size/2)-1;i>=0;i--){
        heapify(arr,size,i);
    }

    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}