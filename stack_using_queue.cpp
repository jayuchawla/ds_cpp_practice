/*
Either of push or pop operation has to be costly, here we make push operation costly
the idea is to use a main queue and a temporary queue for push
push -> dequeue each element from main queue(q) while pushing it to temp queue
        enqueue new element
        enqueue back all elements in 'temp' to 'q'
pop -> simply dequeue
*/
#include <iostream>
#include <queue>
using namespace std;

class StackQueue {
    private:
        queue<int> q;
    public:
        StackQueue() {}

        // push is costly
        void push(int d) {
            queue<int> temp;
            // moving all elements of main queue 'q' to 'temp'
            while(!q.empty()) {
                temp.push(q.front()); q.pop();
            }
            // push new element into empty main stack
            q.push(d);
            // push back all elements of 'temp' to 'q' (NO need to worry about order since queue maintains FIFO) 
            while(!temp.empty()) {
                q.push(temp.front()); temp.pop();
            }
        }

        int pop() {
            if(q.empty()) {
                cout<<"cannot pop from empty stack!"<<endl;
                return -1;
            }
            int t = q.front();
            q.pop();
            return t;
        }
        
        int top() {
            if(q.empty()) {
                cout<<"No top, empty stack!"<<endl;
                return -1;
            }
            return q.front();
        }

        int count() {

        }

        void print() {

        }
};
int main() {
    StackQueue s;
    cout<<s.top()<<endl;
    s.push(2);
    cout<<s.top()<<endl;
    s.push(3);
    s.pop();
    s.pop();
    cout<<s.top()<<endl;
    s.push(1);
    cout<<s.top()<<endl;
    return 0;
}