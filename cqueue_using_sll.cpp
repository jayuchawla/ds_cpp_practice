/*
WHY LEFT SIDE IS KEPT AS FRONT AND RIGHT AS REAR ?
enqueue -> at rear append element
dequeue -> at front remove element
in SLL we dont have prev pointer hence if FRONT is at RIGHT then removing an element and going to prev will require complete traversal extra!
*/
#include <iostream>
using namespace std;

class Node {
    public:
        Node *next;
        int data;
        Node(){
            next = NULL;
        }
        Node(int d) {
            next = NULL;
            data = d;
        }
};

class QueueSLL {
    private:
        Node *front, *rear;
    public:
        QueueSLL() {
            front = NULL; rear = NULL;
        }

        bool isEmpty() {
            if(front == NULL && rear== NULL)
                return true;
            return false;
        }

        void enqueue(int d) {
            Node *temp = new Node(d);
            if(isEmpty())
                front = rear = temp;
            else {
                rear->next = temp;
                rear = temp;
            }
            rear->next = front;
        }

        int dequeue() {
            if(isEmpty())
                cout<<"Empty queue!"<<endl;

            Node *temp = front; int d = front->data;
            // reset condition is different here than normal queue
            if(front->next == front) {
                front = rear = NULL;
            }
            else {
                front = front->next;
                rear->next = front;
            }
            delete temp;
            return d;
        }

        int count() {
            int count = 0;
            Node* temp = front;
            while(temp!=NULL) {
                count++;
                temp = temp->next;
            }
            return count;
        }

        void print() {
            if(isEmpty()) {
                cout<<"Empty queue!"<<endl;
                return;
            }
            Node* temp = front;
            do {
                cout<<temp->data<<endl;
                temp = temp->next;
            } while(temp!=front);
        }
};
int main() {
    QueueSLL q;
    q.enqueue(5);
    q.enqueue(55);
    q.enqueue(57);
    q.dequeue();
    q.dequeue();
    // q.dequeue();
    q.print();
    return 0;
}