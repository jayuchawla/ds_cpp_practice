#include <iostream>
#include <stack>
using namespace std;

bool isOperator(char op) {
    if(op == '+' || op == '-' || op == '*' || op == '/' || op == '^')
        return true;
    return false;
}

string postfix_to_prefix(string postfix) {
    stack<string> operandStack, prefixStack;

    for(int i = 0; i < postfix.length(); i++) {
        if(!isOperator(postfix[i])) {
            operandStack.push(string(1, postfix[i]).c_str());
        } else {
            string op1 = operandStack.top(); operandStack.pop();
            string op2 = operandStack.top(); operandStack.pop();
            operandStack.push(postfix[i] + op2 + op1);
        }
    }
    string prefix = operandStack.top();
    operandStack.pop();
    return prefix;
}


int main() {
    string postfix;
    cin>>postfix;
    cout<<postfix_to_prefix(postfix);
    return 0;
}