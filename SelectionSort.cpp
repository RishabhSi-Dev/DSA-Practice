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
    for(int i = 0; i < size-1; i++){
        int minindex = i;
        for(int j = i+1; j < size; j++){
            if(arr[j] < arr[minindex]){
                minindex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minindex];
        arr[minindex] = temp;
    }
    cout << "Sorted array: ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
}