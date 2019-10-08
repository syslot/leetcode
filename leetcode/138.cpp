#include "../common.h"

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node *> map_;
    
        Node * p = head;
        while(p){
            Node * c_ptr = new Node(p->val, NULL, NULL);
            map_[p] = c_ptr;
            p=p->next;
        }

        p = head;
        while(p){
            map_[p]->next = map_[p->next];
            if(p->random)
                map_[p]->random = map_[p->random];
            p = p->next;
        }

        return map_[head];
        
    }
};


int main(){

    Node * head = new Node;
    head->next = new Node(1, NULL, NULL);
    head->next->next = new Node(2, NULL, head->next);
    head->next->random = head->next->next;
    head->next->next->random = head->next->next;

    Solution s;
    s.copyRandomList(head->next);



}
