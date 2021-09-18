/*
SELECTION SORT: pick each index and select appropriate element for it from the subarray in front of it.
*/
#include <iostream>
using namespace std;

void selectionSort(int *a, int size) {
    // traverse each index to find appropriate element for it
    for(int i = 0; i < size-1; i++) {
        // traverse each element in subarray i+1 to size and check if its appropriate for thr index "i"
        for(int j = i+1; j<size; j++) {
            if(a[j] < a[i]) {
                swap(a[i], a[j]);
            }
        }
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
    selectionSort(a, num);
    for(int i = 0; i<num; i++) 
        cout<<a[i]<<endl;
    return 0;
}