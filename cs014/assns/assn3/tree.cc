/*
 * tree.cc
 * assn3
 * cs014 summer 2017
 */
#include <iostream>
#include <string>
#include "tree.h"
#include <fstream>
#include <cstdlib>
using namespace std;

Tree::Tree()
{
	root = 0;
	 ofstream ofs("mytree.out");
         if(!ofs)
         {
		cout << "Error opening file";
                exit(1);
         }
}

void Tree::insert(const string& word) {
	insert(word, root);
}

void Tree::insert(const string& wordIn, Node *& t) {
	if(root == NULL)
        {
                root = new Node(wordIn);
		return;
        }
	if(t == NULL) 
	{
		t = new Node(wordIn);
		return;
	}
	else if (wordIn < t->data) 
	{
		insert(wordIn, t->left);
	}
	else if (wordIn > t->data)
	{
		insert(wordIn, t->right);
	}
	else if (wordIn == t->data) 
	{
		t->count = t->count + 1;
	}
	
}

bool Tree::search(const string& keyWord) {
	Node* s;
	s = search(keyWord, root);
	
	if (s != NULL) 
	{
		return true;
	}
	return false;
}

Node* Tree::search(const string& keyWord, Node* r) {
        if(r == 0)
        {
                return 0;
        }
        while(r != 0)
        {
                if(r->data == keyWord)
                {
                        return r;
                }
                else if(r->data > keyWord)
		{
			return search(keyWord, r->left);
		}
		else 
		{	
			return search(keyWord, r->right);
		}
	}
	return 0;
}

string Tree::largest() {
	Node* currObj = root;
	string largest = "";
	string empty = "";
	if ( currObj == 0 ) 
	{
		return empty;
	}
	else {
		largest = currObj->data;
		while ( currObj != 0 )
		{
			if (currObj->right == NULL) 
			{
				return largest;
			}
			else if (largest < currObj->right->data)
			{
				largest = currObj->right->data;
				currObj = currObj->right;
			}
		}
	}
	return largest;
}

string Tree::smallest() {
	Node* currObj = root;
        string smallest = "";
        string empty = "";
        if ( currObj == 0 ) 
        {
                return empty;
        }
        else {
                smallest = currObj->data;
                while ( currObj != 0 )
                {
                        if (currObj->left == NULL)
                        {
                                return smallest;
                        }
                        else if (smallest > currObj->left->data)
                        {
                                smallest = currObj->left->data;
                                currObj = currObj->left;
                        }
                }
        }
        return smallest;
}

int Tree::height(const string& keyWord) {
	Node* currObj = search(keyWord, root);
	
	if (currObj == 0) 
	{
		return -1;
	}
	return height(currObj);
}
	
int Tree::height(Node* hObj) {
	int leftH;
	int rightH;
	
	if(hObj == 0)
	{
		return -1;
	}
	else 
	{
		leftH = height(hObj->left);
		rightH = height(hObj->right);
		
		if (leftH < rightH)
		{
			rightH = rightH + 1;
			return rightH;
		}
		else 
		{
			leftH = leftH + 1;
			return leftH;
		}
	}
}


/*
void Tree::preOrder() const {
	if(root == 0) 
	{
		return;
	}
	preOrder(root);
}

void Tree::preOrder(Node* currObj) const {
	if(currObj != NULL) 
	{
		cout << currObj->data << "(" << currObj->count << "), ";
		preOrder(currObj->left);
		preOrder(currObj->right);
	}
}

void Tree::inOrder() const {
	if(root == 0)
	{
		return;
	}
	inOrder(root);
}

void Tree::inOrder(Node* currObj) const{
	if(currObj != NULL)
	{
		inOrder(currObj->left);
		cout << currObj->data << "(" << currObj->count << "), ";
		inOrder(currObj->right);
	}
}

void Tree::postOrder() const {
	if(root == 0)
	{
		return;
	}
	postOrder(root);
}

void Tree::postOrder(Node* currObj) const {
	if(currObj != NULL)
	{
		postOrder(currObj->left);
		postOrder(currObj->right);
		cout << currObj->data << "(" << currObj->count << "), ";
	}
}

*/
Node* Tree::findMax(Node* currObj)
{
        if(currObj->right == NULL)
        {
            	return currObj;
        }
        else if(currObj->right != NULL)
        {
        	return findMax(currObj->right); 
        }
        return 0;
}

Node* Tree::findMin(Node* currObj) 
{
	if(currObj->left == NULL)
	{
		return currObj;
	}
	else if(currObj->left != NULL)
	{
		return findMin(currObj->left);
	}
	return 0;
}

void Tree::remove(const string& keyWord)
{
	if (root == NULL)
	{
		return;
	}
	else 
	{
		Node* currObj = search(keyWord, root);		
		remove(keyWord, currObj);
	}
}
		


Node* Tree::remove(const string& v, Node* t) {
int i = 0;
      if(t == NULL) {
//         cout << "Error, this value does not exist in this tree." << endl;
  //       cout << "Please re-check the tree." << endl;
           return 0;
      }
      if(t) {
        if(v < t->data)
          t->left = remove(v, t->left);
        else if(t->data < v)
          t->right = remove(v, t->right);
        else if(t->left != NULL && t->right != NULL) {
          t->data = smallest();
          t->right = remove(t->data, t->right);
        }
        else {
          Node* oldNode = t;
          if(t->left != NULL) {
		t = t->left;
	  }
	  else 
	  {
		t = t->right;
	  }
          delete oldNode;
           
	 i--;
         oldNode->count = 0;
	//delete oldNode;
        } 
      }
	if(t->count > 1)
	{
		t->count = t->count - 1;
	}
	
      return t;
    }

			
			 
          
void Tree::printTreeSideways() {
	printTreeSideways(root);
 	return;
}
void Tree::printTreeSideways(Node* t ) {
    // in-order traversal with indented display.
         
         static int depth = 0;
	 ++ depth;
         if ( t == NULL ) return;
         if ( t->right != NULL ) printTreeSideways(t->right);
         for( int i = 0; i != depth; ++i )
     	 	ofs << "  ";
         ofs << "(" << t->data << ")  " << endl;
         if ( t->left != NULL )
                printTreeSideways(t->left);
         --depth;
	return;
}               
            
            
            
                
                
                    
                
                
                
                 
                    
                
                
    

