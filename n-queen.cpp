//N Queens Problem

#include<iostream>
using namespace std;

int n;
int q[101][101];

bool isSafe(int r, int i)
{
	int j;
	if(r == 0)
		return 1;
	if(r>0 && r<n && i>=0 && i<n)
	{
		for(j=r-1;j>=0;j--)
		{
			if((i>0 && q[j][i-(r-j)]) || q[j][i] || q[j][i+(r-j)])
				return 0;
		}
		return 1;
	}
	return 0;
}

bool nqueen(int r)
{
	if(r == n)
		return 1;
	int i;
	for(i=0;i<n;i++)	//for each cell in a row
	{
		if(isSafe(r,i))
		{
			q[r][i] = 1;
			if(nqueen(r+1))
				return 1;
			else
				q[r][i] = 0;
		}
	}
	return 0;
}

void print()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<q[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	cout<<"Enter number of queens!";
	cin>>n;
	int i, j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			q[i][j] = 0;
		}
	}
	if(nqueen(0))
		print();
	else
		cout<<"Queens gonna attack!";
	return 0;
}