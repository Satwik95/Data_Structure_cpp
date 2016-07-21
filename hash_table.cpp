/*
	Implementation of hash table using c++
*/

#include<iostream>
#include<string>
#define size 101
using namespace std;

class hash
{
private:
	struct item
	{
		string name;
		int age;
		item* next;
	};

	item* hashtable[size];

public:
	hash()
	{
		for(int i=0;i<size;i++)
		{
			hashtable[i] = new item;
			hashtable[i]->name = "Empty";
			hashtable[i]->age = 0;
			hashtable[i]->next = NULL;
		}
	}
	int Hash(string key)
	{
		int sum = 0;

		for(int i=0;i<key.length();i++)
		{
			sum+=(int)key[i];
		}

		int index = sum%size;

		return index;
	}

	void additem(string name,int age)
	{
		int index = Hash(name);

		//now that we have the head index of the hash table
		// we can add nodes to this list 

		item* temp = new item;
		
		if(hashtable[index]->next == null)
		{
			hashtable[index]->name = name;
			hashtable[index]->age = age;
			hashtable[index]->next = null;
		}

    	temp->next = hashtable[index]->next;
		hashtable[index]->next = temp;
		temp->name = name;
		temp->age = age;
	}

	int countItems(int index)
	{
		item* cur = hashtable[index]->next;
		int count = 0;

		if(hashtable[index]->next == null)
		{
			return count;
		}
		else
		{
			while(cur!=null)
			{
				count++;
				cur = cur->next;
			}
		}
		return count+1;
	}

	// we can implement search an deletion similarly using the logic if linked list
};

int main()
{
	string key = "Satwik";

	hash k;
	int index = k.Hash(key);
	cout<<index;

	return 0;
}