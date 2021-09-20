/*
RADIX / BUCKET SORT: No comparison reqd
Counting sort has a major disadvantage for the case when elements are heavily skewed(though num of elements is less but k is too high to increase complexity!!)
radix sort is nothing but d times counting sort (d denotes radix of maximum element)
For each digit counting sort is ran and elements sorted based on that digit (and hence range locked to 10)
TC: O(d*(n+k))
SC: O(n+k)
*/
#include <iostream>
using namespace std;

void radixSort(int *a, int size) {
    // finding max element
    int max=a[0];
    for(int i = 0; i<size; i++)
        if(a[i] > max)
            max = a[i];
    // finding radix of max element
    int temp = max, max_radix = 0;
    while(temp>0) {
        temp = temp / 10;
        max_radix++;
    }

    // cout<<"max: "<<max<<" max_radix: "<<max_radix<<endl;

    int current_radix = 1, range = 10;
    int *count_array = new int[range];
    int *op_array = new int[size];
    
    for(int r = 0; r < max_radix; r++) {        
        // cout<<"For radix: "<<current_radix<<endl;
        for(int i = 0; i<range; i++)
            count_array[i] = 0;
        // a[i] / current_radix) % 10 -> gives current digit 
        for(int i = 0; i<size; i++)
            count_array[(a[i] / current_radix) % 10]++;
        for(int i = 1; i<range; i++)
            count_array[i]+=count_array[i-1];
        for(int i = 0; i<range; i++)
            count_array[i]-=1;
        // why to go from backwards ? Do you remember counting sort places repeated element from higher index to lower i.e. if count_sort[1] = 2 then
        // if a = [811, 11, 34] -> 811 will be placed at index 2 and 11 will be placed at index 1 -> WE WANT THE ORDER TO BE PRESERVED and hence traversing from backwards
        for(int i = size-1; i>=0; i--) {
            op_array[count_array[(a[i] / current_radix) % 10]] = a[i];
            count_array[(a[i] / current_radix) % 10]--;
        }
        // copy radix sorted elements to input array        
        for(int i = 0; i<size; i++) {
            a[i] = op_array[i];
            // cout<<a[i]<<endl;
        }
        //cout<<"----------"<<endl;
        // radix levelled up
        current_radix *= 10;
    }
}

int main() {
    int num, range;
    cin>>num;
    int *a = new int[num];
    for(int i = 0; i<num; i++) 
        cin>>a[i];
    radixSort(a, num);
    for(int i = 0; i<num; i++)
        cout<<a[i]<<endl;
    return 0;
}