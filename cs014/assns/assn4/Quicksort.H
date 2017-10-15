/*
 * Quicksort.H
 * assn4
 * CS014 Summer 2017
 */
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

template<typename T>
int Partition(vector<T>& nums, int i, int k) {
	bool complete = false;
	int midpoint = i + (k-i) / 2;
	T pivot = nums.at(midpoint);
	T tempNum;

	while (complete != true) 
	{
		while (nums.at(i) < pivot) 
		{
			++i;
		}
		
		while (pivot < nums.at(k))
		{
			--k;
		}
		
		if (i >= k) 
		{
			complete = true;
		}
		
		else 
		{
			tempNum = nums.at(i);
			nums.at(i) = nums.at(k);
			nums.at(k) = tempNum;
			
			++i;
			--k;
		}
	}
	return k;
}

template<typename T>
int PartitionMedianofThree(vector<T>& nums, int i, int k) {
        bool complete = false;
        int midpoint;
	T leftmost = nums.at(i);
   	T middle = nums.at(i +(k-i)/2);
   	T rightmost = nums.at(k);
   
   
   	if (middle >= rightmost && middle < leftmost) 
   	{
       		midpoint = (i + (k-i)/2);//middle
   	}
   	else if (leftmost >= middle && leftmost < rightmost) 
   	{
   	    	midpoint = (i);//leftmost
   	}
   	else 
   	{
       		midpoint = (k);//rightmost
   	}

        T pivot = nums.at(midpoint);
        T tempNum;

        while (complete != true)
        {
                while (nums.at(i) < pivot)
                {
                        ++i;
                }

                while (pivot < nums.at(k))
                {
                        --k;
                }

                if (i >= k)
                {
                        complete = true;
                }

                else
                {
                        tempNum = nums.at(i);
                        nums.at(i) = nums.at(k);
                        nums.at(k) = tempNum;

                        ++i;
                        --k;
                }
        }
        return k;
}

template<typename T>
void Quicksorts(vector<T>& numbers, int low, int high) {
   	int partition = 0;
   
   	if (low >= high) 
	{
      		return;
   	}	
   
   	partition = Partition(numbers, low, high);
   
   	Quicksorts(numbers, low, partition);
   	Quicksorts(numbers, partition + 1, high);
   
   	return;
}

template<typename T>
void QuicksortsMedOfthree(vector<T>& numbers, int low, int high) {
        int partition = 0;

        if (low >= high)
        {
                return;
        }

        partition = PartitionMedianofThree(numbers, low, high);

        QuicksortsMedOfthree(numbers, low, partition);
        QuicksortsMedOfthree(numbers, partition + 1, high);

        return;
}


template<typename T>
vector<T> Quicksort(vector<T>& numbers, T pivot) {
	int size = numbers.size();
	vector<T> equal;	
	vector<T> partLow;
	vector<T> partHigh;
	int lowCount = 0;
	int highCount = 0;
	int equalCount = 0;

	for (int i = 0; i < size; ++i)
	{
		if (numbers.at(i) < pivot) 
		{
			partLow.push_back(numbers.at(i));//pushes numbers less than pivot new low vector
			++lowCount;
		}
		
		else if (numbers.at(i) > pivot)
		{
			partHigh.push_back(numbers.at(i));//pushes numbers greater than pivot into new high vector
			++highCount;
		}
		else
		{
			equal.push_back(numbers.at(i));//pushes numbers equal to pivot into new equal vector
			++equalCount;
		}
	}

	Quicksorts(partLow, 0, lowCount - 1);//Sorts numbers lower than pivot

	Quicksorts(partHigh, 0, highCount - 1);//Sorts numbers higher or equal to pivot

	/*Pushes sorted numbers into original numbers vector*/
	for (int j = 0; j < lowCount; ++j) 
	{
		numbers.at(j) = partLow.at(j);
	}
	
	for (int k = 0; k < equalCount; ++k) 
	{
		numbers.at(lowCount + k) = equal.at(k);
	}
	
	for (int l = 0; l < highCount; ++l) 
	{
		numbers.at(lowCount + equalCount + l) = partHigh.at(l);
	} 
	return numbers;//returns vector 
}


template<typename T>
vector<T> QuicksortMedOfthree(vector<T>& numbers, T pivot) {
        int size = numbers.size();
        vector<T> equal;
        vector<T> partLow;
        vector<T> partHigh;
        int lowCount = 0;
        int highCount = 0;
        int equalCount = 0;

        for (int i = 0; i < size; ++i)
        {
                if (numbers.at(i) < pivot)
                {
                        partLow.push_back(numbers.at(i));//pushes numbers less than pivot new low vector
                        ++lowCount;
                }
		
		else if (numbers.at(i) > pivot)
                {
                        partHigh.push_back(numbers.at(i));//pushes numbers greater than pivot into new high vector
                        ++highCount;
                }
                
		else
                {
                        equal.push_back(numbers.at(i));//pushes numbers equal to pivot into new equal vector
                        ++equalCount;
                }
        }

        QuicksortsMedOfthree(partLow, 0, lowCount - 1);//Sorts numbers lower than pivot

        QuicksortsMedOfthree(partHigh, 0, highCount - 1);//Sorts numbers higher or equal to pivot

        /*Pushes sorted numbers into original numbers vector*/
        for (int j = 0; j < lowCount; ++j) 
        {
                numbers.at(j) = partLow.at(j);
        }
        
        for (int k = 0; k < equalCount; ++k) 
        {
                numbers.at(lowCount + k) = equal.at(k);
        }
        
        for (int l = 0; l < highCount; ++l) 
        {
                numbers.at(lowCount + equalCount + l) = partHigh.at(l);
        } 
        return numbers;//returns vector 
}


