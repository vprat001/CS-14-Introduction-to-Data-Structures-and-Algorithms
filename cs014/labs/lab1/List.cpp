/**
 * UCR CS&E
 * CS014 Lab 1
 * List.cpp
 */

#include <iostream>
#include <cstdlib>
#include "List.h"
#include "Node.h"
#include "Iterator.h"

using namespace std;

/**
 * Constructor
 */
List::List()
{
	head = NULL;
	tail = NULL;
}

/**
 * Destructor
 */
List::~List()
{
	cout << "\nList Destructor called...\n";
	
	while(head)
	{
		Node* temp = head;
		head = head->get_next();
		cout << "Deleting.... " << temp->get_value() << endl;
		delete temp;
	}	
}

/**
 * push_back() inserts a new node at the tail
 * end of the list, with a given value
 * @param value an integer Node value
 * @return none
 */
void List::push_back(int value)
{
	Node* new_node = new Node(value);
	
	/* list is empty */
	if(!head)
	{
		head = new_node;
		tail = new_node;
	}
	else
	{
		new_node->set_prev(tail);
		tail->set_next(new_node);
		tail = new_node;
	}
}
/**
 * push_front() inserts a new node at the 
 * front of the list, with a given value
 * @param value an integer Node value
 * @return none
 */
void List::push_front(int value)
{
	Node* new_node = new Node(value);
		
	/* list is empty */
	if(!head)
	{
		head = new_node;
		tail = new_node;
	}
	else
	{
		new_node->set_next(head);
		head->set_prev(new_node);
		head = new_node;			
	}
}

/**
 * print()const prints the contents of 
 * the list to the console, starting
 * at the head of the list
 * @param none
 * @return none
 */
void List::print()const
{
	cout << "\nList contents:\n";

	/* list is empty */
	if(!head)
	{
		cout << "empty\n";
		return;
	}
	
	for(Iterator iter = begin(); !iter.is_equal(end()); iter.next_pos())
	{
		cout << iter.get_value() << ", ";
	}
	cout << "\n";
}

/**
 * get_head()const returns the head
 * Node pointer which points to the
 * first element in the list
 * @param none
 * @return List's head Node pointer
 */
Node* List::get_head()const
{
	return head;
}

/**
 * get_tail()const  returns the tail
 * Node pointer which points to the
 * last element in the list
 * @param none
 * @return List's tail Node pointer
 */
Node* List::get_tail()const
{
	return tail;
}

/**
 * begin()const gets beginning postion of the list
 * @param none
 * @return an Iterator pointing to the beginning of the list
 */
Iterator List::begin()const
{
	Iterator iter;
	iter.set_curr_pos(get_head());
	iter.set_last_pos(get_tail());
	return iter;
}

/**
 * end()const gets past-the-end postion of the list
 * @param none
 * @return an Iterator pointing just past the end of the list
 */
Iterator List::end()const
{
	Iterator iter;
	iter.set_curr_pos(NULL);
	iter.set_last_pos(get_tail());
	return iter;
}

/**
 * sorted_insert() takes integer value and inserts it into the list
 * as a new node in the list
 * @param value is an integer node value
 * @return none
 */
void List::sorted_insert(int value) {
        if (head == NULL)
        {
                push_front(value);
        }
        else if (value <= head->get_value()) 
        {
                push_front(value);
        }
        else if (value >= tail->get_value())
        {
                push_back(value);
        }
        else
        {
                Node * tempobj = new Node(value);
                for (Node * currobj = head; currobj != NULL; currobj = currobj->get_next())
                {
                        if ((currobj->get_value() < value) && (currobj->get_next()->get_value() >= value))
                        {
                                tempobj->set_next(currobj->get_next());
                                currobj->set_next(tempobj);
                        }
                }
        }
        return;
}

/**
 * print_reverse() prints the contents of a list backwards.
 * @param none
 * @return none
 */
void List::print_reverse()const {        
        for (Node *temp = tail; temp != NULL; temp = temp->get_prev())
        { 
               cout << temp->get_value() << ", ";

        }
}

/**
 * insertAfter() inserts a node with a value at position i+1 in the list.
 * If position is outside the list's boundaries, value is added to the end of the list.
 * @param i is the position of where the value should be inserted
 * @return none
 */
void List::insertAfter(int i, int value) {
       Node* temp = new Node(value);
     
       int size = 0;
       for (Node* temp1 = head; temp1 != NULL; temp1 = temp1->get_next())
       {
              ++size;
       }

       if (i > (size - 1)) {
             push_back(value);
             return;
       }

       if (head == NULL)
       {
             head = temp;
       } 
   
       Node *prevobj = NULL;
       Node *currobj = head;
       int j = 0;
 
       while ((currobj != NULL) && (j <= i))
       {
             prevobj = currobj;
             currobj = currobj->get_next();
             ++j;
       }

       temp->set_next(prevobj->get_next());
       prevobj->set_next(temp);
}


/**
 * insertBefore() inserts a node with a value at position i-1.
 * If the position is outside the list's boundaries, an error message pops up.
 * @param i is the position that is passed in.
 * Value is the number that should be inserted into the list.
 */
void List::insertBefore(int i, int value) {
       Node* temp = new Node(value);
       int size = 0;
   
       for (Node *temp1 = head; temp1 != NULL; temp1 = temp1->get_next())
       {
               ++size;
       }

       if (i > (size - 1)) {
               cout << "Error, please choose a location within the list's boundaries." << endl;
               return;
       } 

       if (head == NULL) 
       { 
               head = temp;
       }

       if (i == 0)
       {
               temp->set_next(head);
               head = temp;
               return;
       }

       Node *prevobj = NULL;
       Node *currobj = head;
       int j = 0;

       while ((currobj != NULL) && (j < i-1))
       {
              prevobj = currobj;
              currobj = currobj->get_next();
              ++j;
       }

       temp->set_next(prevobj->get_next());
       prevobj->set_next(temp);

}

/**
 * count() returns the number of times a certain value appears in the list.
 * @param value is the value that is checked.
 */
int List::count(int value)const {
        int count = 0;
        for(Node* temp = head; temp != NULL; temp = temp->get_next())
        {
                if (value == temp->get_value()) 
                {
                        ++count;
                }
        }
        return count;
}
