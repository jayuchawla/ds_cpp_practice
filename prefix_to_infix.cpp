#include <iostream>
#include <stack>
using namespace std;

bool isOperator(char op) {
    if(op == '+' || op == '-' || op == '*' || op == '/' || op == '^')
        return true;
    return false;
}

string prefix_to_infix(string prefix) {
    stack<string> s;
    for(int i = prefix.length()-1; i>=0; i--) {
        if(isOperator(prefix[i])) {
            string operand1 = s.top(); s.pop();
            string operand2 = s.top(); s.pop();
            s.push("(" + operand1 + prefix[i] + operand2 + ")");
        } else {
            s.push(string(1, prefix[i]).c_str());
        }
    }
    return s.top();
}

int main() {
    string prefix;
    cin>>prefix;
    cout<<prefix_to_infix(prefix);
    return 0;
}