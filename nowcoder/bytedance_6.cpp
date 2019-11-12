#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin>>n;
    n = 1024-n;
    if(n==0){
        cout<< 0 << endl;
        return 0;
    }
    int f[n+1];
    for(int i=0;i<=n;i++){
        f[i] = i;
    }
    int cost[3] = {4,16,64};
    for(int i=0;i<3;i++){
        for(int v=cost[i];v<=n;v++)
            f[v] = min(f[v], f[v-cost[i]]+1);
    }
    cout << f[n] << endl;
    return 0;

}
