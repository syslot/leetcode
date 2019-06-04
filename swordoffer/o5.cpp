//
// Created by syslot on 2019-04-10.
//

#include "common.h"


//class Solution
//{
//public:
//    void push(int node) {
//        stack1.push(node);
//    }
//
//    int pop() {
//
//        while(!stack1.empty()){
//            stack2.push(stack1.top());
//            stack1.pop();
//        }
//
//        auto ret = stack2.top();
//        stack2.pop();
//
//        while(!stack2.empty()){
//            stack1.push(stack2.top());
//            stack2.pop();
//       }
//        return ret;
//
//    }
//
//private:
//    stack<int> stack1;
//    stack<int> stack2;
//};


class Solution7 {
public:
    int Fibonacci(int n) {
        long a[40];
        a[1] =1;
        a[2] =1;
        for(int i =3;i< 41;i++){
            a[i] = a[i-1] + a[i-2];
        }

        return a[n];
    }
};
int main7(){


    Solution7 s;
//    s.push(1);
//    s.push(2);
//    s.push(3);

//    cout << s.pop()<<endl;

//    s.push(4);
//    cout << s.pop()<<endl;
//    s.push(5);
//    cout << s.pop()<< " "<<s.pop()<<endl;


    cout << s.Fibonacci(39)<< endl;

}


class Solution {
public:
    int jumpFloor(int number) {

    }
};

int main(){
    Solution s;

    cout << s.jumpFloor(10)<<endl;

}