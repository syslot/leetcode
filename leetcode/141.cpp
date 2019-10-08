#include "../common.h"


class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode * p1 = head;
        ListNode * p2 = head;
        while(p1){
            if(p1->next == NULL || p1->next->next == NULL){
                return false;
            }
            if(p1->next == p2 || p1->next->next == p2)
                return true;
            p1 = p1->next->next;
            p2 = p2->next;
            if(p1 == p2)
                return true;
        }
        
    }
};

int main(){

    //auto l = GenList(vector<int>{3,2,0,-4});

    //l->next->next->next = l->next;
    auto l = GenList(vector<int>{1});

    Solution s;
    cout << s.hasCycle(l)<< endl;


}
