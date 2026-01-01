#include<iostream>
using namespace std;
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void sort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
int main(){
    int size, value;
    cout << "Enter the size of array: ";
    cin >> size;
    int arr[size];
    cout << "Enter the elements of array: ";
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }
    sort(arr,size);
    cout << "Sorted array: ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Enter the value to search: ";
    cin >> value;
    int start = 0, end = size - 1;
    bool found = false;
    while (start <= end){
        int mid = (start+end)/2;
        if (arr[mid] == value){
            cout << value << " was found at position " << (mid+1) << endl;
            found = true;
            break;
        }
        else if (arr[mid] > value) end = mid-1;
        else start = mid+1;
    }
    if(!found){
        cout << value << " was not found!" << endl;
    }
}