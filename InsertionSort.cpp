// Insertion sort
#include <iostream>

using namespace std;

int main() {
  
  int arraySize;
  //Enter size of aray
  cout<<"Enter Array Size: ";
  cin>>arraySize;

  //Initialize  array
  int arr[arraySize];

  //Enter element of array
  for(int i=0;i<arraySize;i++){
    cout<<"Enter Array Element: ";
    cin>>arr[i];
  }

  //Sort array
  for(int i=1;i<arraySize;i++){
    int current = arr[i];
    int j=i-1;
    while(j>=0 && arr[j]>current){
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=current;
    
  }
  //Print sorted array
  cout<<"SortedArray=[";
  for(int i=0;i<arraySize;i++){
    if(i==arraySize-1){
      cout<<arr[i];
    }else{
      cout<<arr[i]<<",";
    }
  }
  cout<<"]";
}
