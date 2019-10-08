#include "../common.h"


struct BiLinkNode{
    int key;
    int value;
    BiLinkNode * pre;
    BiLinkNode * nxt;
    BiLinkNode(int key, int value){this->key = key; this->value = value;}
};

class LRUCache {
public:
    LRUCache(int capacity) {
        h = new BiLinkNode(0,0);
        h->nxt = h;
        h->pre = h;
        cap = capacity;
    }
    
    int get(int key) {
        auto it=ht.find(key);
        if(it == ht.end()){
            return -1;
        }else{
            auto p = it->second;
            update(p, p->value);
            return p->value;
        }
        
    }
    
    void put(int key, int value) {
        auto it = ht.find(key);
        if(it == ht.end()){
            auto p = new BiLinkNode(key, value);
            insert(p);
            ht[key] = p;
        }else{
            auto p = it->second;
            update(p, value);
        }

        if(ht.size()>cap){
            //delete the oldest;
            auto p = h->pre;
            h->pre = p ->pre;
            p->pre->nxt = h;
            ht.erase(p->key);
            delete p;
        }
        
    }
    
    void insert(BiLinkNode *p){
        p->nxt=h->nxt;
        p->pre =h;
        h->nxt->pre = p;
        h->nxt = p;
    }

    void update(BiLinkNode *p, int value){
        p->value = value;
        p->pre->nxt = p->nxt;
        p->nxt->pre = p->pre;

        p->nxt = h->nxt;
        p->pre = h;
        p->nxt->pre= p;
        h->nxt = p;
    }

    BiLinkNode *h;
    int cap;

    map<int, BiLinkNode *> ht;

};


int main(){
    LRUCache cache(2);
    
    cache.put(2, 1) ;
    cache.put(2, 2) ;
    cout << cache.get(2) << endl;       // returns 1
    cache.put(1, 1) ;    // evicts key 2
//    cout << cache.get(2) << endl;       // returns -1 (not found)
    cache.put(4, 1) ;    // evicts key 1
    cout << cache.get(2) << endl;       // returns -1 (not found)
//    cout << cache.get(3) << endl;       // returns 3
//    cout << cache.get(4) << endl;       // returns 4


}
