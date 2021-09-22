#include <iostream>
using namespace std;

class Stack {
    private:
        int top;
        int *arr;
        int size;

    public:
        Stack(int num);
        bool isEmpty();
        bool isFull();
        void push(int);
        int pop();
        int count();
        int peek(int);
        int change(int, int);
        void display();
};