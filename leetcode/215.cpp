#include "../common.h"

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        build_heap(nums, k);
        int rst = this->heap[1];
        for(int i =k;i < nums.size();i++){
            if(heap[1] >= nums[i])
                continue;
            heap[1] = nums[i];
            MinHeap(1);
        }
        return heap[1];
    }

    void MinHeap(int i){
        int l = i * 2;
        int r = l + 1;
        int least;
        if( l < heap.size() && heap[l] < heap[i])
            least = l;
        else
            least = i;
        if(r < heap.size() && heap[r] < heap[least])
            least = r;
        if(least != i){
            swap(heap[least], heap[i]);
            MinHeap(least);
        }
        
    }

    void build_heap(vector<int>&nums, int k){
        heap.push_back(-1);
        for(int i =0;i<k;i++){
            heap.push_back(nums[i]);

            for(int i= heap.size()/2; i >0;i-- ){
                MinHeap(i);
            }
        }
    }
    vector<int> heap;
};

int main(){
    vector<int> nums {3,2,3,1,2,4,5,5,6};//{3,2,3,1,2,4,5,5,6,7,7,8,2,3,1,1,1,10,11,5,6,2,4,7,8,5,6};
    Solution s;
    int k = 4;
    cout << s.findKthLargest(nums, k)<<endl;
    return 0;
}
