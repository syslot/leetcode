//
// Created by syslot on 2019/9/16.
//

#include "../common.h"

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode * tmp = head;
        int count = 0;
        while(tmp){
            count++, tmp=tmp->next;
        }

        int arr[count];
        tmp = head;
        int i =0;
        while(tmp){
            arr[i++] = tmp->val;
            tmp =tmp->next;
        }
        sort(arr, arr+count);
        tmp = head;
        for(int i =0;i<count ;i++, tmp = tmp->next){
            tmp->val = arr[i];
        }

        return head;
    }
};

int main(){

    Solution s;
    auto head = GenList(vector<int>{-1,5,3,4,0});
    auto rst = s.sortList(head);
    while(rst){
        cout << rst->val << endl;
        rst=rst->next;
    }
    cout << endl;

}