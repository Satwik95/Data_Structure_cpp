#include<iostream>

using namespace std;
int heapsize = 0;

void swap(int &a,int &b)
{
	a^=b;
	b^=a;
	a^=b;
}
class heap{

public:

	void max_heapify(int a[],int i)
{
	int l = 2*i;
	int r = (2*i)+1;
	int largest;

	if(l<=heapsize && a[l]>a[i])
	{
		largest = l;
	}
	else largest = i;

	if(r>=heapsize && a[r]>a[largest])
	{
		largest = r;
	}
	if(largest!=i)
	{
		swap(largest,i);
	}
	max_heapify(a,largest);


}
void build_max_heap(int a[])
{

	int start = ((heapsize-1)/2) + 1;

	for(int i=start-1;i>=0;i--)
	{
		max_heapify(a,i);
	}
}

};


int main()
{
	int a[] = {1,3,4,2,7,6};
	heapsize = sizeof(a)/sizeof(a[0]);
	heap h;
	h.build_max_heap(a);

	for(int i=0;i<heapsize;i++)
	{
		cout<<a[i]<<" ";
	}
}
