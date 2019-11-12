#include <iostream>
#include <cmath>
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
    bool isSymmetric(TreeNode* root) {
        queue<tuple<int,int,TreeNode*>> q;

        q.push(make_tuple(0, 1, root));
        vector<tuple<int,int>> tmp;
        while(!q.empty()){
            int level = get<0>(q.front());
            tmp.clear();
            while(get<0>(q.front()) == level){

                auto node = q.front();
                q.pop();
                int idx = get<1>(node);
                auto v = get<2>(node);
                if(v->left){
                    q.push(make_tuple(level+1, idx*2, v->left));
                }
                if(v->right){
                    q.push(make_tuple(level+1, idx*2+1, v->right));
                }
                tmp.push_back(make_tuple(idx,v->val));
            }

            if(level==0 &&tmp.size() == 1)
                continue;
            if(tmp.size()%2 !=0)
                return false;

            int sum = pow(2, level) + pow(2, level+1)-1;
            for(auto it1 = tmp.begin(), it2 = tmp.end()-1;it1!=tmp.end();it1++, it2--){
                int idx1 = get<0>(*it1);
                int idx2 = get<0>(*it2);
                int v1 = get<1>(*it1);
                int v2 = get<1>(*it2);

                if(idx1 + idx2 != sum || v1 != v2)
                    return false;
            }

        }

        return true;
    }
};

int main(){

    auto root = new TreeNode(1);
    root->left= new TreeNode(0);
    //root->right= new TreeNode(2);
    //root->left->left = new TreeNode(3);
    //root->left->right = new TreeNode(4);
    //root->right->left = new TreeNode(4);
    //root->right->right = new TreeNode(3);

    Solution s;
    cout << s.isSymmetric(root) << endl;
    

}
