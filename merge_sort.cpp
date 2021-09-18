/*
MERGE SORT
divide & conquer
NOT inplace
EACH RECURSIVE CALL FOCUSSES ON MERGING 2 SORTED ARRAYS AT THAT INSTANT.
talking of best, worst case is irrelvant in case of merge sort 
TC WC: O(n*logn)
TC Avg C: O(n*logn)
TC BC: O(n*logn)
*/

#include <iostream>
using namespace std;

void divideMerge(int *a, int start, int end) {
    if(start >= end)
        return;
    int mid = (start + end) / 2;
    divideMerge(a, start, mid);
    divideMerge(a, mid+1, end);

    // copying SORTED left subarray and SORTED right subarray into new arrays
    int *L = new int[mid - start + 1]; int *R = new int[end - mid];
    for(int i = 0; i < mid - start + 1; i++)
        L[i] = a[start + i];
    for(int i = 0; i < end - mid; i++)
        R[i] = a[mid + 1 + i];

    // merging SORTED L and R into original array
    int iteratorL = 0, iteratorR = 0, iteratorOriginalArray = start;
    while(iteratorL < (mid - start + 1) && iteratorR < (end - mid)) {
        if(L[iteratorL] < R[iteratorR]) {
            a[iteratorOriginalArray] = L[iteratorL];
            iteratorL++;
        } else {
            a[iteratorOriginalArray] = R[iteratorR];
            iteratorR++;
        }
        iteratorOriginalArray++;
    }
    while(iteratorL < (mid - start + 1)) {
        a[iteratorOriginalArray] = L[iteratorL];
        iteratorL++; iteratorOriginalArray++;
    }
    while(iteratorR < (end - mid)) {
        a[iteratorOriginalArray] = R[iteratorR];
        iteratorR++; iteratorOriginalArray++;
    }
}

int main() {
    int num;
    cin>>num;
    int *a = new int[num];
    for(int i = 0; i<num; i++) 
        cin>>a[i];
    divideMerge(a, 0, num-1);
    for(int i = 0; i<num; i++) 
        cout<<a[i]<<endl;
    
    return 0;
}