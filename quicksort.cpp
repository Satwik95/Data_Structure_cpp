/* C++ implementation of quicksort using divide and conquer O(nlogn)
Author: Satwik Mishra */

#include<iostream>
#include<stdio.h>


using namespace std;

int partition(int* a,int start,int end)
{
	int pindex = start;
	int pivot = a[end];

	for(int i = start;i<end;i++)
	{
		if(a[i]<=pivot)
		{
			int k = a[i];
			a[i] = a[pindex];
			a[pindex] = k;
			pindex++;
		}
	}

			int k = a[end];
			a[end] = a[pindex];
			a[pindex] = k;

		return pindex;

}

void quicksort(int* a,int start,int end)
{
	if(start<end)
	{
		int pindex = partition(a,start,end);
		quicksort(a,start,pindex-1);
		quicksort(a,pindex+1,end);
	}
}

int main()
{
	int a[] = {8,6,4,6,4,5,2,1};
	quicksort(a,0,7);

	for(int i=0;i<8;i++)
	{
		cout<<a[i]<<endl;
	}

	return 0;
}