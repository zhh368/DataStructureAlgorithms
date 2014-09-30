#include<iostream>

using namespace std;

void printArray(char* source, char* dest, int *printArr, int sLen, int dLen, int printArrNum, int sStartNum, int dStartNum)
{
	int sstartNum = sStartNum;
	int dstartNum = dStartNum;
	int printNum = printArrNum;
	
	if (printNum == dLen)
	{
		for (int i = 0; i < dLen; ++i)
		{
			cout << *(printArr + i);
			cout << " ";
		}
		cout << endl;
		return;
	}

	for (int i = sstartNum; i < sLen; ++i)
	{
		for (int j = dstartNum; j < dLen; ++j)
		{
			if (*(source + i) == *(dest + j))
			{
				printArr[printNum] = i + 1;
				sstartNum = i;
				dstartNum = j;
				printArray(source, dest, printArr, sLen, dLen, printNum + 1, sstartNum+1, dstartNum+1);
			}
		}
	}
}

void connectSequence(char* source, char* dest)
{
	if (source == NULL || dest == NULL) return;
	int sLen = strlen(source);
	int dLen = strlen(dest);
	int *printArr = new int[dLen];
	if (printArr == NULL) return;
	printArray(source, dest, printArr, sLen, dLen, 0, 0, 0);
}

void connectSequenceMain()
{
	char source[] = "abdbcc";
	char dest[] = "abc";
	connectSequence(source, dest);
	system("pause");
}