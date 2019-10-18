#include "../common.h"


class Solution {
public:
    int superEggDrop(int K, int N) {
        
        if(N == 0)
            return 0;
        if(K==1)
            return N;

        int key = N*1000+K;
        if(map_.find(key) != map_.end())
            return map_[key];

        int low = 1, high = N;
        while(low<high){
            int middle = (low+high)/2;
            int lowVal = superEggDrop(K-1, middle -1);
            int highVal = superEggDrop(K, N-middle);
            if(lowVal < highVal)
                low = middle+1;
            else
                high = middle;
        }

        int min_ = 1 +
            min(max(superEggDrop(K-1, low-1), superEggDrop(K, N-low)),
                    max(superEggDrop(K-1, high-1), superEggDrop(K, N-high)));
        
        map_[key] = min_;


    }

    map<int,int> map_;
};

int main(){

    Solution s;
    cout << s.superEggDrop(4,2000) << endl;

}
