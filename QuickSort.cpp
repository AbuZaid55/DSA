#include<iostream>
using namespace std;

int partition(int arr[],int start,int end){
    int pivot = arr[start];
    int cnt = 0;
    for(int i=start;i<=end;i++){
        if(arr[i]<pivot){
            cnt++;
        }
    }
    int pivotIndex = start+cnt;
    swap(arr[start],arr[pivotIndex]);

    int i=start, j=end;
   
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i]<pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotIndex;
}

void QuickSort(int arr[],int start,int end){

    if(start>=end){
        return;
    }
    int p = partition(arr,start,end);

    QuickSort(arr,start,p-1);
    QuickSort(arr,p+1,end);
}

int main(){
    int arr[]={10,3,8,9,11,7,6,4,2,11,15,1,0,3,7};
    int size = sizeof(arr)/sizeof(arr[0]);

    QuickSort(arr,0,size-1);

    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}