#include <iostream>
#include "elapsedtime.h"
#include "algorithms.h"
#include <random>


void quicksort(int *arr, int start, int end)
{
	if(start == end)
		return;
    
    //select the pivot, time bieng first value
    //
    //make partition of the array
    int i = start+1;

    int pivot = arr[start];

    for(int j = i; j <= end; j++)
    {
       if( arr[j] <= pivot)
       {
	       if(i != j)
		       swap(arr[i], arr[j]);
		i++;
       }       
	 
    }

    // swap the pivot to right location
    swap(arr[start], arr[i-1]);

    quicksort(arr, start, i-2);
    quicksort(arr, i, end);

}

void RandomQuickSortTest() {
  int N = 10;
  // intialize random device
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_real_distribution<double> dist(1, N);

  int *arr = new int[N]{};

  for (int k = 0; k < N; k++) {
    arr[k] = dist(mt);
    std::cout << arr[k] << " ";
  }

  std::cout << std::endl;

  std::ofstream timefile;
  clock_t begin_time = clock();

  begintime(begin_time);
  quicksort(arr, 0, N-1);
  elapsedtimeFile(timefile, begin_time);


      for (int k = 0; k < N; k++)
      {
          std::cout << arr[k] << " ";
      }
      std::cout << std::endl;
  
  delete[] arr;
}

