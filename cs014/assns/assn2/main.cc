/*
 * main.cc
 * cs014 Summer 2017
 * assn2
 */
#include <iostream>
#include "WordLadder.h"
#include "stack.cc"
#include "queue.cc"
using namespace std;

int main() {
	string dictionaryFile;
	string beginWord;
	string endWord;

	cout << "Enter the name of the dictionary file: ";
	cin >> dictionaryFile;
	cout << endl;

	cout << "Please enter the first word for the Ladder: ";
	cin >> beginWord;
	cout << endl;
	
	if (beginWord.size() != 5) 
	{
		cout << "Word must have exactly 5 letters." << endl;
		cout << "Please re-enter the first word: ";
       		cin >> beginWord;
      		cout << endl;
	}
	
	cout << "Please enter the last word for the Ladder: ";
	cin >> endWord;
	cout << endl;
	
	if (endWord.size() != 5)
        {
                cout << "Word must have exactly 5 letters." << endl;
                cout << "Please re-enter the last word: ";
                cin >> endWord;
                cout << endl;
        }
	
	WordLadder firstLadder(dictionaryFile.c_str());
	cout << "Word Ladder may take a few seconds to output" << endl;

	firstLadder.outputLadder(beginWord, endWord);

	return 0;
	
}
