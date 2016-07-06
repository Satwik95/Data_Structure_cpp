#include<iostream>
#include<stdio.h>
using namespace std;

class node {
	int data;
	node *next;
	node *head, *tail;

public:

	node()

	{
		head = NULL;
		tail = NULL;

	}

	node* insert(node* p);
	node* disp(node* temp);
	void add_node(node* l1, node* l2,node* l3,int carry);
	node* insert_add(node* p, int val);


};

void node::add_node(node* first, node* second,node* third,int carry)
{
	int val1 = first->data;
	int val2 = second->data;
	if (first == NULL && second == NULL)
	{
		return;
	}
	if (first == NULL)
		val1= 0;

	if (second == NULL)
		val2 = 0;

	int sum = first->data + second->data + carry;
	carry = sum / 10;
	int val = sum % 10;

	third = insert_add(third,val);
	add_node(first->next, second->next,third,carry);
}
node* node::insert_add(node* p,int val)

{
	p = head;
	node *temp = new node;
	temp->next = NULL;
	temp->data = val;
		if (head != NULL && tail != NULL)
	{
		tail->next = temp;
		tail = temp;
		return p;

	}

	else
	{
		tail = head = temp;
		return p;
	}
}

node* node::insert(node* p)

{
	p = head;
	node *temp = new node;
	temp->next = NULL;
	cout << "enter value" << endl;
	cin >> temp->data;
	if (head != NULL && tail != NULL)
	{
		tail->next = temp;
		tail = temp;
		return p;

	}

	else
	{
		tail = head = temp;
		return p;
	}
}

node* node::disp(node* temp)

{
	temp = head;
	if (temp == NULL)
		cout << "empty!" << endl;
	while (temp != NULL)
	{
		cout << temp->data << "\t";
		temp = temp->next;
	}
	return head;

}

int main()

{
	node l1; //list 1
	node l2; //list 2
	node l3; //list 3
	node* first = NULL;
	node* third = NULL;
	node* second = NULL;
	int ch, n;
	cout << "enter no. of elements for list 1:-" << endl;
	cin >> n;

	for (int i = 0; i<n; i++)

	{
		first = l1.insert(first);
	}

	cout << "enter no. of elements for list 2:-" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)

	{
		second = l2.insert(second);
	}
	l3.add_node(first, second,third,0);

	third = l3.disp(third);




	system("pause");
}
