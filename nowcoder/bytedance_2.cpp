#include <iostream>
#include <algorithm>
#define M 99997867

using namespace std;
int main(){

    int n,d;
    cin>>n>>d;
    int a[n];
    uint64_t count = 0;

    for(int i=0,j=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(int i=2,j=0;i<n;i++){
        while(a[i]-a[j]>d){
            j++;
        }
    
        count =  (count + ((i-j) * (i-j-1)/2)%M)%M;
    }

    cout << count << endl;

}
