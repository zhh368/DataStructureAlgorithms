#include<iostream>
#include<string>

using namespace std;

void arrayCompare()
{
	int len1, len2;
	cin >> len1;
	int *array1 = new int[len1];
	for (int i = 0; i < len1; i++)
	{
		cin >> array1[i];
	}
	system("pause");
}