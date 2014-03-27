##运算符

C++预定义表示对数据的运算只能用于基本的数据类型
	•整型,实型,字符型,逻辑型......

##自定义数据类型与运算符重载

C++提供了数据抽象的手段:
用户自己定义数据类型--类
	•调用类的成员函数

操作它的对象类的成员函数操作对象时,很不方便
	•在数学上,两个复数可以直接进行+/-等运算
	Vs.在C++中,直接将+或-用于复数是不允许的

##运算符重载

对抽象数据类型也能够直接使用C++提供的运算符
	•程序更简洁
	•代码更容易理解

运算符重载
•对已有的运算符赋予多重的含义
•使同一运算符作用于不同类型的数据时->不同类型的行为

目的
•扩展C++中提供的运算符的适用范围,以用于类所表示的抽象数据类型

运算符重载的实质是函数重载返回值类型
operator 运算符（形参表）
{
	......
}

在程序编译时:
	•把含运算符的表达式->对运算符函数的调用
	•把运算符的操作数->运算符函数的参数
	•运算符被多次重载时,根据实参的类型决定调用哪个运算符函数
	•运算符可以被重载成普通函数
		重载为普通函数时,参数个数为运算符目数
	•也可以被重载成类的成员函数:
		重载为成员函数时,参数个数为运算符目数减一

#include <iostream>
using namespace std;

class Complex
{
public:
    double real, imag;
    
    Complex( double real_, double imag_ ):real(real_), imag(imag_){}
    Complex(  ):real(0), imag(0){}

    Complex operator + (const Complex & a) //运算符重载为成员函数
    {
        return Complex(real + a.real, imag + a.imag);   
    }
};

Complex operator - (Complex & a, Complex & b) //运算符重载为普通函数
{
    return Complex(a.real - b.real, a.imag - b.imag);    
}

int main(void)
{
    Complex a(10, 20), b(30, 40), c;
    c = a + b;
    cout << c.real << "," << c.imag << endl;
    // 40,60
    c = b - a;
    cout << c.real << "," << c.imag << endl;
    //20,20
    return 0;
}