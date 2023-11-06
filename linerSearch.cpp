#include <iostream>

using namespace std;

int main() {

  int arr[] = {1, 2, 3, 4, 5};
  int x;
  cout<<"Enter search element: ";
  cin >> x;
  int flag = -1;

  for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
    if (arr[i] == x) {
      flag = i;
      break;
    }
  }

  if (flag == -1) {
    cout << "Element not found" << endl;
  } else {
    cout << "Element found at index " << flag << endl;
  }

  return 0;
}