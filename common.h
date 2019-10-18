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

TreeNode * BuildTree(vector<int> array){
    if(array.size() == 0)
        return NULL;

    auto root = new TreeNode(array[0]);
    auto rst=root;
    queue<TreeNode *> q;
    q.push(root);

    for(int i=1;i<array.size();i++){
        root = q.front();
        q.pop();
        if(array[i] != INT_MAX){
            root->left = new TreeNode(array[i]);
            q.push(root->left);
        }
        if(i+1 < array.size()){
            if(array[i+1] != INT_MAX){
                root->right = new TreeNode(array[++i]);
                q.push(root->right);
            }
        }


    }


    return rst;
}
