#include<iostream>
#include<string>
#include<vector>
using namespace std;

void stringChang(char* input, char* output)
{
	int m = strlen(input);
	int i;
	for (i = 0; i < m; i++)
	{
		if (isalpha(input[i]))
		{
			if (input[i] == 'Z')
				output[i] = 'A';
			else if (input[i] == 'z')
				output[i] = 'a';
			else
				output[i] = input[i] + 1;
		}
		else
			output[i] = input[i];
	}
	output[i] = '\0';
}

int same(long long num)
{
	vector<int> nums;
	while (num > 0)
	{
		nums.push_back(num % 10);
		num /= 10;
	}

	if (nums.size() < 4)
	{
		return 0;
	}

	for (int i = 0; i < nums.size()-3; ++i)
	{
		for (int j = i + 2; j < nums.size()-1; ++j)
		{
			if (nums[j] == nums[i] && nums[j+1] == nums[i+1])
			{
				return 1;
			}
		}
	}
	return 0;
}

//void main()
//{
//	//char input[100], output[100];
//	//cin.getline(input, 100);
//	//stringChang(input, output);
//	long long input;
//	cin>>input;
//	int i = same(input);
//	cout << i;
//	system("pause");
//}