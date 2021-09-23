/*
Traverse infix string from L to R
precedence(incoming-op) > prec(stack-top) -> push incoming-op
precedence(incoming-op) < prec(stack-top) -> keep popping (and append to postfix) until precedence(incoming-op) <= prec(stack-top) is True (WHY '=' -> read in comments below)
in case of precedence clash -> apply ASSOCIATIVITY
Associativity L->R('+','-' or '*','/'): keep popping until precedence is not equal (then finally push incoming-op)
Associativity R->L('^'): keep pushing until precedence is not equal (then finally push incoming-op)
*/
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
    string postfix;    
    int j = 0;

    for(int i=0; i<infix.length(); i++) {
        // if incoming character is '(', no checks simply push
        if(strcmp(string(1, infix[i]).c_str(), "(") == 0)
            s.push(infix[i]);
        // if incoming character is ')', pop out all operators until '(' found as top
        else if(strcmp(string(1, infix[i]).c_str(), ")") == 0) {
            while(!s.empty() && strcmp(string(1, s.top()).c_str(), "(") != 0) {
                postfix += s.top();
                s.pop();
            }
            // '(' should not be appended in output, discard '(' on top of stack
            s.pop();
        }
        // check if incoming operator is an operator
        else if(isOperator(infix[i])) {
            // check if stack not empty, else simply push the incoming operator
            if(!s.empty()) {
                // '(' is not actually an operator and hence no comparison when stack top is '('
                if(s.top() == '(')
                    s.push(infix[i]);
                else if(precedenceOfOperator(infix[i]) > precedenceOfOperator(s.top())) {
                    s.push(infix[i]);
                }
                // if prec(incoming op) <  prec(stack top) -> keep popping until top has operator with low precedence
                else if(precedenceOfOperator(infix[i]) < precedenceOfOperator(s.top())) {
                    // *************NOTE************* :: why <= ? '=' is used for the case when top has equal precedence to incoming op (L to R associativity logic) -> Keep in mind R to L associativity is not taken ... WHY ? since only '^' has R to L and '^' has most precedence -> Logically this case wont exist for '^' 
                    while(!s.empty() && precedenceOfOperator(infix[i]) <= precedenceOfOperator(s.top())) {
                        // if precedence clashes and if associativity of incoming operator is right to left (only applicable when come operator with precedence = '^' is introduced)
                        if(precedenceOfOperator(infix[i]) == precedenceOfOperator(s.top()) && strcmp(associativityOfOperator(infix[i]).c_str(),"rl") == 0) {
                            s.push(infix[i]);
                        } else {
                            postfix += s.top();
                            s.pop();
                        }
                    }
                    // finally push the incoming operator
                    s.push(infix[i]);
                } else {
                    // apply associativity rules
                    // for l to r associativity -> keep popping out top until top has an operator whose precedence does not clash with incoming operator 
                    // for r to l associativity -> keep pushing operators
                    if(strcmp(associativityOfOperator(infix[i]).c_str(),"lr") == 0) {
                        while(!s.empty() && precedenceOfOperator(infix[i]) == precedenceOfOperator(s.top())) {
                            postfix += s.top();
                            s.pop();
                        }
                        // once clash resolved, push incoming operator
                        s.push(infix[i]);
                    } else
                        s.push(infix[i]);
                    }
                }
                // if stack empty, simply push incoming operator to stack
                else
                    s.push(infix[i]);
            }
            // if not (, ), or operator simply append to result
            else
                postfix += infix[i];
    }
    // pop out all remaining operators
    while(!s.empty() && isOperator(s.top())) {
            postfix += s.top();
            s.pop();
    }
    return postfix;
}

int main() {
    string infix;
    cin>>infix;
    cout<<infixToPostfix(infix);
    return 0;
}