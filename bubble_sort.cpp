/*
BUBBLE SORT: each iteration ensures bubbling out largest element at last
OPTIMIZED BUBBLE SORT: if no swapping happened for last round -> no need to go for next iteration
*/
#include <iostream>
using namespace std;

void bubbleSort(int *a, int size) {
    // each i ensures bubbling out largest element at last index of considered boundary
    for(int i = 0; i<size; i++) {
        // reducing boundary to size-i-1
        for(int j = 0; j<size-i-1; j++) {
            if(a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
            }
        }
    }
}

void bubbleSortOptimized(int *a, int size) {
    // flag to confirm if iterating needs to continued
    int continueIterating = false;
    // each i ensures bubbling out largest element at last index of considered boundary
    for(int i = 0; i<size; i++) {
        // reset flag to default
        continueIterating = false;
        // reducing boundary to size-i-1
        for(int j = 0; j<size-i-1; j++) {
            if(a[j] > a[j+1]) {
                // atleast 1 swap happened -> should continue with next iteration
                continueIterating=true;
                swap(a[j], a[j+1]);
            }
        }
        if(continueIterating == false)
            break;
    }
}

void swap(int *nump1, int *nump2) {
    int temp = *nump1;
    *nump1 = *nump2;
    *nump2 = temp;
}

int main() {
    int num;
    cin>>num;
    int *a = new int[num];
    for(int i = 0; i<num; i++) 
        cin>>a[i];
    bubbleSortOptimized(a, num);
    for(int i = 0; i<num; i++) 
        cout<<a[i]<<endl;
    
    return 0;
}