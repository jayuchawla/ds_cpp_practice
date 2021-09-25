#include <iostream>
#include <stack>
using namespace std;

bool isOperator(char op) {
    if(op == '+' || op == '-' || op == '*' || op == '/' || op == '^')
        return true;
    return false;
}

string postfix_to_prefix(string postfix) {
    stack<string> s;

    for(int i = 0; i < postfix.length(); i++) {
        if(!isOperator(postfix[i])) {
            s.push(string(1, postfix[i]).c_str());
        } else {
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();
            s.push(postfix[i] + op2 + op1);
        }
    }
    string prefix = s.top();
    s.pop();
    return prefix;
}


int main() {
    string postfix;
    cin>>postfix;
    cout<<postfix_to_prefix(postfix);
    return 0;
}