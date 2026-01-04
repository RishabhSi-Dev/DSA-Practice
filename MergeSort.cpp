#include<iostream>
using namespace std;
void print(int *array, int size){
    for(int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}
void merge(int *array, int l, int m, int r){
   int nl = m-l+1;
   int nr = r-m;
   int larr[nl], rarr[nr];
   for(int i=0; i < nl; i++) larr[i] = array[l+i];
   for(int j=0; j < nr; j++) rarr[j] = array[m+1+j];
   int i=0, j=0, k=l;
   while(i < nl && j < nr){
    if (larr[i] <= rarr[j]) array[k++] = larr[i++];
    else array[k++] = rarr[j++];
   }
   while(i < nl) array[k++] = larr[i++];
   while(j < nr) array[k++] = rarr[j++];
}
void mergeSort(int *array, int l, int r){
    if(l < r){
        int m = l+(r-l)/2;
        mergeSort(array,l,m);
        mergeSort(array,m+1,r);
        merge(array,l,m,r);
    }
}
int main(){
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of array: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << endl;
    mergeSort(arr,0,n-1);
    print(arr,n);
    return 0;
}