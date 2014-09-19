#include<iostream>
#include<vector>
#include<string>

using namespace std;
int cmp(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}
void qsortDemo()
{
	int nums[10] = {36,56,12,25,54,75,45,35,79,24};
	qsort(nums, 10, sizeof(int), cmp);

}