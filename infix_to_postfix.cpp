#include <iostream>
#include <string>
#include <string.h>
#include <stack>
using namespace std;

int precedenceOfOperator(char op) {
    if(op == '^')
        return 3;
    if(op == '*' || op == '/')
        return 2;
    if(op == '+' || op == '-')
        return 1;
}

string associativityOfOperator(char op) {
    if(op == '+' || op == '-' || op == '*' || op == '/') {
        return "lr";
    } else if(op == '^') {
        return "rl";
    }
}

bool isOperator(char op) {
    if(op == '+' || op == '-' || op == '*' || op == '/' || op == '^')
        return true;
    return false;
}

string infixToPostfix(string infix) {
    stack<char> s;
    // char *postfix = new char[infix.length()];
    string postfix;    
    int j = 0;

    for(int i=0; i<infix.length(); i++) {
        if(strcmp(string(1, infix[i]).c_str(), "(") == 0)
            s.push(infix[i]);
        else if(strcmp(string(1, infix[i]).c_str(), ")") == 0) {
            while(!s.empty() && (string(1, s.top()).c_str(), "(") != 0) {
                postfix += s.top();
                s.pop();
            }
            // discard ( on top of stack
            cout<<"discarding: "<<s.top()<<endl;
            s.pop();
            cout<<"discarded"<<endl;
        }
        else if(isOperator(infix[i])) {
            if(!s.empty()) {
                if(s.top() == '(')
                    s.push(infix[i]);
                else if(precedenceOfOperator(infix[i]) > precedenceOfOperator(s.top())) {
                    s.push(infix[i]);
                } else if(precedenceOfOperator(infix[i]) < precedenceOfOperator(s.top())) {
                    while(!s.empty() && precedenceOfOperator(infix[i]) <= precedenceOfOperator(s.top())) {
                        postfix += s.top();
                        s.pop();
                    }
                    s.push(infix[i]);
                } else {
                    // apply associativity rules
                    if(strcmp(associativityOfOperator(infix[i]).c_str(),"lr") == 0) {
                        while(!s.empty() && precedenceOfOperator(infix[i]) == precedenceOfOperator(s.top())) {
                            postfix += s.top();
                            s.pop();
                        }
                        s.push(infix[i]);
                    } else {
                        s.push(infix[i]);
                    }
                }
            } else {
                s.push(infix[i]);
                //cout<<"empty, pushed: "<<infix[i]<<endl;
            }
        } else {
            postfix += infix[i];
        }
    }
    while(!s.empty()) {
        if(isOperator(s.top())){
            postfix += s.top();
            s.pop();
        }
    }
    return postfix;
}

int main() {
    string infix;
    cin>>infix;
    cout<<infixToPostfix(infix);
    return 0;
}