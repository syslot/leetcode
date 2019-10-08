#include <iostream>
using namespace std;
int main(){
    int less = 8;
    int day = 0;
    int t1,t2;
    for(int i=0;i<7;i++){
        cin >> t1>>t2;
        if(t1+t2 > less){
            less = t1+t2;
            day = i+1;
        }
    }
    cout << day << endl;
    return 0;

}
