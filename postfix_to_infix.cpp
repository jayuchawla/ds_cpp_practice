#include <iostream>
#include <stack>
using namespace std;

bool isOperator(char op) {
    if(op == '+' || op == '-' || op == '*' || op == '/' || op == '^')
        return true;
    return false;
}

string postfix_to_infix(string postfix) {
    stack<string> s;
    for(int i = 0; i<postfix.length(); i++) {
        if(isOperator(postfix[i])) {
            string operand1 = s.top(); s.pop();
            string operand2 = s.top(); s.pop();
            s.push("(" + operand2 + postfix[i] + operand1 + ")");
        } else {
            s.push(string(1, postfix[i]).c_str());
        }
    }
    return s.top();
}

int main() {
    string postfix;
    cin>>postfix;
    cout<<postfix_to_infix(postfix);
    return 0;
}