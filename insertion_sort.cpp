/*
INSERTION SORT: pick each element and insert it at its correct index in the subarray behind it.
*/
#include <iostream>
using namespace std;

void insertionSort(int *a, int size) {
    int current_element, j;
    // traversing each element to find and insert it at its correct index
    for(int  i = 1; i < size; i++) {
        current_element = a[i];
        // traversing each index backwards to find correct index for current_element
        for(j = i - 1; j >= 0 && current_element < a[j]; j--) {
            // shift elements to right until an element smaller than current_element is located!
            a[j+1] = a[j];
        }
        // jth index has element smaller than current hence place current at j+1
        a[j+1] = current_element;
    }
}

int main() {
    int num;
    cin>>num;
    int *a = new int[num];
    for(int i = 0; i<num; i++) 
        cin>>a[i];
    insertionSort(a, num);
    for(int i = 0; i<num; i++) 
        cout<<a[i]<<endl;
    
    return 0;
}