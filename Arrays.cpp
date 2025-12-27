#include<iostream>
using namespace std;
class Array{
    private:
    int arr[100], maxsize, size;
    public:
    Array(int max){
        maxsize = max;
        size = 0;
    }
    bool isEmpty(){return size == 0;}
    bool isFull(){return size == maxsize;}
    void insert(int pos, int value){
        if(isFull()){
            cout << "Array is full!" << endl;
            return;
        }
        pos = pos - 1;
        if(pos < 0 || pos > size){
            cout << "Invalid position!" << endl;
            return;
        }
        for(int i = size-1; i >= pos; i--){
            arr[i+1] = arr[i];
        }
        arr[pos] = value;
        size++;
        cout << "Inserted " << value << " successfully." << endl;
    }
    void delet(int pos){
        if(isEmpty()){
            cout << "No element to delete!" << endl;
            return;
        }
        pos = pos - 1;
        if(pos < 0 || pos >= size){
            cout << "Invalid position!" << endl;
            return;
        }
        cout << "Deleting: " << arr[pos] << endl;
        for(int i = pos; i < size-1; i++){
            arr[i] = arr[i+1];
        }
        size--;
    }
    void search(){
        int value;
        cout << "Enter element to search: ";
        cin >> value;
        for(int i = 0; i < size; i++){
            if(arr[i] == value){
                cout << value << " was found at position " << (i+1) << endl;
                return;
            }
        }
        cout << value << " is not in the array!" << endl;
    }
    void display(){
        if(isEmpty()){
            cout << "Array is empty!" << endl;
            return;
        }
        for(int i = 0; i < size; i++){
            cout << arr[i] << " ";
        }
        cout << "\nTotal elements: " << size << endl;
    }
};
int main(){
    int maxsize, choice, value, posi;
    cout << "Enter the maximum size of the array: ";
    cin >> maxsize;
    if(maxsize > 100 || maxsize <= 0){
        cout << "Invalid size. Reverting to 100!" << endl;
        maxsize = 100;
    }
    Array myArray(maxsize);
    while (true){
        cout << "Choose\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\nYour Choice: ";
        cin >> choice;
        switch(choice){
            case 1:
            cout << "Enter which position to insert in: ";
            cin >> posi;
            cout << "Enter the value to insert: ";
            cin >> value;
            myArray.insert(posi,value);
            break;
            case 2:
            cout << "Enter the position to delete: ";
            cin >> posi;
            myArray.delet(posi);
            break;
            case 3:
            myArray.search();
            break;
            case 4:
            myArray.display();
            break;
            case 5:
            cout << "Exiting....\n";
            return 0;
            break;
            default:
            cout << "Invalid choice. Try Again!";
        }
    }
    return 0;
}