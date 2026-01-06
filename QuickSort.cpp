#include<iostream>
using namespace std;
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
int partition(int a[], int low, int high){
    int pivot = a[high];
    int i = low-1;
    for(int j = low; j < high; j++){
        if(a[j] < pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1], a[high]);
    return i+1;
}
void quickSort(int a[], int low, int high){
    if(low < high){
        int pindex = partition(a,low,high);
        quickSort(a,low,pindex-1);
        quickSort(a,pindex+1,high);
    }
}
int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}