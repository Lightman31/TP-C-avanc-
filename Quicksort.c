#include<stdio.h>
#include <stdlib.h>
#include<pthread.h>
#include<errno.h>
#include<time.h>

#define tabSize 100000000
#define nb_threads 0

int global_threads = 0; 

struct quick_sort_arg
{
	int *array;
	int start;
	int end;
};

void swap(int array[], int a, int b) {
	int temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

void *qsort_worker(void *arg_void);

void quickSort(int array[], int start, int end) {
	int left = start-1;
	int right = end+1;
	const int bias = array[start];
/* if array length is null, nothing to do */
	if(start >= end) return;
/* else, we read the array, one time from right
to left and one time from left to right to search
for element which are on the wrong place.
Once found, we swap them. When right index
reaches left index we stop.*/
	while(1) {
		do right--; while(array[right] > bias);
		do left++; while(array[left] < bias);
		if(left < right) swap(array, left, right);
		else break;
	}
/* Now, all elements lesser than bias are on the
left side and all elements greater than bias are
on the right side. Thus, we have 2 groups to
sort. We launch quicksort on these 2 groups!
That’s what we call recursivity ! */
	if(global_threads<nb_threads)
	{
		pthread_t newThread1;
		pthread_t newThread2;

		struct quick_sort_arg left_half = {
			.array = array,
			.start = start,
			.end = right,
		};

		struct quick_sort_arg right_half = {
			.array = array,
			.start = right + 1,
			.end = end,
		};

	pthread_create(&newThread1, NULL, qsort_worker, &left_half);
	pthread_create(&newThread2, NULL, qsort_worker, &right_half);

	global_threads+=2;
	
	pthread_join(newThread1, NULL);
	pthread_join(newThread2, NULL);

	global_threads-=2;

	}
	else{
	quickSort(array, start, right);
	quickSort(array, right+1, end);
	}
}

void *qsort_worker(void *arg_void)
{
	struct quick_sort_arg *arg = (struct quick_sort_arg*) arg_void;
	quickSort(arg->array, arg->start, arg->end);

	return NULL;
}

int main(void)
{
	clock_t startTime, endTime;
	float timeInSecond;
	startTime=clock();

	int * tab = malloc(sizeof(int)*tabSize);

	for(int i=0; i<tabSize; i++)
	{
		tab[i]= rand() %1000;
	}

/*
	for(int i=0; i<tabSize; i++)
	{
		printf("%d : %d\n", i, tab[i]);
	}
*/

	quickSort(tab, 0, tabSize);

/*
	for(int i=0; i<tabSize; i++)
	{
		printf("%d : %d\n", i, tab[i]);
	}
*/

endTime=clock();
timeInSecond=(endTime-startTime)/(float)CLOCKS_PER_SEC;
printf("time=%f\n",timeInSecond);
}
