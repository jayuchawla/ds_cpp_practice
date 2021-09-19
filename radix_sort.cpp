#include <iostream>
using namespace std;

void radixSort(int *a, int size) {
    int max=a[0];
    for(int i = 0; i<size; i++)
        if(a[i] > max)
            max = a[i];
    
    int temp = max, max_radix = 0;
    while(temp>0) {
        temp = temp / 10;
        max_radix++;
    }

    cout<<"max: "<<max<<" max_radix: "<<max_radix<<endl;

    int current_radix = 1, range = 10;
    int *count_array = new int[range];
    int *op_array = new int[size];
    
    for(int r = 0; r < max_radix - 1; r++) {        
        cout<<"For radix: "<<current_radix<<endl;
        for(int i = 0; i<range; i++)
            count_array[i] = 0;
        for(int i = 0; i<size; i++)
            count_array[(a[i] / current_radix) % 10]++;
        for(int i = 1; i<size; i++)
            count_array[i]+=count_array[i-1];
        for(int i = 0; i<size; i++)
            count_array[i]-=1;
        for(int i = size-1; i>=0; i--) {
            op_array[count_array[(a[i] / current_radix) % 10]] = a[i];
            count_array[(a[i] / current_radix) % 10]--;
        }
        
        for(int i = 0; i<size; i++) {
            a[i] = op_array[i];
            cout<<a[i]<<endl;
        }
        cout<<"----------"<<endl;
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