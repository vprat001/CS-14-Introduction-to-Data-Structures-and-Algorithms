/*
 * Mergesort.H
 * assn4
 * CS014 Summer 2017
 */
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;
template<typename T>
void Merge(T numbers[], int i, int j, int k) {
	int mergedSize = (k - i) + 1;
	int indexPos = 0;
	int lPos = 0;
	int rPos = 0;

	T* mergedNumbers = new T[mergedSize];
	
	lPos = i;
	rPos = j + 1;
	
	while (lPos <= j && rPos <= k) 
	{
		if (numbers[lPos] < numbers[rPos]) 
		{
			mergedNumbers[indexPos] = numbers[lPos];
			++lPos;
		}
		else 
		{
			mergedNumbers[indexPos] = numbers[rPos];
			++rPos;
		}
		++indexPos;
	}

	while (lPos <= j) 
	{
		mergedNumbers[indexPos] = numbers[lPos];
		++lPos;
		++indexPos;
	}
	
	while (rPos <= k)
	{
		mergedNumbers[indexPos] = numbers[rPos];
		++rPos;
		++indexPos;
	}
	
	for (indexPos = 0; indexPos < mergedSize; ++indexPos)
	{
		numbers[i + indexPos] = mergedNumbers[indexPos];
	}
}

template<typename T>
void MergeSorts(T v[], int i, int k) {
	int j = 0;

	if (i < k) 
	{
		j = (i + k) / 2;	
		MergeSorts(v, i, j);
		MergeSorts(v, j + 1, k);
		Merge(v, i, j, k);
	}
}
template<typename T>
vector<T> MergeSort(vector<T>& v) {
        T* arr[v.size()];

	int i = 0;
        int k = v.size() - 1;

	for(unsigned i = 0; i < v.size(); i++) 
	{
		arr[i] = &v[i];
	}

        MergeSorts(*arr,i,k);

	for(unsigned i = 0; i < v.size(); i++) 
	{
		v[i] = *arr[i];
	}
	
        return v;	
}





