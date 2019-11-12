//
// Created by syslot on 2019/9/16.
//

#include "../common.h"

//class Solution {
//public:
//    ListNode* sortList(ListNode* head) {
//        ListNode * tmp = head;
//        int count = 0;
//        while(tmp){
//            count++, tmp=tmp->next;
//        }
//
//        int arr[count];
//        tmp = head;
//        int i =0;
//        while(tmp){
//            arr[i++] = tmp->val;
//            tmp =tmp->next;
//        }
//        sort(arr, arr+count);
//        tmp = head;
//        for(int i =0;i<count ;i++, tmp = tmp->next){
//            tmp->val = arr[i];
//        }
//
//        return head;
//    }
//};


class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr)
            return head;
        auto rst = quickSort(head);
        return get<0>(rst);
    }

    tuple<ListNode*, ListNode*> quickSort(ListNode * head){
        if(head == nullptr)
            return make_tuple(head, nullptr);
        auto h = new ListNode(0);
        h->next = head->next;
        ListNode * key = head;
        key->next = nullptr;
        ListNode * pre = new ListNode(0), *pre_tail, *post = new ListNode(0), *post_tail;
        pre_tail = pre;
        post_tail= post;

        while(h->next){
            if(h->next->val < key->val) {
                pre_tail->next = h->next;
                h->next = h->next->next;
                pre_tail = pre_tail->next;
                pre_tail->next = nullptr;
            }else{
                post_tail->next = h ->next;
                h->next = h->next->next;
                post_tail = post_tail->next;
                post_tail->next=nullptr;
            }
        }

        auto sub_pre = quickSort(pre->next);
        auto sub_post= quickSort(post->next);
        pre = get<0>(sub_pre);
        pre_tail = get<1>(sub_pre);
        post = get<0>(sub_post);
        post_tail = get<1>(sub_post);
        ListNode* tail = nullptr;

        if(pre){
            h->next = pre;
            pre_tail->next = key;
            tail = key;
        }else{
            h->next = key;
            tail = key;
        }

        if(post){
            tail->next = post;
            tail = post_tail;
        }
        return make_tuple(h->next, tail);
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
