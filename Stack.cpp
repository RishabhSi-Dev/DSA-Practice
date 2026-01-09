#include<iostream>
using namespace std;
class Stack{
    int top, size, st[100];
    public:
    Stack(int s){
        size = s;
        top = -1;
    }
    bool isFull(){return top == size - 1;}
    bool isEmpty(){return top == -1;}
    void push(int value){
        if(isFull()){
            cout << "Stack is full!" << endl;
            return;
        }
        top++;
        st[top] = value;
        cout << value << " pushed successfully!" << endl;
    }
    void pop(){
        if(isEmpty()){
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << st[top] << " popped successfully!" << endl;
        top--;
    }
    void traversal(){
        if(isEmpty()){
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack (top -> bottom): ";
        for(int i = top; i >= 0; i--){
            cout << st[i];
            cout << " | ";
        }
        cout << "\n";
    }
    void search(int value){
        if(isEmpty()){
            cout << "Queue is empty!" << endl;
        }
        bool found = false;
        for(int i = top; i >= 0; i--){
            if(st[i] == value){
                cout << value << " found at position " << (top-i+1) << endl;
                found = true;
                break;
            }
        }
        if(!found){
            cout << value << " not found!" << endl;
        }
    }
};
int main(){
    int choice, value, size;
    cout << "Enter size of stack: ";
    cin >> size;
    Stack myStack(size);
    while(true){
        cout << "Choose\n1. Push\n2. Pop\n3. Display\n4. Search\n5. Exit\nYour Choice: ";
        cin >> choice;
        switch(choice){
            case 1:
            cout << "Enter a value to push: ";
            cin >> value;
            myStack.push(value);
            break;
            case 2:
            myStack.pop();
            break;
            case 3:
            myStack.traversal();
            break;
            case 4:
            cout << "Enter a value to search: ";
            cin >> value;
            myStack.search(value);
            break;
            case 5:
            cout << "Exiting..." << endl;
            return 0;
            default:
            cout << "Invalid choice. Try Again\n";
        }
    }
}