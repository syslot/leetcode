/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <string>
#include <iostream>
#include <vector>

using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

int len(ListNode * lNode){
    int n = 0;
    for(auto ptr = lNode; ptr!= NULL; ptr = ptr->next){
        n++;
    }
    return n;
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int l1_len = len(l1);
        int l2_len = len(l2);
        if(l2_len > l1_len)
            swap(l1, l2);
        auto L = new ListNode(0);
        auto cur = L;
        bool carry = false;
        auto l2_ptr = l2;
        for(auto l1_ptr = l1; l1_ptr != NULL; l1_ptr = l1_ptr->next){

            if (l2_ptr != NULL) {
                cur->next = new ListNode(l2_ptr->val + l1_ptr->val);
                l2_ptr = l2_ptr->next;
            }
            else
                cur->next = new ListNode(l1_ptr->val);

            cur = cur->next;
            if (carry)
                cur->val++, carry = false;

            if(cur->val >= 10){
                cur->val %= 10;
                carry = true;
            }
        }
        if(carry)
            cur ->next = new ListNode(1);
        cur = L;
        L= cur->next;
        delete cur;
        return L;
    }
};

int main(){
    auto s = Solution();

//    vector<int> a = vector<int>{1,2,3,4,5,6};
//    vector<int> b = vector<int>{1,2,3,4,5};

    vector<int> a = vector<int> {1,2,3,3,4,5,5,6};
    vector<int> b = vector<int> {0};

    auto l1 = new ListNode(0);
    auto cur = l1;
    for (auto p:a){
        cur->next = new ListNode(p);
        cur = cur->next;
    }
    cur = l1;
    l1 = l1->next;
    delete cur;

    auto l2 = new ListNode(0);
    cur = l2;
    for(auto p:b){
        cur->next = new ListNode(p);
        cur = cur->next;
    }
    cur = l2;
    l2 = l2->next;
    delete cur;

    auto L = s.addTwoNumbers(l1, l2);

    for(auto p = L; p!= NULL; p = p->next){
        cout << p->val <<" ";
    }
    cout << endl;


}