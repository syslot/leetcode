#include "../common.h"

//class Solution {
//public:
//    vector<vector<string> > solveNQueens(int n) {
//        this->arr = new int[n+1];
//        memset(arr, 0, sizeof(int) *(n+1));
//        this->n = n;
//        for(int i =0;i<n;i++){
//            line += '.';
//        }
//        search(0);
//        return this->rst;
//    }
//
//    void search(int cur){
//
//        if(cur == n){
//            // Search successed!
//            // record
//            vector<string> s;
//            for(int i =0;i<n;i++){
//                s.push_back(line);
//                s[i][arr[i]] = 'Q';
//            }
//            rst.push_back(s);
//        }
//
//        for(int i =0;i<n;i++){
//
//            if(cur == 0){
//                arr[cur] = i;
//                search(cur+1);
//            }else {
//                int j;
//                for (j = 0; j < cur; j++) {
//                    if (arr[j] == i || abs(arr[j] - i) == abs(cur - j))
//                        break;
//                }
//                if (j != cur)
//                    continue;
//                else {
//                    arr[cur] = i;
//                    search(cur + 1);
//                }
//            }
//        }
//    }
//
//    int *arr;
//    int n;
//    vector<vector<string> > rst;
//    string line;
//};


class Solution {
public:
    int totalNQueens(int n) {
            this->arr = new int[n + 1];
            memset(arr, 0, sizeof(int) * (n + 1));
            this->n = n;
            this->rst = 0;
            search(0);
            return this->rst;
        }


        void search(int cur) {

            if (cur == n) {
                this->rst++;

            }

            for (int i = 0; i < n; i++) {

                if (cur == 0) {
                    arr[cur] = i;
                    search(cur + 1);
                } else {
                    int j;
                    for (j = 0; j < cur; j++) {
                        if (arr[j] == i || abs(arr[j] - i) == abs(cur - j))
                            break;
                    }
                    if (j != cur)
                        continue;
                    else {
                        arr[cur] = i;
                        search(cur + 1);
                    }
                }
            }
        }

    int rst;
    int *arr;
    int n;

};

int main(){
    int n = 8;
    Solution s;
    cout << s.totalNQueens(n) << endl;
//    for(auto str_v:r){
//        for(auto v:str_v)
//            cout << v<<endl;
//        cout << endl;
//    }

}
