#include<stdio.h>
#include <stdlib.h>
#include<pthread.h>
#include<errno.h>
#include<time.h>

#define tabSize 100000000 // number of array cells that need to be sorted.

/**************************************************************

	Quicksort is a function whose purpose is to sort in the most 
	optimized way possible an array of random numbers. In order to 
	improve the algorithm we take the median of the begining, end
	and middle value of the array in order to obtain a better bias.
	The quicksort has been improved by implementing an insertion 
	sort if the size of an array to be sorted is 20 or less, making it
  a faster algorithm in general.

 **************************************************************/


struct quick_sort_arg
{
	int *array;
	int start;
	int end;
};

void swap(int *array, int left, int right) // function swaps two elements of a given array.
{
	int temp = array[left];
	array[left] = array[right];
	array[right] = temp;
}

int median_of_three(int a, int b, int c) // function searches the median of 3 integers
{
	if(( a < b && a > c) || (a > b && a < c))
		return a;

	if(( b < a && b > c) || (b > a && b < c))
		return b;

	else
		return c;

}

int construct_bias(int * array, int start, int end) // function that returns the bias calculated by using the median of begin, middle and end of array.
{
	int middle = (end - start) / 2;
	int median = median_of_three(array[start], array[middle], array[end - 1]);
	return median;
}

void insertion_sort(int *array, int start, int end) // insertion sort impltementation for small sized arrays to sort.
{ 
	int i, key, j; 
	for (i = start + 1; i < end+1; i++) { 
		key = array[i]; 
		j = i - 1; 

        /* Move elements of array[0..i-1], that are 
          greater than key, to one position ahead 
          of their current position */
		while (j >= 0 && array[j] > key) { 
			array[j + 1] = array[j]; 
			j = j - 1; 
		} 
		array[j + 1] = key; 
	} 
} 


/*
SINGLE THREADED
 */

void quick_sort(int *array, int start, int end) // Implementation of QuickSort that sorts an array quickly.
{

	if (end - start <= 20)
	{
		insertion_sort(array, start, end);
	}
	else{
		
		if(start >= end) return;

		const int bias = construct_bias(array, start, end);
		//const int bias = array[start];

		int left = start-1; 
		int right = end+1;

		while(1) {

			do right--; while(array[right] > bias);
			do left++; while(array[left] < bias);

			if(left < right) swap(array, left, right);
			else break;
		}

		quick_sort(array, start, right);
		quick_sort(array, right + 1, end);
	}
}

int main(void)
{
	clock_t startTime, endTime;
	float timeInSecond;
	startTime=clock();

	int * tab = malloc(sizeof(int)*tabSize);


	for(int i=0; i < tabSize; i++)
	{
		tab[i]= rand() % 1000;
	}


	quick_sort(tab, 0, tabSize);

	for(int i=0; i<tabSize-1; i++) // to check if quick_sort sorted correctly.
	{
		if(tab[i]>tab[i+1])
		{
			printf("Problem with Qsort: %d > %d\n", tab[i], tab[i + 1]);
			return -1;
		}
	}

	endTime=clock();
	timeInSecond=(endTime-startTime)/(float)CLOCKS_PER_SEC;
	printf("time=%f\n",timeInSecond);
}
