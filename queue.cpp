#include <iostream>
using namespace std;

class Queue {
    private:
        int front, rear;
        int *arr;
        int size;
    public:
        Queue(int num) {
            size = num;
            arr = new int[size];
            front = rear = -1;
        }

        bool isEmpty() {
            if(front == -1 && rear == -1)
                return true;
            return false;
        }

        bool isFull() {
            if(front == (rear + 1) % size)
                return true;
            return false;
        }

        void enqueue(int val) {
            if(!isFull()) {
                if(isEmpty())
                    front = rear = 0;
                else
                    rear = (rear + 1) % size;
                arr[rear] = val;
            }
            else
                cout<<"Overflow!"<<endl;
                
        }

        int dequeue() {
            if(!isEmpty()) {
                int x = arr[front];
                if(front == rear)
                    front = rear = -1;
                else
                    front = (front + 1) % size;
                return x;
            }
            else
                cout<<"Underflow!"<<endl;
        }

        void display() {
            cout<<"Queue: "<<endl;
            for(int i = 0; i < size; i++) {
                cout<<arr[i]<<endl;
            }
        }
};
int main() {
    Queue q1(5);
    cout<<q1.isFull()<<endl;
    cout<<q1.isEmpty()<<endl;
    q1.enqueue(3);
    q1.display();
    cout<<"----"<<endl;
    q1.enqueue(4);
    q1.display();
    cout<<"----"<<endl;
    q1.enqueue(3);
    q1.display();
    cout<<"----"<<endl;
    q1.enqueue(4);
    q1.display();
    cout<<"----"<<endl;
    q1.enqueue(3);
    q1.display();
    cout<<"----"<<endl;
    q1.dequeue();
    q1.display();
    q1.enqueue(56);
    q1.display();
    return 0;
}