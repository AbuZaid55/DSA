//Heap Sort
#include <iostream>
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

void HeapSort(int arr[],int n){

    int size = n;
    while(size>0){
        swap(arr[size-1],arr[0]);
        size--;

        heapify(arr,size,0);
    }
}

int main(){

    // Normal array
    int arr[]={1,2,3,4,5,6,7,2,3};
    int size = sizeof(arr)/sizeof(arr[0]);

    //Change normal array into heap
    for(int i=(size/2)-1;i>=0;i--){
        heapify(arr,size,i);
    }
    
    //Sort array using heap sort
    HeapSort(arr,size);

    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}