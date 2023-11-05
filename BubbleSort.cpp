// Bubble sort
#include <iostream>

using namespace std;

int main() {
  
  int arraySize;
  //Enter size of aray
  cout<<"Enter Array Size: ";
  cin>>arraySize;

  //Initialis array
  int arr[arraySize];

  //Enter element of array
  for(int i=0;i<arraySize;i++){
    cout<<"Enter Array Element: ";
    cin>>arr[i];
  }

  //Sort array
  for(int i=0;i<arraySize;i++){
    bool swapped = false;
    for(int j=0;j<arraySize ;j++){
      if(arr[j]>arr[j+1]){
        int temp = arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
        swapped=true;
      }
    }
    if(swapped==false){
      break;
    }
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
