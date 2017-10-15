/*
 * node.h
 * assn3
 * cs014 summer 2017
 */
#ifndef __NODE_H__
#define __NODE_H__
#include <iostream>
using namespace std;

class Node 
{
    friend class Tree;
    private:
        int count;
        string data;
        Node* left;
        Node* right; 
    public:
        Node()
        {
            count = 0;
            left = 0;
            right = 0;
            data = "";
        }
        Node(string s)
        {
            count = 1;
            left = 0;
            right = 0;
            data = s;
        }
};

#endif
