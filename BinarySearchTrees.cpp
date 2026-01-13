#include<iostream>
using namespace std;
struct Node{
    int key;
    Node* left;
    Node* right;
};
Node* createNode(int data){
    Node* temp = new Node();
    temp -> key = data;
    temp -> left = temp -> right = NULL;
    return temp;
}
Node* insert(Node* root, int data){
    if(root == NULL) return createNode(data);
    if(data < root->key) root -> left = insert(root->left,data);
    else if(data > root->key) root -> right = insert(root->right,data);
    else cout << "Duplicate value not allowed\n";
    return root;
}
void inorder(Node* root){
    if(root != NULL){
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}
void preorder(Node* root){
    if(root != NULL){
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(Node* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        cout << root->key << " ";
    }
}
Node* search(Node* root, int data){
    if(root == NULL || root->key == data) return root;
    if(data < root->key) return search(root->left,data);
    return search(root->right,data);
}
Node* findMin(Node* root){
    while (root && root->left != NULL) root = root->left;
    return root;
}
Node* deleteNode(Node* root, int data){
    if(root == NULL) return root;
    if(data < root->key) root->left = deleteNode(root->left, data);
    else if(data > root->key) root->right = deleteNode(root->right, data);
    else{
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        else if(root->left == NULL){
            Node* temp = root -> right;
            delete root;
            return temp;
        }else if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
void freeTree(Node* root){
    if(!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}
int main() {
    Node* root = nullptr;
    int choice, val;

    while (true) {
        cout << "1. Insert Node\n2. Inorder Traversal\n3. Preorder Traversal\n4. Postorder Traversal\n";
        cout << "5. Search Node\n6. Delete Node\n7. Find Minimum\n8. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> val;
            root = insert(root, val);
            cout << "Inserted successfully!\n";
            break;

        case 2:
            cout << "Inorder: ";
            inorder(root);
            cout << "\n";
            break;

        case 3:
            cout << "Preorder: ";
            preorder(root);
            cout << "\n";
            break;

        case 4:
            cout << "Postorder: ";
            postorder(root);
            cout << "\n";
            break;

        case 5:
            cout << "Enter value to search: ";
            cin >> val;
            if (search(root, val)) cout << "Found!\n";
            else cout << "Not Found!\n";
            break;

        case 6:
            cout << "Enter value to delete: ";
            cin >> val;
            if(search(root,val)){
                root = deleteNode(root,val);
                cout << "Deleted successfully.\n";
            }
            else{
                cout << "Value not found!\n";
            }
            break;

        case 7:
            if (root != nullptr) cout << "Minimum value = " << findMin(root)->key << endl;
            else cout << "Tree is empty!\n";
            break;

        case 8:
            freeTree(root);
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice!";
        }
    }
}