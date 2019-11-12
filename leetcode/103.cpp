#include "../common.h"


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return vector<vector<int>> ({});
        queue<tuple<TreeNode *, int>> q;
        q.push(make_tuple(root, 0));
        map<int, vector<int>> r;

        while(!q.empty()){
            auto node = q.front();
            q.pop();
            auto v = get<0>(node);
            int d = get<1>(node);
            if(v->left)
                q.push(make_tuple(v->left, d+1));
            if(v->right)
                q.push(make_tuple(v->right, d+1));

            if(r.find(d) != r.end()){
                r[d].push_back(v->val);
            }else{
                r[d] = vector<int>({v->val});
            }
        }
        vector<vector<int>> rst;
        bool flag=true;
        for(int i=0;i<INT_MAX;i++)
            if(r.find(i) != r.end())
                if(flag){
                    rst.push_back(r[i]);
                    flag = !flag;
                }else{
                    rst.push_back(vector<int>(r[i].rbegin(), r[i].rend()));
                    flag=!flag;
                }
            else
                break;
        
        return rst;
    }
};

int main(){

    auto root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    auto w = s.zigzagLevelOrder(root);
    for(auto& v:w)
    {
        for(auto &i:v){
            cout << i << " ";
        }
        cout << endl;
    }


}
