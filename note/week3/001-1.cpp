/*形式: X::X( X& )或X::X(const X &) 后者能以常量对象作为参数
如果没有定义复制构造函数，那么编译器生成默认复制构造函数。默认的复制构造函数完成复制功能。
*/
#include <iostream>
using namespace std;

class Complex
{
public:
    double real, imag;	
    Complex() {}
	Complex(Complex & a1) //复制构造函数
	{
		real = a1.real;
		imag = a1.imag;
		cout << "Copy Constructor" << endl;
	}
};

Complex f(Complex a)
{
    cout << "fun" <<endl;
	/*3.如果函数的返回值是类A的对象时，则函数返回时，A的复制构造函数被调用	*/
	return a;
}

int main(void)
{
	Complex c1; //调用缺省无参构造函数

	/*1.当用一个对象去初始化同类的另一个对象时*/
	Complex c2(c1); //等同于 Complex c2 = c1;
    
    cout << "main" <<endl;
    
	/*2.如果某函数有一个参数是类A的对象，
	那么该函数被调用时，类A的复制构造函数将被调用,去初始化形参*/
	f(c1); 

	return 0;
}

/*
Copy Constructor
main
Copy Constructor
fun
Copy Constructor
*/