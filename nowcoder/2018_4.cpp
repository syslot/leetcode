//
// Created by syslot on 2019/9/18.
//

#include <cstdio>
#include <cstdint>

const int m = 1000000007;

using namespace std;
typedef unsigned long long      u_int64_t;


u_int64_t c(int n, int m){
    if(m==0)
        return 1;
    u_int64_t  sum = 1;
    for(int i = 0 ; i < m ;i++){
        sum *= (n-i);
    }
    for(int i = 2; i <= m;i++){
        sum /=i;
    }
    return sum;
}

int main(){
    int k;

    int a, a_l, b, b_l;
    while(scanf("%d", &k) != EOF){
        scanf("%d %d %d %d",&a, &a_l, &b, &b_l);

        u_int64_t sum = 0;
        for(int i = 0;i < a_l ;i++){
            int res = k - a * i;
            if(res < 0)
                break;
            if(res % b == 0 && res / b <= b_l){
                int j = res / b;
                printf("%d %d %d %d\n", a, i, b , j);
                sum += (((c(a_l, i) % m) * (c(b_l,j) %m)) % m);
                sum %= m;
            }
        }
        printf("%lu\n", sum);
    }

}