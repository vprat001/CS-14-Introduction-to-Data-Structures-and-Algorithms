/*
 * stack.cc
 * cs014 summer 2017
 * assn2
 */
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#define Capacity 4000

using namespace std;


template<class T>
class Stack {
        public:



Stack() {
        sz  = 0;

}
/*
Stack(const Stack& cpy) {

	while(!(this->is_empty())) {
		this->pop();
	}
	while(!(cpy.is_empty())) {
		this->push(cpy.top());
		cpy.pop();
	}

	T temp;
	for (int i = 0; i < sz; ++i) {
		temp = stack[i];
		stack[i] = stack[sz - 1];
		stack[sz - 1] = temp;
	}	
	for (int i = 0; i < sz; ++i) {
		cpy.push(stack[i]);
	}
}	
*/


void push(const T& x) {
        if((sz) == Capacity)
        {
                throw overflow_error("overflow");
        }
        else {
                stack[++sz] = x;
        }
}

int size() const {
	return sz;	
}

T& top() {
        if(is_empty())
        {
                throw underflow_error("underflow for top");
        }
        return stack[sz];

}


void pop() {
        if(is_empty())
        {
                throw underflow_error("underflow for pop");
        }
        else {
                --sz;
        }
}



bool is_empty() const {
       	if (sz == 0)
        {
                return true;
        }
        return false;
}



private:
        int sz;
        T stack[Capacity];
};

