//
// Created by syslot on 2019/9/18.
//

#include <cstdio>
#include <string>

using namespace std;

void ppp(int geo){
   string s;

        int l = -90;
        int r = 90;

        int mid = (l+r)/2;
        while(1){
//            printf("%d %d %d\n",l, r, mid);
            if(geo >= mid){
                s += '1';
                l = mid;
            }else{
                s+= '0';
                r = mid;
            }
            if(r -l < 5#include <cstdio>
#include <string>

using namespace std;

int main(){
    int geo=0;

    while(scanf("%d", &geo) != EOF){

        string s;

        int l = -90;
        int r = 90;

        int mid = (l+r)/2;
        while(1){
            if(geo >= mid){
                s += '1';
                l = mid;
            }else{
                s+= '0';
                r = mid;
            }
            if(r -l < 6)
                break;
            mid = (l+r)/2;
        }
        printf("%s\n", s.c_str());
    }

})
                break;
            mid = (l+r)/2;
        }
        printf("%d %s\n",geo, s.c_str());
}

int main(){
    int geo=0;

//    while(scanf("%d", &geo) != EOF){


//    }
    for(int i = -90; i<=90;i++)
        ppp(i);
}