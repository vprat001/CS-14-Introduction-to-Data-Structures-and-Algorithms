/*
 * WordLadder.h
 * cs014 Summer 2017
 * assn2
 */
#ifndef WORDLADDER_H
#define WORDLADDER_H
#include <iostream>
#include <list>
#include <string>
//#include "stack.cc"
//#include "queue.cc"
using namespace std;
	
class WordLadder{

	public:
		WordLadder(const string &listFile);
		void outputLadder(const string &start, const string &end);
		
	
	private:
		list<string> dictionary;

};
#endif
