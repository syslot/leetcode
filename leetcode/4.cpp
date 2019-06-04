
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <iterator>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        auto l1 = nums1.size(), l2 = nums2.size();

        int index1 = 0;
        int index2 = 0;
        bool odd = true;

        if((l1+l2 )% 2  == 0){
            odd = false;
            index2 = (l1+l2)/2;
            index1 = index2 - 1;
        }
        else{
            index1 = (l1+l2)/2;
        }
        auto it_1 = nums1.begin(), it_2 = nums2.begin();
        for(auto i = 0; i < index1; i++){
            if(it_1 == nums1.end()){
                it_2 ++;
            }else if(it_2 == nums2.end()){
                it_1 ++;
            }else if(*it_1 < *it_2){
                it_1 ++;
            }else{
                it_2 ++;
            }
        }
        auto sum = 0;
        if(it_1 == nums1.end()) {
            sum += (*it_2++);
        }else if(it_2 == nums2.end()){
            sum += (*it_1++);
        }else if(*it_1 < *it_2){
            sum += *(it_1++);
        }else{
            sum += *(it_2++);
        }

        if(odd){
            return sum;
        }else{
            if(it_1 == nums1.end()){
                sum += (*it_2++);
            }else if(it_2 == nums2.end()){
                sum += (*it_1++);
            }else if(*it_1 < *it_2){
                sum += *(it_1++);
            }else{
                sum += *(it_2++);
            }
            return sum *0.5;
        }
    }
};

int main(){
    auto s = Solution();

    vector<int> a = {3,4,5};
    vector<int> b = {1};
    cout<< s.findMedianSortedArrays(a,b) << endl;

}