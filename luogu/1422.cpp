#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int a;
    cin >>a;
    float sum=0;
    if(a <=150)
        printf("%.1f\n", 0.4463*a);
    else{
        sum += 150 * 0.4463;
        if(a<= 400){
            printf("%.1f\n",sum + (a-150) * 0.4663);
        }else{
            sum += 250*0.4663;
            printf("%.1f\n",sum+(a-400)* 0.5663);
        }
    }
    return 0;

}
