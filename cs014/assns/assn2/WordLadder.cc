/*
 * WordList.cc
 * cs014 Summer 2017
 * assn2
 */
#include <iostream>
#include "queue.cc"
#include "stack.cc"
#include <string>
#include <fstream>
#include <cstdlib>
#include "WordLadder.h"
#include <list>
using namespace std;


WordLadder::WordLadder(const string& listFile) {
	ifstream inFS;
	string words;
	
	inFS.open(listFile.c_str());

	if(!inFS.is_open())
	{
		cout << "Error, cannot open this file." << endl;
		return;
	}
	
	while(inFS >> words) 
	{
		if(words.size() != 5)
		{
			cout << "Word is not the correct size of 5." << endl;
		}
		else {
			
			dictionary.push_back(words);
		}
	
	}
	
	inFS.close();
	
}

void WordLadder::outputLadder(const string &start, const string &end) {

	Stack<string> stackOfStrings;                      	//Create a stack of strings.
	
	if(start == end)
        {
                cout << start << endl;
                exit(0);
        }
	bool ends = false;			

	Queue<Stack <string> > queueofStacks;			//Create a queue of stacks.
	
	stackOfStrings.push(start);                             //Push the start word onto this stack.
	queueofStacks.enqueue(stackOfStrings);			//Enqueue this stack.


		
	while((!queueofStacks.is_empty()) && (ends != true))	//While the queue is not empty.
	{

		list<string>::iterator iter = dictionary.begin();

		for (iter = dictionary.begin(); ((iter != dictionary.end()) && (ends != true)); ++iter)
		{						//For each word in the dictionarye
			
			int numCharsTotal = 0;	
			string frontStack = queueofStacks.front().top();
			string tempString;
			
			tempString = *iter;

			for (int i = 0; i < 5; ++i) 
			{
				if (tempString[i] == frontStack[i])
				{
					++numCharsTotal;
				}
			}
		
			
			
			
			if (numCharsTotal == 4)			//If a word is one letter different...
			{
				Stack<string> cpyStack;
				cpyStack = queueofStacks.front(); //Make a copy of the front stack.
	
				cpyStack.push(*iter);		//Push the found word onto the copy.
				
				
				queueofStacks.enqueue(cpyStack);	//Enqueue the copy.
				
				iter = dictionary.erase(iter);	
				--iter;
	
				if (queueofStacks.back().top() == end)
				{
					ends = true;
				}
			
			}
		}
		
		if (ends != true)
		{
			queueofStacks.dequeue(); 			//Dequeue front stack. 
		}
	}
	
	if ((!queueofStacks.is_empty()) && (ends == true))	//This if statement is used to print out the Word Ladder.
	{
		Stack<string> wordLadderResult;
		while (!queueofStacks.back().is_empty())
		{
			wordLadderResult.push(queueofStacks.back().top());
			queueofStacks.back().pop();
		}
	
		while (!wordLadderResult.is_empty())
		{
		
			if (wordLadderResult.size() == 1)
			{
				cout << wordLadderResult.top();
			}
			else 
			{
				cout << wordLadderResult.top() << " ";
			}
			
			wordLadderResult.pop();
			
		}
		cout << endl;
	}
	else 
	{
		cout << "This word Ladder does not exist." << endl;
	}
}

