/*
Traverse infix string from R to L
precedence(incoming-op) > prec(stack-top) -> push incoming-op
precedence(incoming-op) < prec(stack-top) -> keep popping (and append to postfix) until precedence(incoming-op) <= prec(stack-top) is True (WHY '=' -> read in comments below)

NOTE: the role of i->post in '(' is similar to role of ')' in i->pre 
hence push ')' and pop all operators when '(' found until top is ')'

ASSOCIATIVITY rules change here: (Reverse of infix to postfix)
in case of precedence clash -> apply ASSOCIATIVITY
Associativity L->R('+','-' or '*','/'): simply pushing incoming-op
Associativity R->L('^'): keep popping until precedence is not equal (then finally push incoming-op)
*/
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
        // if incoming character is ')', no checks simply push
        if(strcmp(string(1, infix[i]).c_str(), ")") == 0)
            s.push(infix[i]); 
        // if incoming character is '(', pop out all operators until ')' found as top
        else if(strcmp(string(1, infix[i]).c_str(), "(") == 0) {
            while(!s.empty() && strcmp(string(1, s.top()).c_str(), ")") != 0) {
                prefix += s.top();
                s.pop();
            }
            // ')' should not be appended in output, discard ')' on top of stack
            s.pop();
        }
        // check if incoming character is an operator
        else if(isOperator(infix[i])) {
            // check stack if empty, simply push the incoming operator in that case
            if(s.empty())
                s.push(infix[i]);
            else {
                // ')' is not actually an operator and hence no comparison when stack top is ')'
                if(s.top() == ')')
                    s.push(infix[i]);
                else if(precedenceOfOperator(infix[i]) > precedenceOfOperator(s.top()))
                    s.push(infix[i]);
                else if(precedenceOfOperator(infix[i]) < precedenceOfOperator(s.top())) {
                    // *************NOTE************* :: why <= ? '=' is used for the case when top has equal precedence to incoming op (R to L associativity logic)
                    while(!s.empty() && s.top()!=')' && precedenceOfOperator(infix[i]) <= precedenceOfOperator(s.top())) {
                        // if precedence clashes and if associativity of incoming operator is left to right simply break and push incoming operator
                        if(precedenceOfOperator(infix[i]) == precedenceOfOperator(s.top()) && strcmp(associativityOfOperator(infix[i]).c_str(), "lr") == 0) {
                            break;
                        }
                        prefix += s.top();
                        s.pop();
                    }
                    // finally push the incoming operator
                    s.push(infix[i]);
                }
                else {
                    // apply associativity rules
                    // for l to r associativity -> keep pushing operators
                    // for r to l associativity -> keep popping out top until top has an operator whose precedence does not clash with incoming operator 
                    if(strcmp(associativityOfOperator(infix[i]).c_str(), "lr") == 0) {
                        s.push(infix[i]);
                    } else {
                        while(!s.empty() && precedenceOfOperator(infix[i]) == precedenceOfOperator(s.top())) {
                            prefix += s.top();
                            s.pop();
                        }
                        // once clash resolved, push incoming operator
                        s.push(infix[i]);
                    }
                }
            }
        }
        // if not (, ), or operator simply append to result
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

    // actually required to print reverse since we choose to traverse from R to L initially
    string reversed;
    for(int i = prefix.length(); i>=0; i--)
        reversed+=prefix[i];
    return reversed;
}

int main() {
    string infix;
    cin>>infix;
    cout<<infixToPrefix(infix)<<endl;
    return 0;
}