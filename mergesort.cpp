//c++ implementation of mergesort
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void merge(int A[],int left[],int right[],int leftcount,int rightcount)
{
	int l=0;
	int r=0;
	int i=0;
	while(l<leftcount && r<rightcount)
	{
		if(left[l]<right[r])
			A[i++] = left[l++];
        else
			A[i++] = right[r++];
	}

	while(l<leftcount)
	{
		A[i++] = left[l++];
    }

	while(r<rightcount)
	{
		A[i++] = right[r++];

	}

}

void mergesort(int arr[],int n)
{
	int mid = n/2;
	int left[mid];
	int right[n-mid];

	for(int i=0;i<mid;i++)
	{
		left[i] = arr[i];
	}
	for(int i=mid+1;i<n;i++)
	{
		right[i-mid] = arr[i];
	}


		 mergesort(arr,mid);
		 mergesort(arr,n-mid);
		merge(arr,left,right,mid,n-mid);

}

int main(void)
{
	int arr[] = {1,2,3,4,5,8};
	int n = sizeof(arr)/sizeof(arr[0]);

	mergesort(arr,n);
        int i=0;
	for(i=0;i<n;i++)
	{
		cout<<arr[i]+" ";

	}

}
