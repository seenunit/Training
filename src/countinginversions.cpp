#include <iostream>
#include "elapsedtime.h"
#include <algorithm>
#include <random>

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int SortandCount(int arr[], int start, int end)
{
	if(start >= end)
	{
		return 0;
	}


    int n = end - start + 1;

	//divide the arr in to arrays
	int mid = start + (end - start)/ 2 ;

	int l = SortandCount(arr,start, mid);
	int r = SortandCount(arr, mid + 1, end);

	int m = 0;

    int *A = new int[n];

    int i = start;
    int j = mid + 1;
	
	//merge the array
	for(int k = 0; k < n; k++)
	{
        if (i <= mid && j <= end && arr[i] <= arr[j])
        {
            A[k] = arr[i];
            i++;
        }
        else if (i <= mid && j <= end && arr[j] < arr[i])
        {
            A[k] = arr[j];
            j++;

            int count = mid - i + 1;
	   // std::cout << count << std::endl;
	    m = m + count;
        }
        else
        {
            if (i == mid)
                A[k] = arr[i];
            else if (j == end)
                A[k] = arr[j];
        }

    }

    i = 0;
    for (int k = start; k <= end; k++)
    {
        arr[k] = A[i];
        i++;
    }

//	std::cout << "l = " << l << " , r = " << r << " , m = " << m << std::endl;

    delete[] A;

    return l + r + m;
}

void RandomCountingInversionTest()
{
    //// intialize random device
    //std::random_device rd;
    //std::mt19937 mt(rd());
    //std::uniform_real_distribution<int> dist(1, 1000);

    int arr[] = { 2, 1, 3, 1, 2 };

    for (int k = 0; k < 5; k++)
    {
        std::cout << arr[k] << " ";
    }

    std::cout << std::endl;


    int count = SortandCount(arr, 0, 4);

    std::cout << "inversion count :" << count << std::endl;

    for (int k = 0; k < 5; k++)
    {
        std::cout << arr[k] << " ";
    }
    std::cout << std::endl;

}
