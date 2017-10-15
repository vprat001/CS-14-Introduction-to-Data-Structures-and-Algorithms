/*
 * main.cc
 * assn3
 * cs014 summer 2017
 */

#include <iostream>
#include "tree.h"

using namespace std;

void printOrders( Tree *tree ) {
  cout << "Preorder = ";
  tree->preOrder( );
  cout << endl;
  cout << "Inorder = ";
  tree->inOrder( );
  cout << endl;
  cout << "Postorder = ";
  tree->postOrder( );
  cout << endl;
}

int main( ) {

  Tree tree;

  cout << "Test 1: Testing simple insert" << endl;
  tree.insert( "hoppy" );
  tree.insert( "gadget" );
  //tree.insert( "gadget" );
  printOrders( &tree );
  cout << "----------------------------------------------------------------" 
       << endl;
 tree.printTreeSideways();
  cout << "Test 2: Search testing" << endl;
  if ( tree.search( "hoppy" ) )
    cout << "Passed" << endl;
  else
    cout << "Failed" << endl;
  cout << "----------------------------------------------------------------" 
       << endl;
  cout << "Test 3: Smallest value in the tree is..." << endl;
  cout << tree.smallest( ) << endl;
  cout << "----------------------------------------------------------------" 
       << endl;
  cout << "Test 4: Largest value in the tree is..." << endl;
  cout << tree.largest( ) << endl;
  cout << "----------------------------------------------------------------" 
       << endl;
  cout << "Test 5: Testing subtree heights" << endl;
  cout << "Height of subtree rooted at \"hoppy\" = " 
       << tree.height( "hoppy" ) << endl;
  cout << "----------------------------------------------------------------" 
       << endl;
  cout << "Test 6: Remove testing" << endl;
  cout << "Removing \"hoppy\"" << endl;
  tree.remove( "hoppy" );
  printOrders( &tree );
  cout << "----------------------------------------------------------------" 
       << endl;
 
  return 1;
}

