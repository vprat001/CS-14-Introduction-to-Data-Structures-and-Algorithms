/**
 * cs014
 * main.cc for BinaryHeap
 */
 
//#include "BinaryHeap.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

// Implement heapsort here

int currentSize = 0;

template<typename T>
void percolateDown(vector<T>& A, int hole) {

	if ((2*hole + 1) > currentSize)
	{
		return;
	}

	int sm_ch = 2*hole + 1;

	if ( 2*hole + 2<= currentSize)
	{
		if(A[2*hole+1] < A[2*hole+2])
		{
			sm_ch = 2*hole + 2;
		}
	}	
	if (A[sm_ch] > A[hole]) {
		T temp = A[sm_ch];
		A[sm_ch] = A[hole];
		A[hole] = temp;
	}

	percolateDown(A, sm_ch);
}

template<typename T>
void buildMaxHeap(vector<T>& A) {
	currentSize = A.size() - 1;

        for (int j = currentSize /2; j >= 0; --j) 
	{
                percolateDown(A, j);
        }
}

template<typename T>
void print(vector<T> & arr) {
        int currentSize = arr.size();

        for (int i = 0; i < currentSize; ++i) {
                cout << arr[i] << " ";
        }
}

template<typename T>
void heapSort(vector<T>& A) {
	buildMaxHeap(A);

	while(currentSize >= 1) 
	{
		T temp = A[0];
		A[0] = A[currentSize];
		A[currentSize] = temp;
		--currentSize;
		
		for(int i = currentSize /2; i>= 0; i--)
		{
			percolateDown(A, i);
		}
	}
	return;
}


int main() {
    //ints 
    vector<int> v;
    v.push_back(3);//10
    v.push_back(7);//6
    v.push_back(9);//8
    v.push_back(1);//4
    v.push_back(8);//2
    v.push_back(2);//12
    v.push_back(10);//14
    //v.push_back(14);
    //v.push_back(3); 
    
/*
    BinaryHeap <int>pq(v);
    cout << "MinHeap ints: " << endl;
    pq.print( );
    cout << endl;

    pq.insert(4);
    pq.insert(3);
    pq.insert(2);
    pq.insert(4);
    pq.insert(9);
    pq.insert(3);

    cout << "MinHeap ints with inserts: " << endl;
    pq.print(); 
    cout << endl;
*/
    
    //string
    vector<string> s;
    s.push_back("hello");
    s.push_back("me");
    s.push_back("A");
    s.push_back("have");
    s.push_back("been");
    s.push_back("why");
    s.push_back("wondering");
    s.push_back("lenovo");
    s.push_back("joke");
    s.push_back("Steak"); 

/*  BinaryHeap <string>pw(s);
    cout << "MinHeap strings: " << endl;
    pw.print();
    cout << endl;

    pw.insert("okay");
    pw.insert("peach");
    pw.insert("google");
    pw.insert("apple");
    pw.insert("coffee");
    cout << "MinHeap strings with inserts: " << endl;
    pw.print();
    cout << endl;

    //MaxHeap
    //Int
    BinaryHeapHo <int>pr(v);
    cout << "MaxHeap ints: " << endl;
    pr.print();
    cout << endl;
    pr.insert(4);
    pr.insert(3);
    pr.insert(5);
    pr.insert(7);
    pr.insert(9);
    cout << "MaxHeap ints with inserts: " << endl;
    pr.print();
 
    //String
    BinaryHeapHo <string>pn(s);
    cout << "MaxHeap strings: " << endl;
    pn.print();
    cout << endl;
    
    pn.insert("okay");
    pn.insert("peach");
    pn.insert("google");
    pn.insert("apple");
    cout << "MaxHeap strings with inserts: " << endl;
    pn.print();
    cout << endl;
    */
    cout << "HeapSort Max(increasing order): " << endl;
    heapSort(v);
    
    
    // Add additional tests for new BinaryHeap functionality here
    // Add additional tests for heapsort here. You should use the
    // print function to view the heap at each step of the sort. 
    print(v);   
    return 0;
}



