//求最大连续递增数字串(如“ads3sl456789DF3456ld345AA”中的“456789”)
#include <iostream>
#include <string>

using namespace std;

//求最大连续递增数字串
string FindMaxIncreNumberSeq(string str)
{
	if (str == "" || str.size() == 0)
		return NULL;
	int maxLen = 0;
	int start = -1;
	int count = 0;
	int pos = -1;
	bool isbegin = true;
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] >= '0'&&str[i] <= '9')
		{
			if (isbegin)
			{
				pos = i;
				isbegin = false;
				count = 1;
			}
			else if (str[i] - str[i - 1] == 1)
			{
				count++;
			}
			else
			{
				if (maxLen < count)
				{
					maxLen = count;
					start = pos;
				}
				pos = i;
				count = 1;
			}

			if (maxLen < count)
			{
				maxLen = count;
				start = pos;
			}
		}
		else
		{
			if (maxLen < count)
			{
				maxLen = count;
				start = pos;
			}
			isbegin = true;
		}
	}
	return str.substr(start, maxLen);
}

void main()
{
	string str = "23456789ads3sl456789DF012341234567893456ld345AA345678";
	cout << FindMaxIncreNumberSeq(str);

	system("pause");
}