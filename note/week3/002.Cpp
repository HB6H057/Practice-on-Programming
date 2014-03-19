/*
目的
•实现类型的自动转换

特点
•只有一个参数
•不是复制构造函数

编译系统会自动调用->转换构造函数->建立一个临时对象/临时变量  
*/

#include <iostream>
using namespace std;

class Complex {
public:
	double real, imag;
	Complex(){}
	Complex(int i)
	{
		real = i;
		imag = 0;
		cout << "IntConstructor called" << endl;
	}

};

int main(void)
{

	Complex c1 = 12; //不会生成临时对象
	cout << c1.real << ", " << c1.imag << endl;
	c1 = 20; // 9被自动转换成一个临时Complex对象
	cout << c1.real << ", " << c1.imag << endl;
	return 0;
}

/*
IntConstructor called
12, 0
IntConstructor called
20, 0
*/