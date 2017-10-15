/*
 * queue.cc
 * cs014 Summer 2017
 * assn2
 */
#include <iostream>
#include <stdexcept>
//#define cap 8000
#include "node.h"
using namespace std;


template<typename T>
class Queue {
public:

Queue() {
	head = 0;
	tail = 0;
}        


void enqueue(const T& x) {
/*       
        if ((size()) == (cap - 1))
	{
		throw overflow_error("overflow");
	}
	else 
	{
		queue[tail%cap] = x;
		tail = (tail + 1) % cap;
	}*/

   Node<T>* newNode = new Node<T>(x);
   if ( is_empty ( ) ) 
      head = newNode;
   else
      tail->next = newNode;
   tail = newNode;

}



T front() {
        if(is_empty())
        {
               	throw underflow_error("underflow for front");
        }
     	
	//return queue[head];
	return head->data;
}


void dequeue() {
        if(is_empty())
        {
                throw underflow_error("underflow");
	}
        else
	{
		//head = (head + 1) % cap;
		Node* ptr = head;
		head = head->next;
		if (head == NULL)
			tail = NULL;
		delete ptr;
		--numItems;

	}	
	
	
}
T back() {
	if(is_empty())
        {
                throw underflow_error("underflow for front");
        }
	
	//return queue[tail];
	return tail->data;

}

bool is_empty() {
        /*if ((head == 0) && (tail == 0))
	{
		return true;
	}
	return false;*/
	return (tail == NULL);
	
}
/*
int size() {
	return (cap - head + rear) % cap;
}*/
private:
	Node<T>* head;
        Node<T>* tail;
        //T queue[cap];
	int numItems;
		


};
