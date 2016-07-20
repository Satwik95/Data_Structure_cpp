//N Queens Problem

#include<iostream>
#include<bits/stdc++.h>
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
		for(j=r-1;j>=0;j--)   //j=r-1 because we need to start checking with the prvious row as we called isSafe(r+1)
		{
			if((i>0 &&   q[j][i-(r-j)])  ||   q[j][i] ||      q[j][i+(r-j)])   //check in six direction
						//first diagonal     //same column  //second diagonal
				return 0;
		}
		return 1;
	}
	return 0;
}

bool nqueen(int r)
{
	if(r == n)   //r stands for row
		return 1;
	int i;
	for(i=0;i<n;i++)	//for each cell in a row
	{
		if(isSafe(r,i))
		{
			q[r][i] = 1;
			if(nqueen(r+1))  //recursive call for the next n rows
				return 1;	 // if next row is being attacked for the given co-ordinate then return false 
			else
				q[r][i] = 0;   //set the previous allocated position as 0 and go to the next cell
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

	memset(q,0,sizeof(q));

	if(nqueen(0))
		print();
	else
		cout<<"Queens gonna attack!";
	return 0;
}