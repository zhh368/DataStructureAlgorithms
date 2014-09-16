#include"VectorSort.h"

VectorSort::VectorSort()
{
}

VectorSort::~VectorSort()
{
}

Rank VectorSort::partition(vector<int>& elem, Rank lo, Rank hi)
{
	swap(elem[lo], elem[lo + rand() % (hi - lo + 1)]);
	int pivot = elem[lo];
	while (lo<hi)
	{
		while ((lo < hi) && (pivot <= elem[hi]))
			hi--;
		elem[lo] = elem[hi];
		while ((lo<hi) && (pivot>=elem[lo]))
			lo++;
		elem[hi] = elem[lo];
	}
	elem[lo] = pivot;
	return lo;
}

void VectorSort::QuickSort(vector<int>& elem, Rank lo, Rank hi)//quick sort [lo,hi-1]
{
	if (hi - lo < 2) return;
	Rank mid = partition(elem, lo, hi - 1);
	QuickSort(elem, lo, mid);//mid is in the right position, sort [lo,mid-1]
	QuickSort(elem, mid+1, hi);
}

void VectorSort::merge(vector<int>& elem, Rank lo, Rank mid, Rank hi)
{
	//vector<int> temp(mid - lo);
	//for (int n = 0; n < temp.size(); ++n)
	//	temp[n] = elem[lo + n];
	//Rank i = 0, j = mid, k = lo;
	//for (; i < mid - lo||j < hi;)
	//{
	//	if (i<mid - lo&&(!(j<hi)||temp[i] <= elem[j])) elem[k++] = temp[i++];
	//	if (j < hi && (!(i<mid-lo) || elem[j] < temp[i])) elem[k++] = elem[j++];
	//}
	vector<int> temp(mid - lo);
	for (int n = 0; n < temp.size(); ++n)
		temp[n] = elem[lo + n];
	Rank i = 0, j = mid, k = lo;
	while (i < mid - lo && j < hi)
	{
		while (i<mid - lo && temp[i] <= elem[j]) elem[k++] = temp[i++];
		if (i >= mid - lo) return;
		while (j < hi && elem[j] <= temp[i]) elem[k++] = elem[j++];
	}
	while (i<mid - lo) elem[k++] = temp[i++];
}

void VectorSort::MergeSort(vector<int>& elem, Rank lo, Rank hi)
{
	if (hi - lo < 2) return;
	int mid = (hi + lo) >> 1;
	MergeSort(elem, lo, mid);
	MergeSort(elem, mid, hi);
	merge(elem, lo, mid, hi);
}

void VectorSort::SelectSort(vector<int>& elem, Rank lo, Rank hi)
{
	for (Rank k = hi - 1; k > lo; k--)
	{
		Rank max = 0;
		for (Rank i = 0; i <= k; i++)
			if (elem[i] > elem[max]) max = i;
		swap(elem[max], elem[k]);
	}
}

void VectorSort::BubbleSort(vector<int>& elem, Rank lo, Rank hi)
{
	for (Rank k = hi - 1; k > lo; k--)
	{
		bool sorted = true;
		for (Rank i = 0; i < k; i++)
			if (elem[i] > elem[i + 1])
			{
				sorted = false;
				swap(elem[i], elem[i+1]);
			}
		if (sorted)
			return;
	}
}

void VectorSort::InsertSort(vector<int>& elem, Rank lo, Rank hi)
{
	for (Rank i = lo + 1; i < hi; ++i)
	{
		Rank j;
		int temp = elem[i];
		for (j = i; j>lo && temp < elem[j-1]; j--)
			elem[j] = elem[j - 1];
		elem[j] = temp;
	}
}