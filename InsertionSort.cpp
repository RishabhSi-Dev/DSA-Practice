#include<iostream>
using namespace std;
int main(){
    int size;
    cout << "Enter the size of array: ";
    cin >> size;
    int arr[size];
    cout << "Enter the elements of array: ";
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }
    cout << "Array is: ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    for(int i = 1; i < size; i++){
        int j = i-1;
        int key = arr[i];
        while (j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    cout << "Sorted array: ";
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
}