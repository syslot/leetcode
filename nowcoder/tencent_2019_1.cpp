//
// Created by syslot on 2019/9/20.
//

#include "../common.h"

#include <iostream>
#include <algorithm>

int main(){
    int a,b;
    while(cin>>a>>b, !cin.eof()){
        int arr[300001];
        int brr[300001];
        int tmp;
        int c=a;
        for(int i= 0 ;i<a;i++)
            cin>>arr[i];
        for(int j =0;j<b;j++)
            cin>>brr[j];

        sort(arr, arr+a);
        sort(brr, brr+b);

        int rst[4];
        rst[0] = arr[0] * brr[0];
        rst[1] = arr[0] * brr[b-1];
        rst[2] = arr[a-2] * brr[0];
        rst[3] = arr[a-2] * brr[b-1];

        int r = rst[0];
        for(int i=1;i<4;i++)
            if(r < rst[i])
                r=rst[i];
        cout << r;
    }

}