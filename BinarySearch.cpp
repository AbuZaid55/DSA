#include<iostream>
using namespace std;

int binarySearch(int arr[], int size, int target){

    int start=0;
    int end=size-1;
    int mid=start+(end-start)/2;
    while(start<=end){
        if(arr[mid]==target){
            return mid;
        }else if(arr[mid]<target){
            start=mid+1;
        }else{
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    return -1;
}

int main(){

    int arr[]={0,1,2,3,8,9,13};
    int size = sizeof(arr)/sizeof(arr[0]);
    int index = binarySearch(arr,size,8);

    if(index==-1){
        cout<<"Target element not found!";
    }else{
        cout<<"Target element found at postion "<<index;
    }
}