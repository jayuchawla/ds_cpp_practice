#include <iostream>
#include <stack>
using namespace std;

bool isOperator(char op) {
    if(op == '+' || op == '-' || op == '*' || op == '/' || op == '^')
        return true;
    return false;
}

string prefix_to_postfix(string prefix) {
    stack<string> s;

    for(int i = prefix.length(); i >= 0; i--) {
        if(!isOperator(prefix[i])) {
            s.push(string(1, prefix[i]).c_str());
        } else {
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();
            s.push(op1 + op2 + prefix[i]);
        }
    }
    string postfix = s.top();
    s.pop();
    return postfix;
}


int main() {
    string prefix;
    cin>>prefix;
    cout<<prefix_to_postfix(prefix);
    return 0;
}