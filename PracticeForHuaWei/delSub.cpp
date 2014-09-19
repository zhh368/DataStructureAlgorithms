#include<iostream>
#include<string>

using namespace std;

int delSub(string &str, const string &sub, int);

void delSub()
{
	string str, sub;
	getline(cin, str);
	getline(cin, sub);
	int n = sub.size();
	int num = delSub(str, sub, n);
	cout << num << endl;
	system("pause");
}

int delSub(string &str, const string &sub, int n)
{
	int m, flag = 0, num = 0;
	while (flag == 0)
	{
		m = str.find(sub);
		if (m < 0)
			return num;
		else
		{
			str.erase(m, n);
			num++;
		}
	}
}