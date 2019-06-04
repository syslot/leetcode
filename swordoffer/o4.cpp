#include "common.h"
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        
        TreeNode * root = new TreeNode(0);
        s.push(make_tuple(0, pre.size()-1,0, pre.size()-1, root));
        
        int pre_l = 0, pre_r= pre.size(), vin_l =0, vin_r = pre.size();
        TreeNode * curRoot = NULL;
        while(!s.empty()){
            auto tmp = s.top();
            s.pop();

            pre_l = get<0>(tmp);
            pre_r = get<1>(tmp);
            vin_l = get<2>(tmp);
            vin_r = get<3>(tmp);
            curRoot = get<4>(tmp);


            // Get Root
            curRoot->val = pre[pre_l];
            if(pre_l==pre_r)
                continue;

            int idx = vin_l;
            for(int i = vin_l; i<=vin_r ; i++)
                if(pre[pre_l] == vin[i]){
                    idx = i;
                    break;
                }

            if(idx != vin_l){
                curRoot->left = new TreeNode(0);
                auto len = idx - vin_l;
                s.push(make_tuple(pre_l+1, pre_l + len, vin_l, idx-1, curRoot->left));
            }

            if(idx != vin_r){
                curRoot->right = new TreeNode(0);
                auto len = vin_r - idx;
                s.push(make_tuple(pre_r - len+1,pre_r , idx +1, vin_r, curRoot->right));
            }
        
        }
        return root;
    }
    stack<tuple<int,int,int,int,TreeNode *>> s;
    
};


void pre_print(TreeNode * T){
    if(!T)
        return;

    cout << T->val;

    if(T->left)
        pre_print(T->left);

    if(T->right)
        pre_print(T->right);
}

void in_print(TreeNode *T){
    if(!T)
        return;

    if(T->left)
        in_print(T->left);

    cout << T->val;

    if(T->right)
        in_print(T->right);

}


int main(){

    vector<int> pre{1,2,4,7,3,5,6,8};

    vector<int> vin{4,7,2,1,5,3,8,6};

    Solution s;
    auto t = s.reConstructBinaryTree(pre,vin);

    pre_print(t);
    cout << endl;
    in_print(t);
}
