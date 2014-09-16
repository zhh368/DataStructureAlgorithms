//编写一个程序，实现排序算法，从小到大输出，数字间以逗号分隔，所有数字为非负整数。数目小于1028；
//两个逗号之间的字符，最多是‘0’-‘9’共10个;

#include<iostream>
#include<string>
#include<vector>
using namespace std;

//quick sort nums
int partition(vector<int>& elem, int lo, int hi)
{
	swap(elem[lo], elem[lo + rand() % (hi - lo + 1)]);
	int pivot = elem[lo];
	while (lo < hi)
	{
		while (lo<hi&&elem[hi] >= pivot) hi--;
		elem[lo] = elem[hi];
		while (lo<hi&&elem[lo] <= pivot) lo++;
		elem[hi] = elem[lo];
	}
	elem[lo] = pivot;
	return lo;
}

void qucikSort(vector<int>& elem, int lo, int hi)
{
	if (hi - lo < 2) return;
	int mid = partition(elem, lo, hi-1);
	qucikSort(elem, lo, mid);
	qucikSort(elem, mid, hi);
}

void main()
{
	//iutput by cin
	string str;
	getline(cin, str);

	//get char nums
	vector<string> vec;
	string::size_type pos;
	pos = str.find(',');
	string tempStr;
	if (pos != string::npos)
		tempStr.assign(str.begin(), str.begin() + pos);
	else
		tempStr.assign(str.begin(), str.end());
	vec.push_back(tempStr);
	while (pos != string::npos)
	{
		string::size_type prePos=pos;
		pos = str.find(',',pos+1);
		string sTemp;
		if (pos != string::npos)
		{
			sTemp.assign(str.begin() + prePos + 1, str.begin() + pos);
		}
		else
		{
			sTemp.assign(str.begin() + prePos + 1, str.end());
		}
		vec.push_back(sTemp);
	}

	//get int nums
	vector<int> nums(vec.size());
	for (int i = 0; i < vec.size(); ++i)
	{
		int iTemp=0;
		string sTemp = vec[i];
		for (int j = 0; j < sTemp.size(); ++j)
			iTemp = 10 * iTemp + sTemp[j] - '0';
		nums[i] = iTemp;
	}

	qucikSort(nums, 0, nums.size());

	for (int i = 0; i < nums.size(); ++i)
	{
		cout << nums[i] << "  ";
	}

	system("pause");
}