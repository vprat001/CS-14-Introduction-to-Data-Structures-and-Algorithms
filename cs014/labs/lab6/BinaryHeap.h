/**
 * cs014
 * BinaryHeap.H, min-heap
 */

#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstdlib>
using namespace std;
template<class T>
class BinaryHeap
{
public:
    BinaryHeap( int capacity = 100 );
    BinaryHeap( const vector<T> & items )
    :  currentSize( items.size( ) ), array( items.size( ) + 10 ) {
        for( unsigned int i = 0; i < items.size( ); i++ )
            array[ i + 1 ] = items[ i ];
        buildHeap( );
    }

    bool isEmpty( ) const {        // Implement isEmpty here
	if (currentSize == 0)
	{
		return true;
	}
	return false;
    }

    const T & findMin( ) const { // Implement findMin here
	return array[1];
    }	



    void insert( const T & x ) {  // Implement insert here
	T item = x;
	insert(item);
    }
    
    /**
     * Prints the elements of the underlying array in the BinaryHeap
     */
    void print( ) const {
        for( int i = 1; i < currentSize + 1; i++ )
            cout << array[i] << " ";
        cout << endl;
    }
    
    /**
     * Remove the minimum item and place it in minItem.
     * Exits the program if empty.
     */
    void deleteMin( ) {
        
        if( isEmpty( ) ) {
            // throw UnderflowException( );
            cerr << "Heap is empty" << endl;
            exit(1);
        }
        array[ 1 ] = array[ currentSize-- ];
        percolateDown( 1 );
    }
    void makeEmpty( );
    
private:
    int currentSize;   // Number of elements in heap
    vector<T> array; // The heap array
    
    void insert( T& newItem ) { // Implement insert here
        if(currentSize == array.size() - 1)
	{
		throw overflow_error("Heap is full, cannot insert.");
        }
        currentSize++;
        int i = currentSize;
        while(i > 0 && array[(i)/2] > newItem)
        {
                array[i] = array[(i) / 2];
                i = (i)/2;
        }
        array[i] = newItem;	
    }
    /**
     * Establish heap order property from an arbitrary
     * arrangement of items. Runs in linear time.
     */
    void buildHeap( ) {
        for( int i = currentSize / 2; i > 0; i-- )
            percolateDown( i );
    }
    
    /**
     * Internal method to percolate down in the heap.
     * hole is the index at which the percolate begins.
     */
    void percolateDown( int hole ) {
      
        //Implement percolateDown here.      
       
	int index;
	if ((2*hole) > currentSize) 
	{
		return;
	}
	if ((2*hole + 1) > currentSize)
	{
		return;	
	}		
	if(array[hole * 2] < array[(hole * 2) + 1])
	{
        	index = hole * 2;
	}
	else 
	{
		index = (hole * 2) + 1;
	}
	if (array[hole] > array[index]) 
	{
		T temp = array[hole];
		array[hole] = array[index];
		array[index] = temp;
		percolateDown(index);
	}

}
    

};

template<class Try>
class BinaryHeapHo
{
public:
    BinaryHeapHo( int capacity = 100 );
    BinaryHeapHo( const vector<Try> & items )
    :  currentSize( items.size( ) ), array( items.size( ) + 10 ) {
        for( unsigned int i = 0; i < items.size( ); i++ )
            array[ i + 1 ] = items[ i ];
        buildHeap( );
    }

    bool isEmpty( ) const {        // Implement isEmpty here
	 if (currentSize == 0)
        {
                return true;
        }
        return false;
    }

    const Try & findMax( ) const { // Implement findMin here
	return array[1];
    }



    void insert( const Try & x ) {  // Implement insert here
	Try item = x;
        insert(item);
    }

    /**
     * Prints the elements of the underlying array in the BinaryHeap
     */
    void print( ) const {
        for( int i = 1; i < currentSize + 1; i++ )
            cout << array[i] << " ";
        cout << endl;
    }

    /**
     * Remove the minimum item and place it in minItem.
     * Exits the program if empty.
     */
    void deleteMax( ) {
	if( isEmpty( ) ) {
            // throw UnderflowException( );
	     cerr << "Heap is empty" << endl;
            exit(1);
        }
        array[ 1 ] = array[ currentSize-- ];
        percolateDown( 1 );
    }
    void makeEmpty( );

private:
    int currentSize;   // Number of elements in heap
    vector<Try> array; // The heap array

    void insert( Try& newItem ) { // Implement insert here
        currentSize++;
        int i = currentSize;
        while(i > 0 && array[(i)/2] < newItem)//changed from > to <
        {
                array[i] = array[(i) / 2];
                i = (i)/2;
        }
        array[i] = newItem;
    }
    /**
     * Establish heap order property from an arbitrary
     * arrangement of items. Runs in linear time.
     */
    void buildHeap( ) {
        for( int i = currentSize / 2; i > 0; i-- )
            percolateDown( i );
    }

    /**
     * Internal method to percolate down in the heap.
     * hole is the index at which the percolate begins.
     */
    
    void percolateDown( int hole ) {
        //Implement percolateDown here. 
	int index;
	if (2*hole > currentSize+ 1) {
		return;
	}
        if ((2*hole+1 ) > currentSize+1)
        {
         	return;      
	}        
        else if(array[hole * 2] > array[(hole * 2) + 1])
        {
                index = hole * 2;
        }
        else
        {
                index = (hole * 2) + 1;
        }
        
        if (array[hole] < array[index])//changed > to <
        {
                Try temp = array[hole];
                array[hole] = array[index];
                array[index] = temp;
                percolateDown(index);
        }
}
    

};

