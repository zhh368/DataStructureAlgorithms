#include<iostream>
#include <string>
using namespace std;


void PrintOrder(const string& pre, const string& ext)
{
	if (ext.length() == 1)
	{
		//�����׺ֻʣһ���ַ��������ǰ˳�򣬵ݹ����
		cout << pre << ext << endl;
	}
	else
	{
		//�����׺���ȴ���1��ÿ�ΰѺ�׺�е�һ���ַ���ӵ�ǰ׺�У��ݹ�
		for (unsigned int i = 0; i<ext.length(); i++)
		{
			PrintOrder(pre + ext.substr(i, 1), string(ext).erase(i, 1));
		}
	}
}
void TotalOrder(const string& orig)
{
	PrintOrder(string(""), orig);
}


void printPermutations(const char *str)
{
	char *str1 = const_cast<char*>(str);
	int len = strlen(str1);
	if (len <= 0) return;
	else
	{
		//Perm(str1, 0, len-1);
	}
}

void main()
{
	const char *str = "ABCD";
	printPermutations(str);
}