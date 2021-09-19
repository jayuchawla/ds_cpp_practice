/*
COUNT SORT: no comparison done (unlike selection, insertion, bubble, quick, merge)
count frequency of each element
maintain a range array of size = 0 to max or num of unique elements
auxiliary array space of range + size required
*/

#include <iostream>
using namespace std;

void countSort(int *a, int size, int range) {
    int *count_array = new int[range];
    int *op_array = new int[size];
    // initilialize range array
    for(int i = 0; i<range; i++)
        count_array[i] = 0;
    // store frequency of each element
    for(int i = 0; i < size; i++)
        count_array[a[i]]++;
    // evaluate cumalative count
    for(int i = 1; i<range; i++)
        count_array[i] += count_array[i-1]; 
    // subtract 1 from each, this value will indicate last actual index of each element in original array
    for(int i = 0; i<range; i++)
        count_array[i] -= 1;
    // traverse each element in original array and find its actual index from count array and decrement value in count array
    for(int i = 0; i < size; i++){
        op_array[count_array[a[i]]] = a[i];
        count_array[a[i]]--;
    }
    // copy op_array to original array
    for(int i = 0; i<size; i++)
        a[i] = op_array[i];
} 

int main() {
    int num, range;
    cin>>num;
    cin>>range;
    int *a = new int[num];
    for(int i = 0; i<num; i++) 
        cin>>a[i];
    countSort(a, num, range);
    for(int i = 0; i<num; i++)
        cout<<a[i]<<endl;
    return 0;
}