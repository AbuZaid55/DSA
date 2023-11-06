// Heap deletion

#include<iostream>
using namespace std;

void heapify(int arr[],int& size,int i){

    int largestIndex = i;
    int leftIndex = 2*i+1;
    int rightIndex = 2*i+2;

    if(rightIndex<size && arr[largestIndex]<arr[rightIndex]){
        largestIndex=rightIndex;
    }

    if(leftIndex<size && arr[largestIndex]<arr[leftIndex]){
        largestIndex=leftIndex;
    }

    if(largestIndex!=i){
        swap(arr[i],arr[largestIndex]);
        heapify(arr,size,largestIndex);
    }

}

void deleteformHeap(int arr[], int &size){

    arr[0]=arr[size-1];
    size--;
    heapify(arr,size,0);
}
int main(){
    
    int arr[]={60,55,54,53,50,52};
    int size = sizeof(arr)/sizeof(arr[0]);

    deleteformHeap(arr,size);

    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}