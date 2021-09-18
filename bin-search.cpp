#include <iostream>
using namespace std;

int binarySearch(int *a, int size, int ele) {
    int start=0, end=size-1;
    while(start <= end) {
        int mid = (start + end) / 2;
        if(a[mid] == ele) {
            return mid;
        }
        else if(ele > a[mid])
            start = mid + 1;
        else
            end = mid - 1; 
    }
    return -1;
}

int binarySearchRecursive(int *a, int start, int end, int ele) {
    // terminating condition
    if(start > end)
        return -1;
    int mid = (start + end) / 2;
    if(a[mid] == ele)
        return mid;
    else if(ele > a[mid])
        binarySearchRecursive(a, mid+1, end, ele);
    else
        binarySearchRecursive(a, start, mid-1, ele);
}

int main() {
    int num;
    cin>>num;

    int *a = new int[num];
    for(int i = 0;i<num;i++)
        cin>>a[i];
    // cout<<binarySearch(a, num, 1)<<endl;   
    cout<<binarySearchRecursive(a, 0, num-1, 3)<<endl;   

    return 0;
}