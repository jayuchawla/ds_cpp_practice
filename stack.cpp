#include <iostream>
using namespace std;

class Stack {
    private:
        int top;
        int *arr;
        int size;

    public:
        Stack(int num) {
            arr = new int[num];
            top = -1;
            size = num;
        }

        bool isEmpty() {
            if(top == -1)
                return true;
            return false;
        }

        bool isFull() {
            if(top == size-1)
                return true;
            return false;
        }

        void push(int x) {
            if(!isFull()) {
                top+=1;
                arr[top] = x;
            }
            else
                cout<<"Cannot push, already full!"<<endl;
        }

        int pop() {
            if(!isEmpty()) {
                int x = arr[top];
                top -= 1;
                return x;
            }
            else
                cout<<"Cannot pop, blank stack!"<<endl;
        }

        int count() {
            return (top+1);
        }

        int peek(int pos) {
            if(isEmpty()) {
                cout<<"Cannot peek, blank stack!"<<endl;
            }
            else if(pos > top+1) {
                cout<<"Cannot peek, pos greater than max elements allowed!"<<endl;
            }
            else {
                return arr[pos-1];
            }
        }

        int change(int pos, int val) {
            if(isEmpty()) {
                cout<<"Cannot peek, blank stack!"<<endl;
            }
            else if(pos > top+1) {
                cout<<"Cannot peek, pos greater than max elements allowed!"<<endl;
            }
            else {
                arr[pos-1] = val;
                cout<<"Value changed at location "<<pos<<endl;
            }
        }

        void display() {
            cout<<"Stack content: "<<endl;
            for(int i = size -1; i>=0; i--) {
                cout<<arr[i]<<endl;
            }
        }
};

int main() {

    Stack s1(5);
    s1.push(3);
    cout<<s1.peek(1)<<endl;
    s1.display();
    return 0;
}