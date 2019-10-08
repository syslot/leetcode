#include "../common.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNodeX{
    int val;
    TreeNodeX *parent;
    int level;
    TreeNodeX(int v, int l): val(v), level(l){}
};

//class Solution {
//public:
//    int maxPathSum(TreeNode* root) {
//
//        if(!root->left && !root->right)
//            return root->val;
//
//        reverseTravel(root, 0, NULL);
//        int max = INT_MIN;
//
//        for(int i =0;i<nodes.size();i++){
//            for(int j=i;j<nodes.size();j++){
//                int dist = getPathLen(nodes[i], nodes[j]);
//                if(dist > max)
//                    max=dist;
//            }
//        }
//        return max;
//    }
//
//    void reverseTravel(TreeNode *root, int level, TreeNodeX *parent){
//        if(root){
//            auto node = new TreeNodeX(root->val, level);
//            node->parent = parent;
//            nodes.push_back(node);
//            if(root->left){
//                reverseTravel(root->left, level+1, node);
//            }
//            if(root->right){
//                reverseTravel(root->right, level+1, node);
//            }
//
//        }
//
//
//    }
//
//    int getPathLen(TreeNodeX * n1, TreeNodeX *n2){
//
//        if(path.find(make_tuple(n1, n2)) != path.end())
//            return path[make_tuple(n1,n2)];
//        if(path.find(make_tuple(n2,n1))!=path.end())
//            return path[make_tuple(n2,n1)];
//
//        if(n1==n2){
//            path[make_tuple(n1,n1)] = n1->val;
//            return n1->val;
//        }
//
//        int tmp;
//        if(n1->level >= n2->level){
//            tmp = n1->val + getPathLen(n1->parent, n2);
//
//        }else{
//            tmp = n2->val + getPathLen(n1, n2->parent);
//        }
//        path[make_tuple(n1,n2)] = tmp;
//        path[make_tuple(n2,n1)] = tmp;
//        return tmp;
//    }
//
//    vector<TreeNodeX *>nodes;
//    map<tuple<TreeNodeX*, TreeNodeX *>, int> path;
//
//
//};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        maxG(root);
        return maxP;
    }
    int maxG(TreeNode * root){
        if(!root)
            return 0;
        int left = max(maxG(root->left), 0);
        int right = max(maxG(root->right), 0);

        if(left+right +root->val > maxP)
            maxP = left+ right+ root->val;

        return root->val + max(left,right);

    }
    int maxP = INT_MIN;
};
int main(){
    
    auto root = new TreeNode(-10);
    root->left = new TreeNode(9);
//    root->left->left = new TreeNode(15);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
//    root->left->left = new TreeNode(-1);

    Solution s;
    cout << s.maxPathSum(root) <<endl;

}
