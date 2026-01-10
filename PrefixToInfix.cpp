#include<iostream>
#include<string>
using namespace std;
class Stack{
    string arr[100];
    int top;
    public:
    Stack(){top = -1;}
    void push(string val){
        if (top < 99) arr[++top] = val;
    }
    string pop(){
        if(top == -1) return "";
        return arr[top--];
    }
    bool isEmpty(){return top == -1;}
};
bool isOperator(char c){return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');}
string prefixToinfix(string prefix){
    Stack s;
    int length = prefix.length();
    for(int i = length-1; i >= 0; i--){
        char c = prefix[i];
        if(isOperator(c)){
            string op1 = s.pop();
            string op2 = s.pop();
            string temp = "("+op1+c+op2+")";
            s.push(temp);
        }else if(c != ' '){
            s.push(string(1,c));
        }
    }
    return s.pop();
}
int main(){
    string prefix;
    cout << "Enter prefix expression: ";
    cin >> prefix;
    cout << "Infix expression: " << prefixToinfix(prefix);
    return 0;
}