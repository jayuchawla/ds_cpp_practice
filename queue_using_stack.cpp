#include <iostream>
#include <stack>
using namespace std;

class QueueStack {
    private:
        stack<int> s;
    public:
        QueueStack(){};
        
        void enqueue(int d) {
            s.push(d);
        }

        int dequeue() {
            if(s.empty()) {
                cout<<"Cannot dequeue from empty queue!"<<endl;
                return -1;
            }
            stack<int> temp;
            // moving all elements of s to temp
            while(!s.empty()) {
                temp.push(s.top()); s.pop();
                // cout<<"popped from s"<<endl;
            }
            int dequeuedElement = temp.top(); temp.pop();

            // moving back all elements of temp to s
            while(!temp.empty()) {
                s.push(temp.top()); temp.pop();
                // cout<<"pushed back to s"<<endl;
            }
            return dequeuedElement;
        }

        int count() {
            stack<int> temp; int count=0;
            // moving all elements of s to temp
            while(!s.empty()) {
                temp.push(s.top()); s.pop();
                count++;
            }

            // moving back all elements of temp to s
            while(!temp.empty()) {
                s.push(temp.top()); temp.pop();
            }
            return count;           
        }

        void print() {
            if(s.empty()) {
                cout<<"Empty queue!"<<endl;
                return;
            }
            stack<int> temp;
            // moving all elements of s to temp
            while(!s.empty()) {
                temp.push(s.top()); s.pop();
            }

            // moving back all elements of temp to s
            while(!temp.empty()) {
                cout<<temp.top()<<" ";
                s.push(temp.top()); temp.pop();
            }
        }
};
int main() {
    QueueStack q;
    q.enqueue(5);
    q.dequeue();
    q.print();
    q.enqueue(55);
    q.enqueue(57);
    q.print();

    return 0;
}