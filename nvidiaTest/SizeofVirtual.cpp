#include<iostream>

using namespace std;

class AAA
{
	char k[3];
public:
	virtual void aa(){};
};

class BBB :public AAA
{
	char j[3];
public:
	virtual void bb(){};
};

class CCC :public BBB
{
	char i[3];
public:
	virtual void cc(){};
};

void main()
{
	cout << sizeof(AAA) << endl;
	cout << sizeof(BBB) << endl;
	cout << sizeof(CCC) << endl;
	int a = 4;
	a=a >> 1;
	cout << a << endl;
	cout << sizeof(unsigned int) * 8 << endl;
	printf("%f", 5);
	cout << endl;
	printf("%d", 5.0);
}