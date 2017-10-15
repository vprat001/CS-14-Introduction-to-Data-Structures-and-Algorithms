/*
 * cs014_16sum1
 * lab 3
 * BST.H
 */

#ifndef BST_H_
#define BST_H_

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

class BST {

private:
  struct BinaryNode {

    int value;
    BinaryNode* left;
    BinaryNode* right;
    BinaryNode(int& v) : value(v), left(NULL), right(NULL) {}
    static BinaryNode* insert(int v, BinaryNode* t) {
      if(t == NULL){
	t = new BinaryNode(v);
      }
      else if (v < t->value)
	t->left = insert(v, t->left);
      else if (v > t->value)
	t->right = insert(v, t->right);
      else if (v == t->value)
	cout << "Error, this value already exists in this tree." << endl;
      else
	t->value = v;
      
      	
      return t;
    }
    
    static BinaryNode* remove(int v, BinaryNode* t) {
      if(t == NULL) {
	 cout << "Error, this value does not exist in this tree." << endl;
	 cout << "Please re-check the tree." << endl;
      }      	
      if(t) {
	if(v < t->value)
	  t->left = remove(v, t->left);
	else if(t->value < v)
	  t->right = remove(v, t->right);
	else if(t->left != NULL && t->right != NULL) {
	  t->value = find_min(t->right)->value;
	  t->right = remove(t->value, t->right);
	}
	else {
	  BinaryNode* oldNode = t;
	  t = (t->left != NULL) ? t->left
	    : t->right;
	  delete oldNode;
	}
	
      }
      return t;
    }
    
    static BinaryNode* find_min(BinaryNode* t) {
      if(t == NULL)
	return NULL;
      if(t->left == NULL)
	return t;
      return find_min(t->left);
    }
    	
  };

public:
  BST(): root(NULL) {
	ofs.open("output.dot");
        if(!ofs) {
        cout << "output.dot could not be opened." << endl;
        exit(1);
        }
	preKey = 1;
	leftH = 0;
	rightH = 0;
	}
  ~BST() {}
  void insert(int v) { root = BinaryNode::insert(v, root); }
  void remove(int v) { root = BinaryNode::remove(v, root); }
  void display() { display(root); }
  void display( BinaryNode* t ) {
    // in-order traversal with indented display.
    static int depth = 0;
    ++ depth;
    if ( t == NULL ) return;
    if ( t->right != NULL ) display(t->right);
    for( int i = 0; i != depth; ++i )
      cout << " ";
    cout << t->value << " " << endl;
    if ( t->left != NULL )
      display(t->left);
    --depth;
  }
  void postOrder() {
        if (root == 0)
        {
            return;
        }
	ofs << "//PostOrder: " << endl;
        ofs << "digraph G {" << endl;
	postOrder(root);
	ofs << "}" << endl;
  }
 
  void postOrder(BinaryNode* currObj) {
	if (root == NULL)
    	{
       		ofs << "Tree is empty" << endl;
        	return;
    	}
	if (currObj != NULL)
    	{
        	postOrder(currObj->left);
        	postOrder(currObj->right);
        	ofs << currObj->value <<  " [color = green, peripheries=2, style = filled, label = " << "\"" << "Key= " << currObj->value << ", Post= " << preKey << "\"];" << endl;
 		preKey = preKey + 1;
		/*
	 	if((currObj->left != 0 && currObj->right != 0))
         	{

                	ofs << currObj->value << " -> " << currObj->left->value << " [color=blue];" << endl;
                	ofs << currObj->value << " -> " << currObj->right->value << " [color=blue];" << endl;
         	}
		else if(currObj->left != 0 && currObj->right == 0)
		{
			ofs << currObj->value << " -> " << currObj->left->value << " [color=blue];" << endl;
		}
		else 
		{
			ofs << currObj->value << " -> " << currObj->right->value << " [color=blue];" << endl;
		}*/
		if(currObj->left)
                {
                        ofs << currObj->value << " -> " << currObj->left->value << ";" << " [color=blue];" << endl;
                }
                if(currObj->right)
                {
                        ofs << currObj->value << " -> " << currObj->right->value << ";" << " [color=blue];" << endl;
                }
  	}
  }

  void inOrder() {
        if (root == 0)
        {
            	return;
        }
	ofs << "//InOrder: " << endl;
	ofs << "digraph G {" << endl;
        inOrder(root);
	ofs << "}" << endl;
  }
 
  void inOrder(BinaryNode *currObj) {
	
	if (root == NULL)
        {
                ofs << "Tree is empty" << endl;
                return;
        }
	
	if (currObj != 0) {
		
            	inOrder(currObj->left);
		ofs << currObj->value <<  " [color = red, peripheries=2, style = filled, label = " << "\"" << "Key= " << currObj->value << ", In= " << preKey << "\"];" << endl;
            	preKey = preKey + 1;
		inOrder(currObj->right);
		/*if(currObj->left != 0 && currObj->right != 0)
        	{
			
                	ofs << currObj->value << " -> " << currObj->left->value << ";" << " [color=blue];" << endl;
                	ofs << currObj->value << " -> " << currObj->right->value << ";" << " [color=blue];" << endl;
        	}
		else if(currObj->left != 0 && currObj->right == 0)
                {
                        ofs << currObj->value << " -> " << currObj->left->value << " [color=blue];" << endl;
                }
                else
                {
                        ofs << currObj->value << " -> " << currObj->right->value << " [color=blue];" << endl;
                }*/
		if(currObj->left)
                {
                        ofs << currObj->value << " -> " << currObj->left->value << ";" << " [color=blue];" << endl;
                }
                if(currObj->right)
                {
                        ofs << currObj->value << " -> " << currObj->right->value << ";" << " [color=blue];" << endl;
                }
				
        
	}

  }
	
  void preOrder() {
    	if(root == 0)
    	{
        	return;
    	}
	ofs << "//PreOrder: " << endl;
	ofs << "digraph G {" << endl;
    	preOrder(root);
	ofs << "}" << endl;
  }
 
  void preOrder(BinaryNode *currObj) {
    	if (root == NULL)
        {
                ofs << "Tree is empty" << endl;
                return;
        }
	if(currObj != 0)
    	{	
		
	      	ofs << currObj->value <<  " [color = orange, peripheries=2, style = filled, label = " << "\"" << "Key= " << currObj->value << ", Pre= " << preKey << "\"];" << endl;
		preKey = preKey + 1;
        	preOrder(currObj->left);
        	preOrder(currObj->right);
		if(currObj->left)
		{
			ofs << currObj->value << " -> " << currObj->left->value << ";" << " [color=blue];" << endl;
		}
		if(currObj->right)
		{
			ofs << currObj->value << " -> " << currObj->right->value << ";" << " [color=blue];" << endl;
		}

		/*if(currObj->left != 0 && currObj->right != 0)
                {

                        ofs << currObj->value << " -> " << currObj->left->value << ";" << " [color=blue];" << endl;
                        ofs << currObj->value << " -> " << currObj->right->value << ";" << " [color=blue];" << endl;
                }
		else if(currObj->left != 0 && currObj->right == 0)
                {
                        ofs << currObj->value << " -> " << currObj->left->value << " [color=blue];" << endl;
                }
                else
                {
                        ofs << currObj->value << " -> " << currObj->right->value << " [color=blue];" << endl;
                }*/
        }
  }
  
  void height()
  {
        if(root == 0)
        {
                return;
        }
        ofs << "//Height: " << endl;
        ofs << "digraph G {" << endl;
        height(root);
        ofs << "}" << endl;
  }

  int height(BinaryNode* currObj)
  {
       
        if (root == NULL)
        {
                ofs << "Tree is empty" << endl;
                
        }
        if(currObj != 0)
        {
        
        	leftH = height(currObj->left);
        	rightH = height(currObj->right);
        	ofs << currObj->value <<  " [color = lightblue, style = filled, label = " << "\"" << "Key= " << currObj->value << ", Height= ";
		
                
        	if (leftH < rightH)
        	{
			ofs << rightH << "\"];" << endl;
           		rightH = rightH + 1;
        	}
        	else
        	{
			ofs << leftH << "\"];" << endl;
        	    	leftH = leftH + 1;
        	}
		/*if(currObj->left != 0 && currObj->right != 0)
                {

                        ofs << currObj->value << " -> " << currObj->left->value << ";" << endl;
                        ofs << currObj->value << " -> " << currObj->right->value << ";" << endl;
                }*/
		if(currObj->left)
                {
                        ofs << currObj->value << " -> " << currObj->left->value << ";" << " [color=blue];" << endl;
                }
                if(currObj->right)
                {
                        ofs << currObj->value << " -> " << currObj->right->value << ";" << " [color=blue];" << endl;
                }
        }
	return 0;
    }
    
private:
  BinaryNode* root;
  ofstream ofs;
  int preKey;
  int rightH;
  int leftH;
};

#endif /* BST_H_ */

