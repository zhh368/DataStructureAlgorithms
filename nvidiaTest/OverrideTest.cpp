#include<iostream>

using namespace std;

class AA
{
protected:
	int m_data;
public:
	AA(int data = 0)
	{
		m_data = data;
	}
	int GetData()
	{
		return doGetData();
	}
	virtual int doGetData()
	{
		return m_data;
	}
};

class BB:public AA
{
protected:
	int m_data;
public:
	BB(int data = 1)
	{
		m_data = data;
	}
	int doGetData()
	{
		return m_data;
	}
};

class CC :public BB
{
protected:
	int m_data;
public:
	CC(int data = 2)
	{
		m_data = data;
	}
};

void overrideTest()
{
	CC c(10);
	cout << c.GetData() << endl;
	cout << c.AA::GetData() << endl;
	cout << c.BB::GetData() << endl;
	cout << c.CC::GetData() << endl;
	cout << c.doGetData() << endl;
	cout << c.AA::doGetData() << endl;
	cout << c.BB::doGetData() << endl;
	cout << c.CC::doGetData() << endl;
}