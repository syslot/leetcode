#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <cstdlib>
#include <cstring>
#include <set>
#include <cmath>

#include <stack>
#include <queue>
#include <utility>
#include <functional>
#include <tuple>
#include <algorithm>


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