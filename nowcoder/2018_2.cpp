//
// Created by syslot on 2019/9/18.
//

#include <cstdio>
#include <algorithm>

int a[100001] = {0};

int main(){
    int n;

    while(scanf("%d", &n)!=EOF){
        for(int i =0;i<n;i++)
            scanf("%d", a+i);

        std::sort(a, a+n);

        u_int64_t sum=0;
        int i = 0;
        if(n%2!=0)
            sum+= a[i++];
        while(i < n){
            sum += a[i+1] - a[i];
            i+=2;
        }

        printf("%lu\n", sum);

    }
}