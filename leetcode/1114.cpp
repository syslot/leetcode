#include "../common.h"

class Foo {
public:
    Foo() {
        
        l2.lock();
        l3.lock();
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        l2.unlick();
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        l2.try_lock();
        printSecond();
        l3.unlock();

    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        l3.try_lock();
        printThird();
    }

    mutex l1, l2,l3;
};

void pintFirst(){
    cout << "one" << end;
}
void pintSecond(){
    cout << "two" << end;
}
void pintThree(){
    cout << "three" << end;
}

int main(){


}
