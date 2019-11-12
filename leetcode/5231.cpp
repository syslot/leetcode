#include "../common.h"

struct node{
    string val;
    bool edge;

    node * b;
    node * c;
    node(string v, bool e) {val=v; edge = e; b = NULL; c=NULL;}

};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        auto root=buildTree(folder);
        travel(root->c);

        return rst;
    }

    node * buildTree(vector<string>&folder){
        node * root = new node("", false);

        for(auto & str:folder){
            vector<string> tmp;
            int idx = 0;
            for(int i = idx+1; i<str.length();i++){
                if(str[i] == '/'){
                    string s(str.begin()+idx+1, str.begin()+i);
                    tmp.push_back(s);
                    idx = i;
                }
            }
            string s(str.begin()+idx+1, str.end());
            tmp.push_back(s);

            auto cur = root;
            for(int i=0;i<tmp.size();i++){
                if(cur->c == NULL){
                    cur->c = new node(tmp[i], false);
                    if(i == tmp.size()-1)
                        cur->c->edge = true;
                    cur = cur->c;
                }else{
                    if(cur->c->val==tmp[i]){
                        if(cur->c->edge)
                            // if it's edge, don't insert;
                            break;
                        if(i == tmp.size() -1) {
                            cur->c->edge = true;
                            break;
                        }
                        cur = cur->c;
                    }else{
                        // find brother;
                        cur = cur->c;
                        bool fd = false;
                        while(cur->b != NULL){
                            if(cur->b->val == tmp[i]) {
                                fd = true;
                                if(i == tmp.size()-1)
                                    cur->b->edge = true;
                                break;
                            }
                            else
                                cur = cur->b;
                        }
                        if(!fd){
                            cur->b = new node(tmp[i], false);
                            if(i==tmp.size()-1)
                                cur->b->edge = true;
                        }
                        cur = cur->b;
                    }

                }

            }
        }
        return root;
    }

    void travel(node *root){
        pre.push_back(root->val);
        if(root->edge){
            string ss;
            for(auto & s:pre){
                ss+= ('/' + s);
            }   
            rst.push_back(ss);
        }else{
            if(root->c){
                travel(root->c);
            }
        }
        pre.pop_back();
        if(root->b){
            travel(root->b);
        }
    }

    vector<string> rst;
    vector<string> pre;

};


int main(){

    vector<string> folder{
//            "/a/b/c", "/a/b/ca", "/a/b/d",
//"/a","/c/d","/c/f"
//"/a","/a/b/c","/a/b/d"
//"/a/b/c","/a/b/d","/a/b/ca"
//"/ah/al/am","/ah/al"
"/aa/ab/ac/ae","/aa/ab/af/ag","/ap/aq/ar/as","/ap/aq/ar","/ap/ax/ay/az","/ap","/ap/aq/ar/at","/aa/ab/af/ah","/aa/ai/aj/ak","/aa/ai/am/ao"
    };
    Solution s;

    auto rst = s.removeSubfolders(folder);
    for(auto &r:rst)
        cout << r << endl;

}
