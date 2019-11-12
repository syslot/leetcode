#include "../common.h"

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s2.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int tmp = peek();
        s1.pop();
        return tmp;
    }
    
    /** Get the front element. */
    int peek() {
        if(s1.empty()){
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        }
        return s1.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty() && s2.empty();
    }

    stack<int>s1, s2;
};

int main(){
    MyQueue mq;

    mq.push(1);
    mq.push(2);
    cout << mq.peek() << endl;
    cout << mq.pop() <<endl;
    cout << mq.empty() << endl;

}
