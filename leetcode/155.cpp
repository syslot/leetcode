#include "../common.h"


class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s1.push(x);
        if(sm.empty() == true || sm.top() >= x)
            sm.push(x);
    }
    
    void pop() {
        int x = s1.top();
        s1.pop();
        if(x==sm.top()){
            sm.pop();
        }

    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return sm.top();
        
    }

    stack<int> s1;
    stack<int> sm;
};


int main(){

    MinStack m;
    m.push(-2);
    m.push(0);
    m.push(-3);
    cout << m.getMin() << endl;
    m.pop();
    cout << m.top() << endl;
    cout << m.getMin() << endl;



}
