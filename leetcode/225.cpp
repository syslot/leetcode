#include "../common.h"

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        s.push_back(x);
        
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int tmp = s.back();
        s.pop_back();
        return tmp;
    }
    
    /** Get the top element. */
    int top() {
        return s.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return s.size() == 0;
    }

    vector<int> s;
};


int main(){
    auto s = new MyStack();
    s->push(4);
    cout << s->top() << endl;
    cout << s->pop() << endl;
    cout << s->empty() << endl;
}
