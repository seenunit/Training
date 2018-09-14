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
	int count = 0;

	if(start == end)
	{
		return count;
	}


    int n = end - start + 1;

/*	if(n == 2)
	{
        if (arr[start] > arr[end])
        {
            swap(arr[start], arr[end]);
            ++count;
        }
        
        return count;
	}
*/
	//divide the arr in to arrays
	int mid = start + (end - start)/ 2 ;

	int l = SortandCount(arr,start, mid);
	int r = SortandCount(arr+ mid + 1, mid + 1, end);

    count = l + r;

    int *A = new int[n];

    int i = start;
    int j = mid + 1;
	
	//merge the array
	for(int k = 0; k < n; k++)
	{
        if (i <= mid && j <= end && arr[i] < arr[j])
        {
            A[k] = arr[i];
            i++;
        }
        else if (i <= mid && j <= end && arr[j] < arr[i])
        {
            A[k] = arr[j];
            j++;

            count += mid - i + 1;
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

    delete[] A;

    return count;
}

void RandomCountingInversionTest()
{
    //// intialize random device
    //std::random_device rd;
    //std::mt19937 mt(rd());
    //std::uniform_real_distribution<int> dist(1, 1000);

    int arr[] = { 2, 1, 3, 1, 2 };

    int count = SortandCount(arr, 0, 4);

    std::cout << "inversion count :" << count << std::endl;

    for (int k = 0; k < 5; k++)
    {
        std::cout << arr[k] << " ";
    }

}
