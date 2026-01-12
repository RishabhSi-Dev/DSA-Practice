#include<iostream>
using namespace std;
struct Node{
    public:
    int data;
    Node *next;
};
Node* head = NULL;
Node* createNode(int val){
    Node* newNode = new Node();
    newNode -> data = val;
    newNode -> next = NULL;
    return newNode;
}
void InsertAtHead(int val){
    Node* newNode = createNode(val);
    newNode -> next = head;
    head = newNode;
    cout << "Inserted " << val << " at beginning." << endl;
}
void InsertAtTail(int val){
    Node* newNode = createNode(val);
    if(head == NULL){
        head = newNode;
        cout << "Inserted " << val << " as first node." << endl;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    temp -> next = newNode;
    cout << "Inserted " << val << " in the end." << endl;
}
void InsertAtPos(int val, int position){
    if(position < 1){
        cout << "Invalid position!" << endl;
        return;
    }
    Node* newNode = createNode(val);
    if(position == 1){
        newNode -> next = head;
        head = newNode;
        cout << "Inserted " << val << " at position 1." << endl;
        return;
    }
    Node* temp = head;
    for(int i =1; temp != NULL && i < position-1; i++) temp = temp->next;
    if(temp == NULL){
        cout << "Invalid position!" << endl;
        delete newNode;
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    cout << "Inserted " << val << " at position " << position << endl;
}
void deleteAtHead(){
    if(head == NULL){
        cout << "List is empty!" << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    cout << "Deleted " << temp->data << " from beginning."  << endl;
    delete temp;
}
void deleteAtTail(){
    if(head == NULL){
        cout << "List is empty!" << endl;
        return;
    }
    if(head->next == NULL){
        cout << "Deleted " << head->data << " from end." << endl;
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while(temp->next->next != NULL) temp = temp->next;
    cout << "Deleted " << temp->next->data << " from end." << endl;
    delete temp->next;
    temp->next = NULL;
}
void display(){
    if (head == NULL){
        cout << "List in empty!\n";
        return;
    }
    Node* temp = head;
    cout << "Linked list: ";
    while (temp != NULL){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}
int main(){
    int choice, val, pos;
    do {
        cout << "1. Insert at Head\n2. Insert at Tail\n3. Insert at Position\n";
        cout << "4. Delete at Head\n5. Delete at Tail\n6. Display List\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch(choice){
            case 1:
            cout << "Enter value: ";
            cin >> val;
            InsertAtHead(val);
            break;
            case 2:
            cout << "Enter value: ";
            cin >> val;
            InsertAtTail(val);
            break;
            case 3:
            cout << "Enter value and position: ";
            cin >> val >> pos;
            InsertAtPos(val, pos);
            break;
            case 4:
            deleteAtHead();
            break;
            case 5:
            deleteAtTail();
            break;
            case 6:
            display();
            break;
            case 7:
            cout << "Exiting...\n" << endl;
            return 0;
            default:
            cout << "Invalid choice\n";
        }
    }while(choice != 0);
    return 0;
}