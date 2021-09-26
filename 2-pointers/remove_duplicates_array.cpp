#include <iostream>
using namespace std;

/*in place remove duplicates and return number of unique elements*/
/* logic:   remember: slow pointer moves only when condition is in your favour 
            slow moves when elements at slow and fast index do not match */
int removeDuplicates(int *a, int size) {
    int slow=0;
    for(int fast=0; fast<size; fast++)
        if(a[slow] != a[fast])
            a[++slow] = a[fast];
    return slow+1;
}

int main() {
    int num;
    cin>>num;
    int *a = new int[num];
    for(int i = 0; i < num; i++)
        cin>>a[i];
    cout<<removeDuplicates(a, num)<<endl;
    return 0;
}