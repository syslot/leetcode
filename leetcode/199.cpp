#include "../common.h"

struct Node{
    TreeNode * n;
    int d;
    Node(TreeNode *v, int depth){n = v; d=depth;}
};


class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<Node *> q;
        map<int, int> rst;
        if(root == NULL){
            return vector<int>({});
        }
        auto n = new Node(root, 0);
        q.push(n);
        while(!q.empty()){
            auto v = q.front();
            q.pop();
            if(v->n->left){
                auto tmp = new Node(v->n->left, v->d+1);
                q.push(tmp);
            }
            if(v->n->right){
                auto tmp = new Node(v->n->right, v->d+1);
                q.push(tmp);
            }
            rst[v->d] = v->n->val;
        }
        
        vector<int> rst1;
        for(int i=0;i<INT_MAX;i++)
            if(rst.find(i)!=rst.end())
                rst1.push_back(rst[i]);
            else
                break;
        return rst1; 
    }

    
};

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right= new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution s;
    auto w = s.rightSideView(root);
    for(auto &v: w)
        cout << v << " ";
    cout << endl;


}
