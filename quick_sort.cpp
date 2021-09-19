/*
QUICK SORT: divide & conquer
EACH RECURSIVE CALL FOCUSSES ON PLACING PIVOT ELEMENT(last used here) AT ITS CORRECT INDEX
calling recursively on left subarray and right subarray of partition 
inplace
O(n*logn)
WORST CASE: array is already sorted in ASC or DES order already.
When already sorted in ASC order: partition index is pivot index itself for each recursive call and hence each index has to serve as partition index by the end of algorithm.
When already sorted in DES order: partition index changes alternatively between start and end of respective subarray until center of main array reached.
TC WC: O(n2)
TC Avg C: O(n*logn)
TC BC: O(n*logn)
*/

#include <iostream>
using namespace std;

void swap(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int findPartitionIndex(int *a, int start, int end) {
    // i is used as iterator and indexOfElementGreaterThanPivot holds index for the element found which is greater than pivot itself
    int indexOfElementGreaterThanPivot = start;
    for(int i = start; i < end; i++) {
        if(a[i] < a[end]) {
            swap(a[i], a[indexOfElementGreaterThanPivot]);
            indexOfElementGreaterThanPivot++;
        }
    }
    swap(a[end], a[indexOfElementGreaterThanPivot]);
    return indexOfElementGreaterThanPivot;
}

void quickSort(int *a, int start, int end) {
    if(start >= end)
        return;
    int partition = findP(a, start, end);
    quickSort(a, start, partition - 1);
    quickSort(a, partition + 1, end);
}

int main() {
    int num;
    cin>>num;
    int *a = new int[num];
    for(int i = 0; i<num; i++) 
        cin>>a[i];
    // cout<<findPartitionIndex(a, 0, num - 1);
    quickSort(a, 0, num - 1);
    for(int i = 0; i<num; i++) 
        cout<<a[i]<<endl;
    
    return 0;
}