#include"VectorSort.h"

void main()
{
	vector<int> A(5);
	A[0] = 1;
	A[1] = -1;
	A[2] = 2;
	A[3] = -2;
	A[4] = 10;
	VectorSort vectorSort;
	vectorSort.MergeSort(A, 0, A.size());
	//quickSort(A,0,A.size());
	for (int i = 0; i<A.size(); ++i)
		cout << A[i] << endl;
	system("pause");
}