#include "elapsedtime.h"
#include <algorithm>
#include <iostream>
#include <random>
#include "algorithms.h"

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

int MergeSortandCountInversions(int arr[], int start, int end) {
  if (start >= end) {
    return 0;
  }

  int n = end - start + 1;

  // divide the arr in to arrays
  int mid = start + (end - start) / 2;

  int l = MergeSortandCountInversions(arr, start, mid);
  int r = MergeSortandCountInversions(arr, mid + 1, end);

  int m = 0;

  int *A = new int[n];

  int i = start;
  int j = mid + 1;

  // merge the array
  for (int k = 0; k < n; k++) {
    if (i <= mid && j <= end && arr[i] <= arr[j]) {
      A[k] = arr[i];
      i++;
    } else if (i <= mid && j <= end && arr[j] < arr[i]) {
      A[k] = arr[j];
      j++;

      int count = mid - i + 1;
      // std::cout << count << std::endl;
      m = m + count;
    } else {
      if (i <= mid){
		A[k] = arr[i];
		i++;
	  }
      else if (j <= end){
        A[k] = arr[j];
		j++;
	  }
    }
  }

  i = 0;
  for (int k = start; k <= end; k++) {
    arr[k] = A[i];
    i++;
  }

  //	std::cout << "l = " << l << " , r = " << r << " , m = " << m <<
  //std::endl;

  delete[] A;

  return l + r + m;
}

void RandomCountingInversionTest() {
  int N = 1000;
  // intialize random device
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_real_distribution<double> dist(1, N);

  int *arr = new int[N]{};

  for (int k = 0; k < N; k++) {
    arr[k] = dist(mt);
    //        std::cout << arr[k] << " ";
  }

  //    std::cout << std::endl;

  std::ofstream timefile;
  clock_t begin_time = clock();

  begintime(begin_time);
  int count = MergeSortandCountInversions(arr, 0, N);
  elapsedtimeFile(timefile, begin_time);

  std::cout << "inversion count :" << count << std::endl;

  /*    for (int k = 0; k < N; k++)
      {
          std::cout << arr[k] << " ";
      }
      std::cout << std::endl;
  */
  delete[] arr;
}
