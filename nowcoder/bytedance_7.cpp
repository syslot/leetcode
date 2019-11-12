#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main (){

    int n;
    cin>>n;
    if(n==0){
        return 0;
    }
    int h[n];
    for(int i=0;i<n;i++)
        cin>>h[i];

    int e=0;
    for(int i=n-1;i>=0;i--){
        e=ceil((e+h[i])/2.0);
    }
    cout << e << endl;
    return 0;

}
