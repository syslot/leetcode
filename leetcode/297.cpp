#include "../common.h"

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode *>q;

        string str;
        int nn = 0;
        if(root ==nullptr){
            str = "[null]";
            return str;
        }else{
            str += to_string(root->val);
            q.push(root->left);
            q.push(root->right);
            if(root->left)
                nn++;
            if(root->right)
                nn++;
        }
        
        while(nn){
            auto cur = q.front();
            q.pop();
            if(cur == nullptr){
                str += ",null";
                continue;
            }else{
                nn--;
                str += ","  + to_string(cur->val);
            }
            q.push(cur->left);
            q.push(cur->right);
            if(cur->left)
                nn++;
            if(cur->right)
                nn++;
        }
        

        return "[" + str + "]";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<TreeNode *> p,c;
        if(data.length() <=2 || data == "[null]")
            return nullptr;

        vector<string> vs;

        // split line;
        int i =1;
        int b_p=1;
        while(i<data.length()-1){
            if(data[i] == ','){
                vs.push_back(data.substr(b_p, i-b_p));
                b_p = i+1;
            }
            i++;
        }
        vs.push_back(data.substr(b_p, i-b_p));
        
        auto root= new TreeNode(stoi(vs[0]));
        p.push_back(root);
        auto cur = vs.begin()+1;
        while(true){
            bool stop = false;
            for(int i=0;i<p.size();i++){
                auto p_n = p[i];
                if(cur == vs.end()){
                    stop = true;
                    break;
                }

                auto n = build(*cur);
                if(n != nullptr){
                    c.push_back(n);
                    p_n->left = n;
                }
                cur++;
                if(cur == vs.end()){
                    stop = true;
                    break;
                }
                n = build(*cur);
                if(n!= nullptr){
                    c.push_back(n);
                    p_n->right = n;
                }
                cur++;
            }

            p=c;
            c.clear();

            if(stop)
                break;
        }
        return root;
    }

    TreeNode * build(string str){
        if(str == "null")
            return nullptr;
        else{
            auto root= new TreeNode(stoi(str));
            return root;
        }
    }
};



void dfs(TreeNode *root){
    if(root==nullptr)
        return;
    cout << root->val <<endl;
    if(root->left)
        dfs(root->left);
    if(root->right)
        dfs(root->right);
}

int main(){

    TreeNode  *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    root->right->left->right = new TreeNode(6);
    root->right->right->right = new TreeNode(7);

    Codec s;


    auto str = s.serialize(nullptr);
    cout << str <<endl;

    str = "[]";
    auto root1 = s.deserialize(str);

    dfs(root1);

}
