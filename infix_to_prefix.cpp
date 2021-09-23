#include <iostream>
#include <stack>
#include <string>
#include <string.h>
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

string infixToPrefix(string infix) {
    string prefix;
    stack<char> s;
    // traversing R to L
    for(int i = infix.length() - 1; i>=0; i--) {
        if(strcmp(string(1, infix[i]).c_str(), ")") == 0)
            s.push(infix[i]); 
        else if(strcmp(string(1, infix[i]).c_str(), "(") == 0) {
            while(!s.empty() && strcmp(string(1, s.top()).c_str(), ")") != 0) {
                prefix += s.top();
                s.pop();
            }
            // discard ')' 
            s.pop();
        }
        else if(isOperator(infix[i])) {
            if(s.empty())
                s.push(infix[i]);
            else {
                if(s.top() == ')')
                    s.push(infix[i]);
                else if(precedenceOfOperator(infix[i]) > precedenceOfOperator(s.top()))
                    s.push(infix[i]);
                else if(precedenceOfOperator(infix[i]) < precedenceOfOperator(s.top())) {
                    while(!s.empty() && s.top()!=')' && precedenceOfOperator(infix[i]) <= precedenceOfOperator(s.top())) {
                        // if precedence clashes and if associativity of incoming operator is left to right simply break and push incoming operator
                        if(precedenceOfOperator(infix[i]) == precedenceOfOperator(s.top()) && strcmp(associativityOfOperator(infix[i]).c_str(), "lr") == 0) {
                            break;
                        }
                        prefix += s.top();
                        s.pop();
                    }
                    s.push(infix[i]);
                }
                else {
                    if(strcmp(associativityOfOperator(infix[i]).c_str(), "lr") == 0) {
                        s.push(infix[i]);
                    } else {
                        while(!s.empty() && precedenceOfOperator(infix[i]) == precedenceOfOperator(s.top())) {
                            prefix += s.top();
                            s.pop();
                        }
                        s.push(infix[i]);
                    }
                }
            }
        }
        else
            prefix+=infix[i];
    }
    // pop out all remaining operators, why isOperator check ? to avoid adding ')' to prefix expression
    while(!s.empty() && isOperator(s.top())) {
        prefix += s.top();
        s.pop();
    }
    if(!s.empty())
        return "Invalid Infix string";
    return prefix;
}

int main() {
    string infix;
    cin>>infix;
    cout<<infixToPrefix(infix)<<endl;
    return 0;
}