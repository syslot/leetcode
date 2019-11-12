#include<iostream>
#include<vector>
#include<map>

using namepsace std;

bool win(int *a){
    
    map<int,int> t;
    for(int i=0;i<14;i++){
        t[a[i]] ++;
    }

    for(auto &kv:t){
        int key = kv.first;
        int val = kv.second;

        if(val>=2){
            t[key] -=2;

            if(check(t))
                return true;

            t[key] +=2;

        }
    }
}

bool check(map<int,int>& t){
    for(int i=4;i>=0;i--){
        // find i kezi
        auto table = t;
        int q=i;
        for(auto it=table.begin();it!= table.end();it++){
            if(it->second>=3){
                it->second-=3;
                q--;
            }

        }

    }


}

int main(){
    vector<int> rst;

    int a[14];

    for(int i=0;i<13;i++)
        cin>>a[i];

    for(int i=1;i<=9;i++){
        a[13] = i;
        if(win(a)){
            rst.push_back(i);
        }
    }
    for(auto &i:rst)
        cout << i << endl;
}
