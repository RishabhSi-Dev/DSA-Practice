#include<iostream>
using namespace std;
class Queue{
    int size, rear, front, qu[100];
    public:
    Queue(int s){
        size = s;
        front = 0;
        rear = -1;
    }
    bool isEmpty(){return front > rear;}
    bool isFull(){return rear == size-1;}
    void enqueue(int value){
        if(isFull()){
            cout << "Queue is full!" << endl;
            return;
        }
        rear++;
        qu[rear] = value;
        cout << value << " enqueued successfully!" << endl;
    }
    void dequeue(){
        if(isEmpty()){
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << qu[front] << " dequeued!" << endl;
        for(int i = front; i < rear; i++){
            qu[i] = qu[i+1];
        }
        rear--;
        if(rear < 0){
            front = 0;
            rear = -1;
        }
    }
    void display(){
        if(isEmpty()){
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue (front -> rear): ";
        for(int i = front; i <= rear; i++){
            cout << qu[i];
            if(i < rear) cout << " -> ";
        }
        cout << endl;
    }
    void search(int value){
        if(isEmpty()){
            cout << "Queue is empty!" << endl;
            return;
        }
        bool found = false;
        for(int i = front; i <= rear; i++){
            if(qu[i] == value){
                cout << value << " found at position " << (i-front+1) << endl;
                found = true;
                break;
            }
        }
        if(!found){
            cout << value << " not found!" << endl;t
        }
    }
};
int main(){
    int choice, value, size;
    cout << "Enter the size of queue: ";
    cin >> size;
    Queue myQueue(size);
    while(true){
        cout << "Choose\n1. Enqueue\n2. Dequeue\n3. Display\n4. Search\n5. Exit\nYour Choice: ";
        cin >> choice;
        switch(choice){
            case 1:
            cout << "Enter the value to enqueue: ";
            cin >> value;
            myQueue.enqueue(value);
            break;
            case 2:
            myQueue.dequeue();
            break;
            case 3:
            myQueue.display();
            break;
            case 4:
            cout << "Enter the value to search: ";
            cin >> value;
            myQueue.search(value);
            break;
            case 5:
            cout << "Exiting..." << endl;
            return 0;
            default:
            cout << "Invalid input. Try Again" << endl;
        }
    }
}