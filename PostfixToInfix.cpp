#include<iostream>
#include<cstring>
using namespace std;
class Stack{
    string arr[100];
    int top;
    public: 
    Stack(){top = -1;}
    void push(string val){arr[++top] = val;}
    string pop(){return arr[top--];}
    bool isEmpty(){return top == -1;}
};
bool isOperator(char c){return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');}
string postfixToinfix(string postfix){
    Stack s;
    int length = postfix.size();
    for(int i = 0; i < length; i++){
        char c = postfix[i];
        if(isOperator(c)){
            string op2 = s.pop();
            string op1 = s.pop();
            string temp = "("+op1+c+op2+")";
            s.push(temp);
        }else if(c != ' '){
            s.push(string(1,c));
        }
    }
    return s.pop();
}
int main(){
    string postfix;
    cout << "Enter postfix expression: ";
    cin >> postfix;
    cout << "Infix Expression: " << postfixToinfix(postfix);
}