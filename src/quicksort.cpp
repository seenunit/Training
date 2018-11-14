#include <iostream>
#include "elapsedtime.h"
#include "algorithms.h"
#include <random>


int quicksort(int *arr, int start, int end)
{
    if(start >= end)
        return 0;
    
    int count  = 0;
    //select the pivot, time bieng first value
    //
    //make partition of the array
    int i = start+1;

    int pivot = arr[start];

    for(int j = start+1; j <= end; j++)
    {
       if( arr[j] < pivot)
       {           
           swap(arr[i], arr[j]);
          count += 1;
           i += 1;
       }	 
    }
/*
    for(int k = start; k <= end; k++)
        std::cout << arr[k] << " ";

    std::cout << std::endl;
*/
    // swap the pivot to right location
    swap(arr[start], arr[i-1]);
    count += 1;

    int l =  quicksort(arr, start, i-2);
    int r =  quicksort(arr, i, end);

    count = count + l + r;
    return count;
}

void RandomQuickSortTest() {
  int N = 100;
  // intialize random device
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_real_distribution<double> dist(1, N);

//  int arr[10] {4, 3, 4, 4, 1, 8, 3, 4, 4, 7};
//  int arr1[10] {4, 3, 4, 4, 1, 8, 3, 4, 4, 7};
 int *arr = new int[N]{};
 int *arr1 = new int[N]{};

  for (int k = 0; k < N; k++) {
    arr[k] = dist(mt);
    arr1[k] = arr[k];
    std::cout << arr[k] << " ";
  }

  std::cout << std::endl;

  std::ofstream timefile;
  clock_t begin_time = clock();

  begintime(begin_time);
    int qinv =  quicksort(arr, 0, N-1);
  elapsedtimeFile(timefile, begin_time);

  std::cout << "Total inversions : " << qinv << std::endl;

     for (int k = 0; k < N; k++)
      {
          std::cout << arr[k] << " ";
      }
      std::cout << std::endl;


      std::cout << "Merge sort result :" << std::endl;
  
  begintime(begin_time);
int inversions =   MergeSortandCountInversions(arr1, 0, N-1);
  elapsedtimeFile(timefile, begin_time);

  std::cout << "Total inversion : " << inversions << std::endl;

      for (int k = 0; k < N; k++)
      {
          std::cout << arr1[k] << " ";
      }
      std::cout << std::endl;
  
 // delete[] arr;
 // delete[] arr1;
}

