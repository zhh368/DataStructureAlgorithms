#include<iostream>
using namespace std;
void hh()
{
	char *pb = new char[100];
	unsigned int pp = (unsigned int)pb;
	//unsigned int pp = reinterpret_cast<unsigned int>(pb);
	
	cout << pb << endl;
	cout << pp;
	system("pause");
}

int test3(int argc, char** argv)
{
	int x = 1;
	int y = 0;
	int const *p=&x;
	p++;
	if (x++ || y++)
	{
		y += 2;
	}

	std::cout << x + y << std::endl;

	system("pause");
	return 0;
}
