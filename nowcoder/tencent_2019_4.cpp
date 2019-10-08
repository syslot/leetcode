//
// Created by syslot on 2019/9/20.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int m, n;
    scanf("%d %d", &n, &m);
    int pos[1000001];
    int neg[1000001];
    int zero_c =0;
    int pos_c  = 0;
    int neg_c  = 0;
    int tmp;
    for(int i =0;i<n;i++) {
        scanf("%d", &tmp);
        if(tmp == 0)
            zero_c ++;
        else if(tmp > 0)
            pos[pos_c++] = tmp;
        else
            neg[neg_c++] = tmp;
    }


    sort(pos,pos+pos_c);
    sort(neg, neg+ neg_c, greater<int>());

    long long sum = 0;
    int neg_b = 0, pos_b = 0;
    for(int i = m ; i > 0;i--){
        if(neg_c != 0 && pos_c != 0) {
            sum += neg[neg_c - 1] * pos[pos_c - 1];
            neg_c --;
            pos_c --;
        }
        else if(neg_c != 0 && pos_c == 0){
            if (zero_c != 0){
                neg_c -= 1;
                zero_c -= 1;
            }else {
                sum += neg[neg_b] * neg[2 * i - 1 + neg_b];
                neg_b ++;
                neg_c -= 2;
            }
        }
        else if(pos_c != 0 && neg_c == 0){
            if(zero_c != 0){
                pos_c --;
                zero_c --;
            }else{
                sum+= pos[pos_b] * pos[2*i-1 + pos_b];
                pos_b ++;
                pos_c -=2;
            }

        }else
            break;
    }
    printf("%lld\n", sum);

}