#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

Node* reverseList(Node* head)
{
	Node *p1 = NULL;
	Node *p2 = NULL;
	Node *p3 = NULL;
	if (head == NULL || head->next == NULL)
		return head;
	p1 = head;
	p2 = p1->next;
	while (p2)
	{
		p3 = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p3;
	}
	head->next = NULL;
	head = p1;
	return head;
}

int reverseListMain()
{
	int temp;
	Node *head = NULL;
	Node *curr = NULL;
	while (cin >> temp)
	{
		Node *p = new Node();
		p->data = temp;
		if (head == NULL)
		{
			head = p;
			curr = p;
		}
		else
		{
			curr->next = p;
			curr = p;
		}
	}
	Node *newHead = reverseList(head);
	curr = newHead;
	while (curr)
	{
		cout << curr->data << " ";
		curr = curr->next;
	}
	system("pause");
	return 0;
}