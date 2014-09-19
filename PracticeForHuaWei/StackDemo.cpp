#include<iostream>
#include<string>
#include<stack>
#include<unordered_map>
using namespace std;

void chpost(char inorder[], char post[], int& m)//����׺���ʽת��Ϊ��׺���ʽ������m���ٺ�׺���ʽ����
{
	m = 0;
	int n = strlen(inorder);//��ȡ��׺���ʽ�ĳ���
	stack<char> czf;//����һ��char�Ͷ�ջ���ڴ�Ų�����;
	for (int i = 0; i<n; i++)
	{
		if (inorder[i] >= '0'&&inorder[i] <= '9')//��Ϊ��������ֱ����ӵ���׺���ʽ������
		{
			post[m] = inorder[i];
			m++;
		}
		if (inorder[i] == '(')
			czf.push(inorder[i]);//��Ϊ������ֱ��ѹ���ջ
		if (inorder[i] == '+')//��Ϊ��+����ջ���Ƚ����ȼ����ϵ���ջ���������ӵ������У��ڽ���+��ѹջ
		{
			if (!czf.empty() && (czf.top() == '*' || czf.top() == '/' || czf.top() == '-'))
			{
				post[m++] = czf.top(); 
				czf.pop(); 
				czf.push(inorder[i]);
			}
			else
			{ 
				czf.push(inorder[i]);
			}
		}
		if (inorder[i] == '-')//��Ϊ��-����ջ���Ƚ����ȼ����ϵ���ջ���������ӵ������У�����-��ѹջ
		{
			if (!czf.empty() && (czf.top() == '*' || czf.top() == '/'))
			{
				post[m++] = czf.top();
				czf.pop();
				czf.push(inorder[i]);
			}
			else{ czf.push(inorder[i]); }
		}
		if (inorder[i] == '*' || inorder[i] == '/')
			czf.push(inorder[i]);//��Ϊ��*����/��ֱ��ѹջ
		if (inorder[i] == ')')//��������������ջ�еĲ��������ε���ֱ����������������
		{
			while (czf.top() != '(')
			{
				post[m++] = czf.top();
				czf.pop();
			}
			czf.pop();//����������
		}
	}
	while (!czf.empty())//��ջ��ʣ��Ԫ�����ε�������׺���ʽ������
	{
		post[m++] = czf.top();
		czf.pop();
	}
}

int yunsuan(char post[], int n)//ͨ����׺���ʽ��ֵ
{
	stack<int>ss;//����int�Ͷ�ջ��Ų�������ÿ��������
	int a, b, c, result;
	for (int i = 0; i<n; i++)
	{
		if (post[i] >= '0'&&post[i] <= '9')
		{
			ss.push((post[i] - '0'));//��char��תΪint��
		}

		if (post[i] == '-')
		{
			b = ss.top(); ss.pop(); a = ss.top(); ss.pop();
			c = a - b; ss.push(c);
		}
		if (post[i] == '+')
		{
			b = ss.top(); ss.pop(); a = ss.top(); ss.pop();
			c = a + b; ss.push(c);
		}
		if (post[i] == '*')
		{
			b = ss.top(); ss.pop(); a = ss.top(); ss.pop();
			c = a*b; ss.push(c);
		}
		if (post[i] == '/')
		{
			b = ss.top(); ss.pop(); a = ss.top(); ss.pop();
			c = a / b; ss.push(c);
		}
	}
	result = ss.top();//�õ����ջ��Ԫ��
	ss.pop();//���ջ
	return result;
}

void stackExpression()
{
	int m;
	char post[100];
	char express[] = "1+4*(5-8)/3";
	chpost(express, post, m);
	int temp = yunsuan(post, m);
	cout << temp << endl;
	system("pause");
}
