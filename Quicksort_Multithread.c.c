#include<stdio.h>
#include <stdlib.h>
#include<pthread.h>
#include<errno.h>
#include<time.h>

#define tabSize 100000000
#define nbThreads 4

int g_thread_count = 0;

struct quick_sort_arg
{
	int *array;
	int start;
	int end;
};

void swap(int *array, int left, int right) {
	int temp = array[left];
	array[left] = array[right];
	array[right] = temp;
}

int median_of_three(int a, int b, int c)
{
	if(( a < b && a > c) || (a > b && a < c))
		return a;

	if(( b < a && b > c) || (b > a && b < c))
		return b;

	else
		return c;

}

int construct_bias(int * array, int start, int end)
{
	int middle = (end - start) / 2;
	int median = median_of_three(array[start], array[middle], array[end - 1]);
	return median;
}

void insertion_sort(int *array, int start, int end) 
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

void *qsort_worker(void *arg_void);

/*
MULTI THREADED
 */

void quick_sort_mt(int *array, int start, int end) {
	if (end - start <= 20)
	{
		insertion_sort(array, start, end);
	}
	else{
		if(start >= end) return;
		
		const int bias = construct_bias(array, start, end);
		//const int bias = array[start];

		int left = start-1; //  
		int right = end+1;

		while(1) {

			do right--; while(array[right] > bias);
			do left++; while(array[left] < bias);

			if(left < right) swap(array, left, right);
			else break;
		}

		pthread_t newThread2;

		struct quick_sort_arg right_half = {
			.array = array,
			.start = right + 1,
			.end = end,
		};

		if (g_thread_count < nbThreads) {

			quick_sort_mt(array, start, right);
			pthread_create(&newThread2, NULL, qsort_worker, &right_half);
			g_thread_count++;

			pthread_join(newThread2, NULL);
			g_thread_count--;
		}
		else
		{
			quick_sort_mt(array, start, right);
			quick_sort_mt(array, right + 1, end);
		}
	}
	
}

void *qsort_worker(void *arg_void)
{
	struct quick_sort_arg *arg = (struct quick_sort_arg*) arg_void;
	quick_sort_mt(arg->array, arg->start, arg->end);

	return NULL;
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


	quick_sort_mt(tab, 0, tabSize);

	for(int i=0; i<tabSize-1; i++) // check if Qsort sorted correctly.
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
