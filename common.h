#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <cstdlib>
#include <cstring>
#include <set>
#include <cmath>
#include <limits>
#include <cfloat>

#include <stack>
#include <queue>
#include <utility>
#include <functional>
#include <tuple>
#include <algorithm>
#include <stdexcept>
#include <numeric>
#include <iomanip>


using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

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

void printT(TreeNode* p, int indent=0)
{
    if(p != NULL) {
        if(p->left) printT(p->left, indent+4);
        if(p->right) printT(p->right, indent+4);
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        cout<< p->val<<endl;
    }
}

ListNode * GenList(vector<int> array){

    ListNode * head = new ListNode(0), *cur = head;
    for(auto x:array){
        cur->next = new ListNode(x);
        cur = cur->next;
    }

    cur = head->next;
    delete head;
    return cur;
}

TreeNode * BuildTree(string array){

    Codec c;
    return c.deserialize(array);
}
