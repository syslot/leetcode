//
// Created by syslot on 2019-04-11.
//


#include "common.h"

class Solution {
public:
    int jumpFloor(int number) {
        int arr[number+1];
        arr[1] = 1;
        arr[2] = 2;

        for(int i = 3;i<=number;i++){
            arr[i] = arr[i-1] + arr[i-2];
        }
        return arr[number];

    }
};

int main(){
//    Solution s;
//    int n;
//    while(cin>>n)
//        cout << s.jumpFloor(n)<<endl;

    cout << pow(2,0)<<endl;

}