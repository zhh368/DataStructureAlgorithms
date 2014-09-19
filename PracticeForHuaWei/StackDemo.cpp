#include<iostream>
#include<string>
#include<stack>
#include<unordered_map>
using namespace std;

void chpost(char inorder[], char post[], int& m)//将中缀表达式转换为后缀表达式，参数m跟踪后缀表达式长度
{
	m = 0;
	int n = strlen(inorder);//获取中缀表达式的长度
	stack<char> czf;//定义一个char型堆栈用于存放操作符;
	for (int i = 0; i<n; i++)
	{
		if (inorder[i] >= '0'&&inorder[i] <= '9')//若为操作数，直接添加到后缀表达式数组中
		{
			post[m] = inorder[i];
			m++;
		}
		if (inorder[i] == '(')
			czf.push(inorder[i]);//若为‘（’直接压入堆栈
		if (inorder[i] == '+')//若为‘+’与栈顶比较优先级，较低则将栈顶操作符加到数组中，在将‘+’压栈
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
		if (inorder[i] == '-')//若为‘-’与栈顶比较优先级，较低则将栈顶操作符加到数组中，将‘-’压栈
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
			czf.push(inorder[i]);//若为‘*’或‘/’直接压栈
		if (inorder[i] == ')')//若遇到‘）’将栈中的操作符依次弹出直到遇到‘（’结束
		{
			while (czf.top() != '(')
			{
				post[m++] = czf.top();
				czf.pop();
			}
			czf.pop();//弹出‘（’
		}
	}
	while (!czf.empty())//将栈中剩余元素依次弹出到后缀表达式数组中
	{
		post[m++] = czf.top();
		czf.pop();
	}
}

int yunsuan(char post[], int n)//通过后缀表达式求值
{
	stack<int>ss;//定义int型堆栈存放操作数及每次运算结果
	int a, b, c, result;
	for (int i = 0; i<n; i++)
	{
		if (post[i] >= '0'&&post[i] <= '9')
		{
			ss.push((post[i] - '0'));//将char型转为int型
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
	result = ss.top();//得到最后栈顶元素
	ss.pop();//清空栈
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
