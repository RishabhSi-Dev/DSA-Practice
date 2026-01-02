#include<iostream>
using namespace std;
int main(){
    int size, value;
    cout << "Enter the size of array: ";
    cin >> size;
    int arr[size];
    cout << "Enter the elements of array: ";
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }
    cout << "Enter the value to search: ";
    cin >> value;
    bool found = false;
    for(int i = 0; i < size; i++){
        if(arr[i] == value){
            cout << value << " was found at position: " << (i+1) << endl;
            found = true;
        }
    }
    if(!found){
        cout << value << " was not found!" << endl;
    }
    cout << "The array is: ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
}