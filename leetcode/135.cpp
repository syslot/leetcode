#include "../common.h"

class Solution {
public:
    int candy(vector<int>& ratings) {
        int c[ratings.size()];
        memset(c, 0, sizeof(c));
        int idx;
        while(idx = find(ratings, c), idx != -1){
            c[idx] = 1;
            for(int i=idx-1;i>=0;i--){
                if(c[i] == 0)
                    if(ratings[i] > ratings[i+1])
                        c[i] = c[i+1]+1;
                    else
                        break;
                else{
                    if(ratings[i]>ratings[i+1])
                        c[i] = max(c[i+1]+1, c[i]);
                    break;
                }

            }
            for(int i=idx+1;i<ratings.size();i++){
                if(c[i] == 0)
                    if(ratings[i-1] < ratings[i])
                        c[i] = c[i-1] + 1;
                    else
                        break;
                else{
                    if(ratings[i] > ratings[i-1])
                        c[i] = max(c[i-1]+1, c[i]);
                    break;

                }
            }
        }

        int sum =0;
        for(int i=0;i<ratings.size();i++){
            sum += c[i];
            cout << c[i] << " ";
        }
        cout << endl;
        return sum;

        



        
    }

    int find(vector<int> & r, int * c){
        int idx = -1;
        int min = INT_MAX;
        for(int i=0;i<r.size();i++)
            if(c[i] ==0 && min > r[i])
                idx=i, min = r[idx];

        return idx;
    }

};

int main(){
    vector<int> ratings{1,0,2};
    Solution s;
    cout << s.candy(ratings) << endl;

}
