#include <iostream>
using namespace std;

int linearSearch(int *a, int ele, int size) {
    for(int i = 0; i<size; i++)
        if(a[i] == ele)
            return i;
}

int main() {
    int num;
    cin>>num;
    int *a = new int[num];
    for(int i = 0; i<num; i++)
        cin>>a[i];
    cout<<linearSearch(a, 4, num)<<endl;
    return 0;
}