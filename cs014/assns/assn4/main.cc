/*
 * main.cc
 * assn4
 * CS014 Summer 2017
 */
#include <iostream>
#include <vector>
#include "Quicksort.H"
#include <string>
#include "Mergesort.H"

using namespace std;

int main() {   
	
    	vector<int> v;
    	v.push_back(10);//10
    	v.push_back(6);//6
    	v.push_back(8);//8
    	v.push_back(4);//4
    	v.push_back(2);//2
    	v.push_back(12);//12
    	v.push_back(14);//14
    	v.push_back(1);
    	v.push_back(10);
    	v.push_back(7);

	vector<string> s;
	s.push_back("holy");
	s.push_back("joke");
	s.push_back("apple");
	s.push_back("paper");
	s.push_back("laptop");
	s.push_back("bottle");
	s.push_back("wonder");
        s.push_back("dell");
        s.push_back("adele");
        s.push_back("beyonce");
        s.push_back("samsung");
        s.push_back("drones");

	vector<int> result = MergeSort(v);
	string j = "dell";
	vector<string> r = Quicksort(s, j);

	int sz = r.size();
	int size = result.size();
	cout << "Mergesorts 10 integers: " << endl;
	for (int i = 0; i < size; ++i) 
	{
		cout << result.at(i) << " ";
	}
	
	cout << endl;
	cout << "Quicksorts 12 strings: " << endl;
	for (int i = 0; i < sz; ++i)
	{
		cout << r.at(i) << " ";
	}

/*	vector<string> medOfThree = QuicksortMedOfthree(s, j);
	int mSize = medOfThree.size();
	cout << "Quicksorts 12 strings using median of three pivots: " << endl;
	for (int i = 0; i < mSize; ++i)
        {
                cout << medOfThree.at(i) << " ";
        }
*/	
}


		
