/*
 * tree.h
 * assn3
 * cs014 summer 2017
 */

#ifndef __TREE_H
#define __TREE_H
#include <iostream>
#include "node.h"
#include "fstream"
using namespace std;

class Tree {

private:
  Node* root;
  ofstream ofs;
private:
  void preOrder(Node * ) const;
  void inOrder(Node * ) const;
  void postOrder(Node * ) const;
  void insert(const string &, Node *&);
  Node* remove(const string&, Node * ); 
  Node* search(const string& , Node* );
  int height(Node* );
  Node* findMax(Node* );
  Node* findMin(Node* );
  void printTreeSideways(Node* );
public:
  Tree();
  void insert( const string & );
  bool search( const string & );
  void inOrder( ) const;
  void postOrder( ) const;
  void preOrder( ) const;
  string largest( );
  string smallest( );
  int height( const string & );
  void remove( const string & );
  void printTreeSideways();
  //void printTreeSideways(Node* );
// Add any additional variables/functions here

};
//void printTreeSideways(Node* );
#endif
