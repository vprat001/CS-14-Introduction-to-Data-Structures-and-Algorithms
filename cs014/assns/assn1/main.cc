/*
 * main.cc
 * cs014 Summer 2017
 * assn 1
 */

#include <iostream>
#include <string>
#include "MyList.h"
using namespace std;

int main() {

   cout << "Enter a test number(1-4): ";
    int test;
    cin >> test;
    cout << endl;
   //tests constructor, destructor, push_front, pop_front, display
    if (test == 1) {
    cout << "\nlist1 constructor called";
    MyList list1;
    cout << "\npushfront A";
    list1.push_front('A');
    cout << "\npushfront B";
    list1.push_front('B');
    cout << "\npushfront C";
    list1.push_front('C');
    cout << "\nList1: ";  
    list1.print();
    cout << "\npopfront";              
    list1.pop_front();           
    cout << "\nlist1: ";        
    list1.print();
    cout << "\npopfront";
    list1.pop_front();
    cout << "\nlist1: ";
    list1.print();
    cout << "\npopfront";
    list1.pop_front();                                                                          
    cout << "\nlist1: ";
    list1.print();                                                                                       
    cout << endl;                                                                                                                                          
    }                                                                                                                     
    if (test == 1) {                                                                                                                                                        
cout << "list1 destructor called" << endl;                                                                                                                                                           
}

        if (test == 2) 
	{
		cout << "\nlist2 constructor called";
      		MyList list2;
      		cout << "\npushback A";
      		list2.push_back('A');
      		cout << "\npushback B";
      		list2.push_back('B');
      		cout << "\npushback C";
      		list2.push_back('C');
      		cout << "\nlist2: ";
     		list2.print();
      		cout << "\npopback";
      		list2.pop_back();
      		cout << "\nlist2: ";
	        list2.print();
		cout << endl;
	}
	if (test == 2) 
	{
		cout << "\nlist2 destructor called";
	}

	if (test == 3) 
	{
		cout << "\nlist3 constructor called";
      		MyList list3;
      		cout << "\npushfront A";
      		list3.push_front('A');
      		cout << "\npushfront B";
      		list3.push_front('B');
      		cout << "\npushfront C";
      		list3.push_front('C');
      		cout << "\nlist3: ";
      		list3.print();
		cout << "\nSwap positions 1 and 2";
		list3.swap(1, 2);
		cout << "\nlist3: ";
                list3.print();
		cout << "\nInsert D at position 1";
		list3.insert_at_pos(1, 'D');
		cout << "\nlist3: ";
                list3.print();
		cout << "\nReverse the list ";
		list3.reverse();
		cout << "\nlist3: ";
		list3.print();
		cout << "\nSize of list: ";
	        cout << list3.size();
		cout << "\nFind D ";
		cout << "\nPosition: " << list3.find('D');
		cout << endl;
	}	
	if (test == 3) 
	{	
		cout << "list3 destructor called" << endl;
	}

	if (test == 4) 
	{
		cout << "\nlist4 constructor called";
      		MyList list4;
                cout << "\npushfront A";
                list4.push_front('A');
      		cout << "\npushfront B";
      		list4.push_front('B');
      		cout << "\npushfront C";
      		list4.push_front('C');
      		cout << "\nlist4: ";
      		list4.print();
		MyList newList(list4);
		cout << "\nnewList: ";
		newList.print();
		string name = "Jake";
		cout << "\nNew list from a passed in string: ";
		MyList stringList(name);
		stringList.print();
		
		cout << "\nNew list from a passed in string literal: ";
		MyList charList("Hello World");
		charList.print();

		cout << "\nConcatenate 2 lists: ";
		MyList concatList = stringList + list4;
		concatList.print();
		
		cout << "\nFind first occurence of list4 in concatList: ";
		cout << "\nAt position: " << concatList.find(list4);
		
		cout << "\nFind character at position 2: ";
		cout << concatList[2];
		
		list4 = concatList;
		cout << "\nList4: ";
		list4.print();
		cout << endl;
	}
	if (test == 4) 
	{
		cout << "\nList4 destructor called";
	}
}
