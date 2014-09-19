#include<iostream>

using namespace std;

struct node
{
	int num;
	node *next;
};

node *create(int n)
{
	node *p = NULL, *q = NULL, *head = NULL;
	for (int i = 1; i <= n; ++i)
	{
		p = new node;
		p->num = i;
		if (head == NULL)
			head = p;
		else
			q->next = p;
		q = p;
	}
	p->next = head;
	return p;
}

void Josephus()
{
	int k, n, m;
	cin >> n >> k >> m;
	node *l, *q;
	l = create(n);
	q = l;
	l = l->next;
	for (int i = 1; i < k; i++)
	{
		q = l;
		l = l->next;
	}
	while (l->next != l)
	{
		for (int i = 1; i < m; i++)
		{
			q = l;
			l = l->next;
		}
		cout << l->num << "->";
		q->next = l->next;
		delete l;
		l = q->next;
	}
	cout << l->num << endl;
	delete l;
	system("pause");
}