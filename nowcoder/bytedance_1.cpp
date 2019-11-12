#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string str;
        cin >> str;

        string rst;

        deque<char> q;
        if(str.length() <3){
            cout << str << endl;
            continue;
        }else{
            q.push_back(str[0]);
            q.push_back(str[1]);
            for(int i=2;i<str.length();i++){
                q.push_back(str[i]);
                if(q[0] == q[1] && q[1] == q[2] )
                    q.pop_back();
                if(q.size() > 3)
                    if(q[1] == q[2] && q[2] == q[3] || q[0] == q[1] && q[2] == q[3])
                        q.pop_back();
                if(q.size() > 3){
                    char ch = q[0];
                    q.pop_front();
                    rst+=ch;
                }
            }
            while(!q.empty()){
                rst += q[0];
                q.pop_front();
            }
            cout << rst << endl;
        }
    }
    return 0;

}
