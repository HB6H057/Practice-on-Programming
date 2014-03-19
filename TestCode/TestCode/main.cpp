#include <iostream>
using namespace std;

class Complex {
public:
	int real;
	int imag;

	Complex(void){
	
		real = 0;
		imag = 0;
	}

	Complex(int real_, int imag_) {
	
		real = real_;
		imag = imag_;
	}
	/*
		��Ա������ֻ��һ������
	*/	
	Complex operator + (const Complex & a)
	{
		return Complex(real + a.real, imag + a.imag);
	}
};




int main(void)
{
	cout << "helloWorld" << endl;
	Complex c1(1,1);
	Complex c2(2,2);
	Complex c3;

	c3 = c1 + c2;

	cout << c3.imag << endl;

	return 0;
}