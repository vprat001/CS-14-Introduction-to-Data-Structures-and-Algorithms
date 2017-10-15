/*
 * MyList.cc
 * cs014 Summer 2017
 * assn1
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include "MyList.h"

using namespace std;

//Constructors
MyList::MyList() {
	head = 0;
}

MyList::MyList(const MyList& str) {
	head = 0;
        for (Node* currObj = str.head; currObj != 0; currObj = currObj->next)
	{
		push_back(currObj->value);
	}
}

MyList::MyList(const string& str) {
	head = 0;
       
	for (int i = 0; i < str.size(); ++i)
	{
		push_back(str[i]);
	}
}

MyList::MyList(const char* str) {
	head = 0;
	while(*str) 
	{
		push_back(*str);
		++str;
	}
}


//Destructor
MyList::~MyList() {
	delete[] head;
}

//Mutators
void MyList::push_front(char value) {
	if(head != 0) 
	{
		Node* tempObj = head;
		head = new Node();
		head->value = value;
		head->next = tempObj;
	}
	else
	{
		head = new Node();
		head->value = value;
	}
}

void MyList::push_back(char value) {
	if(head == 0) 
	{
		head = new Node();
		head->value = value;
	}
	else
	{
		Node* temp = new Node();
		temp->value = value;
		Node* currObj = head;
		while(currObj->next != NULL)	
		{
			currObj = currObj->next;
		}	
		currObj->next = temp;
        }		
}



void MyList::pop_front() {
	if(head != 0) 
	{
		Node* tempObj = head->next;
		delete head;
		head = tempObj;
	}
	else
	{
		return;
	}
}

void MyList::pop_back() {
	if (head != 0) {
		Node* prev = NULL;
		Node* curr = head;
		while(curr->next != NULL)
		{
			prev = curr;
			curr = curr->next;
		}
		delete prev;
	}
	if (head->next == NULL) 	
	{
		delete head;
	}
	return;
}

void MyList::swap(int i, int j) {
	Node* currObj;
	int size = 0;
	for(currObj = head; currObj != NULL; currObj = currObj->next)
	{
		++size;
	}
	
	if ((i > (size-1)) || (j > (size-1)))
	{
		cout << "\nError, please enter positions within the list.";
		exit(0);
	}
	if (head == 0) 
	{
		return;
	}

	Node* objI = NULL;
	currObj = head;
	int k = 0;
	
	while((currObj != NULL) && (k <= i)) 
	{
		objI = currObj;
		currObj = currObj->next;
		++k;
	}
	
	Node* objJ = NULL;
	currObj = head;
	k = 0;
	
	while((currObj != NULL) && (k <= j))
	{
		objJ = currObj;
		currObj = currObj->next;
		++k;
	}
	k = objI->value;
	objI->value = objJ->value;
	objJ->value = k;

}

void MyList::insert_at_pos(int i, char value) {
	Node* temp = new Node();
	temp->value = value;
	Node* currObj;
	int size = 0;
	for(currObj = head; currObj != NULL; currObj = currObj->next)
	{
		++size;
	}

	if(i > (size - 1))
        {
		push_back(value);
		return;
	}
        
        if(head == NULL)
	{
		head = temp;
	}

	Node* prevObj = NULL;
	currObj = head;
	int j = 0;	
	
	while ((currObj != NULL) && (j < i))
	{
		prevObj = currObj;
		currObj = currObj->next;
		++j;
	}
	temp->next = prevObj->next;
	prevObj->next = temp;
}

void MyList::reverse() {
	Node* temp = NULL;
	Node* currObj = head;
	Node* nextObj;

	if(head == NULL)
	{
		return;
	}
	
	
	while(currObj != NULL) 
	{
		nextObj = currObj->next;
		currObj->next = temp;
		temp = currObj;
		currObj = nextObj;
	}
        head = temp;
}

//Accessors
int MyList::size()const {
	Node* currObj = head;
	int size = 0;
	while(currObj != NULL) 
	{
		currObj = currObj->next;
		++size;
	}
	return size;
}

void MyList::print()const {
	for(Node* temp = head; temp != NULL; temp = temp->next) 
	{
		cout << temp->value << " ";
	}
}

int MyList::find(char value)const {
	int position = 0;
	for(Node* temp = head; temp != NULL; temp = temp->next)
	{
		if(temp->value == value) 
		{
			return position;
		}
		++position;
	}
	return -1;
}

int MyList::find(MyList& query_str)const {
	int position = 0;
	for(Node* temp = head; temp != NULL; temp = temp->next)
	{
		Node* curr = query_str.head;
		if(temp->value == curr->value) {
			return position;
		}
		++position;
	 	curr = curr->next;
	}
	return -1;
}

//Operator Overloaders
MyList& MyList::operator=(const MyList& str) {
	if(this == &str)
	{
		return *this;
	}
	head = 0;
	for(Node* currObj = str.head; currObj != 0; currObj = currObj->next) 
	{
		push_back(currObj->value);
	}
	return *this;
}

char& MyList::operator[](const int i) {
	Node* temp;
        Node* currObj = head;
        int j = 0;

        while ((currObj != NULL) && (j <= i))
        {
                temp = currObj;
                currObj = currObj->next;
                ++j;
        }
	return temp->value;

}

MyList& MyList::operator+(const MyList& str) {
	MyList* result;
	result = this;
	Node* tempObj = result->head;
	
	while(tempObj->next != NULL) 
	{
		tempObj = tempObj->next;
	}
	tempObj->next = str.head;

	return *result;
}
	
