#include "../common.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1,s2;
        if(l1==nullptr)
            return l2;
        if(l2 == nullptr)
            return l1;
        while(l1){
            s1.push(l1->val);
            l1=l1->next;
        }
        while(l2){
            s2.push(l2->val);
            l2=l2->next;
        }
        
        stack<int> s3;
        
        bool flag = false;
        while(!s1.empty() && !s2.empty()){
            int tmp = s1.top() + s2.top();
            if(flag){
                tmp ++;
                flag = 0;
            }
            if(tmp >= 10){
                tmp -= 10;
                flag = 1;
            }
            s3.push(tmp);
            s1.pop();
            s2.pop();
        }
        int tmp;
        if(s1.empty()){
            while(!s2.empty()){
                tmp = s2.top();
                s2.pop();
                if(flag){
                    tmp++;
                    flag=0;
                }
                if(tmp >= 10){
                    tmp-=10;
                    flag =1;
                }
                s3.push(tmp);
            }

        }else{
            while(!s1.empty()){
                tmp = s1.top();
                s1.pop();
                if(flag){
                    tmp++;
                    flag =0;
                }
                if(tmp>=10){
                    tmp-=10;
                    flag = 1;
                }
                s3.push(tmp);
            }
            
        }
        if(flag)
            s3.push(1);
        ListNode * head = new ListNode(0);
        auto cur = head;
        while(!s3.empty()){
            cur->next = new ListNode(s3.top());
            s3.pop();
            cur = cur->next;
        }
        
        return head->next;
    }
};


int main(){
    Solution s;
    auto h = s.addTwoNumbers(GenList(vector<int>{9,0,6}), GenList(vector<int>{0}) );
    while(h){
        cout << h->val << " ";
        h=h->next;
    }
    cout << endl;

}
