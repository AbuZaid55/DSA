// #include<iostream>
// using namespace std; 

// void merge(int arr[],int left_arr[],int leftArrSize,int right_arr[],int rightArrSize){

//     int i=0, j=0, k=start;
//     while (i<leftArrSize && j<rightArrSize){
//         if(left_arr[i]<=right_arr[j]){
//             arr[k]=left_arr[i];
//             i++;
//         }else{
//             arr[k]=right_arr[j];
//             j++;
//         }
//         k++;
//     }
//     while(i<leftArrSize){
//         arr[k++]=left_arr[i++];
//     }
//     while(j<rightArrSize){
//         arr[k++]=right_arr[j++];
//     }
    
// }
// void mergeSort(int arr[],int start,int end){
//     if(start>=end){
//         return;
//     }

//     int mid = (start+end)/2;
//     mergeSort(arr,start,mid);
//     mergeSort(arr,mid+1,end);
//     int left_arr[mid-start+1],right_arr[end-mid];

//     for(int i=0;i<=mid-start;i++){
//         left_arr[i]=arr[start+i];
//     }
//     for(int i=0;i<end-mid;i++){
//         right_arr[i]=arr[mid+1+i];
//     }

//     merge(arr,left_arr,mid-start+1,right_arr,end-mid);
// }

// int main(){

//     int arr[]={0,5,6,9,1,2,7};
//     int size = sizeof(arr)/sizeof(arr[0]);
//     mergeSort(arr,0,size-1);

//     //Print sorted array
//     cout<<"SortedArray=[";
//     for(int i=0;i<size;i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<"]";
// }


#include<iostream>
using namespace std;


void merge(int arr[],int start,int mid,int end){

    int left_arr[mid-start+1],right_arr[end-mid];
    for(int i=0;i<=mid-start;i++){
        left_arr[i]=arr[start+i];
    }
    for(int i=0;i<end-mid;i++){
        right_arr[i]=arr[mid+1+i];
    }

    int i=0,j=0,k=start;
    while(i<mid-start+1 && j<end-mid){
        if(left_arr[i]<=right_arr[j]){
            arr[k++]=left_arr[i++];
        }else{
            arr[k++]=right_arr[j++];
        }
    }
    while(i<mid-start+1){
        arr[k++]=left_arr[i++];
    }
    while(j<end-mid){
        arr[k++]=right_arr[j++];
    }
}

void mergeSort(int arr[],int start,int end){
    if(start>=end){
        return;
    }
    int mid = (start+end)/2;
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);
    merge(arr,start,mid,end);
}

int main(){
    int arr[]={3,4,8,7,6,2,0};
    int size = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,size-1);
    cout<<"SortedArray=[";
    for(int i=0;i<size;i++){
        if(i==size-1){
            cout<<arr[i];
        }else{
            cout<<arr[i]<<",";
        }
    }
    cout<<"]";
}