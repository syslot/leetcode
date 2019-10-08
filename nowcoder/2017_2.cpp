//
// Created by syslot on 2019/9/18.
//

#include <iostream>
#include <cstdio>
#include <cstdint>
#include <cstring>
int main(){
    int a, b;
    uint32_t db[32] = {0};
    memset(db, 0, sizeof(uint32_t)*32);

    while(scanf("%d %d",&a, &b)!=EOF){
        if(a<=0 || a >= 1025 || b <=0 || b>=1025) {
            printf("-1\n");
            continue;
        }
        // set task
        int i = a/32;
        int j = 8-a%32;
        db[i] |= 1 << j;

        i = b/32;
        j = 8 - b%32;
        printf("%d\n", db[i] && 1<<j);


    }
    return 0;
}