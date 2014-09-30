#include<iostream>
#include<string>
using namespace std;

//class Base
//{
//public:
//	void f(int x)
//	{
//		cout << "Base::f(int) " << x << endl;
//	}
//	void f(float x)
//	{
//		cout << "Base::f(float) " << x << endl;
//	}
//	virtual void g(void)
//	{
//		cout << "Base::g(void)" << endl;
//	}
//};
//
//class Derived : public Base
//{
//public:
//	virtual void g(void) override
//	{
//		cout << "Derived::g(void)" << endl;
//	}
//};
//
//void virtualTest(void)
//{
//	Base b;
//	Derived d;
//	Base *pb = &d;
//	pb->f(42); // 运行结果: Base::f(int) 42
//	pb->f(3.14f); // 运行结果: Base::f(float) 3.14
//	d.Base::g(); // 运行结果: Derived::g(void)
//}

class B
{
public:
	B()
	{
		cout << "B constructor\n";
		s = "B";
	}
	void f()
	{
		cout << s;
	}
private:
	string s;
};

class D:public B
{
public:
	D() :B()
	{
		cout << "D constructor\n";
		s = "D";
	}
	void f()
	{
		cout << s;
	}
private:
	string s;
};

//void main()
//{
//	B* b = new D();
//	b->f(); 
//	((D*)b)->f();
//	delete b;
//}