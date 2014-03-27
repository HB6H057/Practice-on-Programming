/*
this 指针的作用：指向成员函数所作用的对象
*/

#include <iostream>
using namespace std;

calss Complex {
public:
	double real, imag;
	void Print(){ cout << real << ", " << imag << endl};
	Complex (double r, double i):real(r), imag(i){}
	Complex AddOne(void)
	{
		this->real++;
		this->Print(); //用到了this指针
		return * this;
	}
};

int main(void)
{
	Complex c1(1, 1), c2(0, 0);
	c2 = c1.AddOne(); 
	return 0;
}

/*
	为什么不会出错？
	因为void Hello(){ cout << "hello" << endl; };会被翻译为
	void Hello(Complex * this){ cout << "hello" << endl; };
	而Hello中并没有用到this，所以不会出错。
	如果void Hello(){ cout << "hello" << endl; };改成
	void Hello(){ cout << i <<"hello" << endl; };就会报错，因为this为NULL，没有i值。

*/
#include <iostream>
using namespace std;

class Complex 
{
	int i;
public:
	void Hello(){ cout << "hello" << endl; };
};

int main(void)
{
	Complex * p = NULL;
	p->Hello(); //为什么不会出错？
	return 0;
}

