#include <iostream>
using namespace std;

class Node {
    public:
        Node *next;
        int data;
        Node () {
            next = NULL;
        }
        Node(int d) {
            next = NULL;
            data = d;
        }
};

class StackSLL {
    private:
        Node *head;
    public:
        StackSLL() {
            head = NULL;
        }

        void push(int d) {
            if(head == NULL) {
                head = new Node(d);
            } else {
                Node *n1 = new Node(d);
                n1->next = head;
                head = n1;
            }
        }

        int pop() {
            if(head == NULL) {
                cout<<"Stack empty!"<<endl;
                return -1;
            } else {
                Node *temp = head; int d = head->data; 
                head = head->next;
                delete temp;
                return d;
            }
        }

        int count() {
            int count = 0;
            if(head!=NULL) {
                Node *temp = head;
                while(temp!=NULL) {
                    count++;
                    temp=temp->next;
                }
            }
            return count;
        }

        int top() {
            if(head == NULL) {
                return -1;
            }
            return head->data;
        }

        void print() {
            Node *temp = head;
            while(temp!=NULL) {
                cout<<temp->data<<endl;
                temp=temp->next;
            }
        }
};

int main() {
    StackSLL s;
    s.push(5);
    s.push(10);
    s.push(14);
    s.push(30);
    cout<<"popping: "<<s.pop()<<endl;
    cout<<"popping: "<<s.pop()<<endl;
    s.print();
    cout<<"top: "<<s.top()<<endl;
    return 0;
}
