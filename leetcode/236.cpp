//
// Created by syslot on 2019-03-05.
//

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <queue>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root== NULL)
            return NULL;
        vector<int> path, path1;

        bfs(root, p->val, path);
        bfs(root, q->val, path1);

        int i =0,j =0;
        for(;i< path.size() && j < path1.size(); i++, j++){
            if(path[i] == path1[j])
                continue;
            else
                break;

        }
        TreeNode * rst = root;
        for(int k =0;k < i;k++){
            if(path[k] == 0)
                rst= rst->left;
            else
                rst = rst->right;
        }
        return rst;
    };

    bool bfs(TreeNode *root, int v, vector<int> & path){
        if(!root){
            return false;
        }
        if(root->val == v)
            return true;

        bool flag = false;
        if(root->left){
            path.push_back(0);
            flag = bfs(root->left, v, path);
            if(!flag)
                path.pop_back();
        }
        if(flag == false && root->right){
            path.push_back(1);
            flag = bfs(root->right, v, path);
            if(!flag)
                path.pop_back();
        }
        return flag;
    } 

};


int main(){
    Solution s = Solution();

    auto root = new TreeNode(3);
    root->left =  new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right= new TreeNode(4);
//[37,-34,-48,null,-100,-101,48,null,null,null,null,-54,null,-71,-22,null,null,null,8]
//    auto root = new TreeNode(37);
//    root->left = new TreeNode(-34);
//    root->right = new TreeNode(-48);
//    root->left->right = new TreeNode(-100);
//    root->right->left = new TreeNode(-101);
//    root->right->right = new TreeNode(48);
//    root->right->right->left = new TreeNode(-54);
//    root->right->right->left->left = new TreeNode(-71);
//    root->right->right->left->right= new TreeNode(-22);
//    root->right->right->left->right->right= new TreeNode(8);


    auto t3 = s.lowestCommonAncestor(root, new TreeNode(5), new TreeNode(4));
    cout << t3->val << endl;

//    s.tree.clear();
//    t3 = s.lowestCommonAncestor(root, new TreeNode(5), new TreeNode(4));
//    cout << t3->val<<endl;

}
