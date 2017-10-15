#include <iostream>
#include <stdexcept>
#include <cstdlib>
#define Capacity 20

using namespace std;


template<class T>          
class Stack { 
        public:
 
                   
          
Stack() {
	size = -1;
	
}


void push(const T& x) {
	if((size + 1) == Capacity)
	{
		throw overflow_error("overflow");
	}
	else {
		stack[++size] = x;
	}
}



T& top() {
	if(is_empty())
	{		
		throw underflow_error("underflow for top");
	}
	return stack[size];

}


void pop() {
	if(is_empty())
	{
		throw underflow_error("underflow for pop");
	}
	else {
		--size;
	}
}



bool is_empty() const {
	if (size == -1)
	{
		return true;
	}
	return false;
}



void print() {
	for(int i = 0; i < Capacity; ++i){
                cout << stack[i] << " ";
	}
}
private: 
	int size;
	T stack[Capacity];
};

