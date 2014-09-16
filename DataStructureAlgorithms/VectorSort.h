#include<iostream>
#include<vector>
#include<string>

using namespace std;

typedef int Rank;

class VectorSort
{
public:
	VectorSort();
	~VectorSort();
	void QuickSort(vector<int>& elem, Rank lo, Rank hi);
	void MergeSort(vector<int>& elem, Rank lo, Rank hi);
	void SelectSort(vector<int>& elem, Rank lo, Rank hi);
	void BubbleSort(vector<int>& elem, Rank lo, Rank hi);
	void InsertSort(vector<int>& elem, Rank lo, Rank hi);
private:
	Rank partition(vector<int>& elem, Rank lo, Rank hi);
	void merge(vector<int>& elem, Rank lo, Rank mid, Rank hi);
};

