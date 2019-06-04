//
// Created by syslot on 2019-04-11.
//

#include "common.h"

class Solution {
public:
    int rectCover(int number) {
        switch(number){
            case 0: return 0;
            case 1: return 1;
            case 2: return 2;
        }

        auto prepre = 1, pre=2;
        auto cur = 0;
        for(auto i = 3;i<=number;i++){
            cur =prepre + pre;
            prepre = pre;
            pre = cur;

        }
        return cur;
    }
};

class Solution11 {
public:
     int  NumberOf1(int n) {
         uint mask = 0xffffffff;
         bool flag = false;
         if (n <0)
             flag = true;

         uint q = abs(n);
         if(flag) {
             q ^= mask;
             q++;
         }
         n =0;
         while(q){
             if(q & 0x01 == 1)
                n++;
             q = q >> 1;
         }

        return n;
     }
};

class Solution13 {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> odd, even;

        for(auto v:array){
            if(v&0x01==1)
                odd.push_back(v);
            else
                even.push_back(v);
        }

        array.erase(array.begin(), array.end());
        array.insert(array.end(),odd.begin(), odd.end());
        array.insert(array.end(), even.begin(), even.end());
    }
};

class Solution14{
    public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        auto q = pListHead;

        int sum =0;
        while(q->next){
            sum++;
            q=q->next;
        }

        q=pListHead;
        sum -= (k);
        while(sum--)
            q=q->next;

        return q;
    }
};

class Solution16 {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        pHead1 = ReverseList(pHead1);
        pHead2 = ReverseList(pHead2);

        ListNode * cur = NULL, *tmp;

        while(pHead1 && pHead2){
            if(pHead1->val > pHead2->val){
                tmp = pHead1;
                pHead1 = pHead1->next;

            }else{
                tmp = pHead2;
                pHead2 = pHead2->next;
            }
            tmp -> next = cur;
            cur = tmp;
        }

        while(pHead1){
            tmp = pHead1;
            pHead1 = pHead1->next;
            tmp -> next = cur;
            cur = tmp;
        }
        while(pHead2){
            tmp = pHead2;
            pHead2 = pHead2->next;
            tmp -> next = cur;
            cur = tmp;
        }

        return cur;
    }

    ListNode* ReverseList(ListNode* pHead) {
        ListNode * tmp, *Q = NULL;
        while(pHead){
            tmp = pHead;
            pHead = pHead->next;
            tmp->next = Q;
            Q= tmp;
        }
        return Q;
    }
};

class Solution17 {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(!pRoot2)
            return false;

        return pre_travel(pRoot1, pRoot2);
    }

    bool pre_travel(TreeNode* pRoot1, TreeNode *pRoot2){
        bool flag = false;
        if(pRoot1->val == pRoot2->val){
            flag |= match_pre_travel(pRoot1, pRoot2);
        }
        if(flag)
            return flag;

        if(pRoot1->left){
            flag |= pre_travel(pRoot1->left, pRoot2);
        }
        if(flag)
            return flag;

        if(pRoot1->right){
            flag |= pre_travel(pRoot1->right, pRoot2);
        }

        return flag;
    }

    bool match_pre_travel(TreeNode * pRoot1, TreeNode * pRoot2){
        if(pRoot1->val != pRoot2-> val)
            return false;

        if( ((pRoot1->left == NULL) && pRoot2->left) || (pRoot2->left && (pRoot2->left == NULL)))
            return false;

        bool flag = false;
        if (pRoot1->left == NULL && pRoot2->left == NULL)
            flag |= true;
        else
            flag |= match_pre_travel(pRoot1->left, pRoot2->left);

        if(!flag)
            return flag;

        flag = false;
        if( ((pRoot1->right == NULL) && pRoot2->right) || (pRoot2->right && (pRoot2->right == NULL)))
            return false;

        if (pRoot1->right == NULL && pRoot2->right == NULL)
            flag |= true;
        else
            flag |= match_pre_travel(pRoot1->right, pRoot2->right);

        return flag;
    }

};

#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

const int inf=0x3f3f3f3f;
const int N=1<<21;

int dis[22][2],dp[N][22];
int n;

int main()
{
     while(~scanf("%d",&n)&&n)
     {
         for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
               scanf("%d",&dis[i][j]);
         for(int k=0;k<=n;k++)
            for(int i=0;i<=n;i++)
                for(int j=0;j<=n;j++)
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
         for(int s=0;s<1<<n;s++)
         {
             for(int i=1;i<=n;i++)
                if(s&(1<<(i-1)))
                {
                     if(s==(1<<(i-1)))
                         dp[s][i]=dis[0][i];
                     else
                     {
                         dp[s][i]=inf;
                         for(int j=1;j<=n;j++)
                            if(s&(1<<(j-1))&&i!=j)
                                dp[s][i]=min(dp[s^(1<<(i-1))][j]+dis[j][i],dp[s][i]);
                     }
                }
         }
         int ans=dp[(1<<n)-1][1]+dis[1][0];
         for(int i=2;i<=n;i++)
             ans=min(ans,dp[(1<<n)-1][i]+dis[i][0]);
         printf("%d\n",ans);
     }
     return 0;
}



//int main(){
//
//    Solution17 s;
//
//    TreeNode *pRoot = new TreeNode(5);
//    pRoot->left = new TreeNode(1);
//    pRoot->left->left = new TreeNode(3);
//    pRoot->right = new TreeNode(2);
//
//    TreeNode *pRoot1 = new TreeNode(5);
//    pRoot1->left = new TreeNode(1);
//    pRoot1->left->left = new TreeNode(3);
//    pRoot1->right = new TreeNode(3);
//
//    cout << s.HasSubtree(pRoot, pRoot1->left)<< endl;
//
//    return 0;
//
//}