基本概念
	静态成员：在说明前面加了static关键字的成员.
普通成员变量每个对象有各自的一份，而静态成员变量一共就一份，为所有对象共享。
	sizeof 运算符不会计算静态成员变量

普通成员函数必须具体作用于某个对象，而静态成员函数并不具体作用与某个对象。

因此静态成员不需要通过对象就能访问。


如何访问静态成员

	1)类名::成员名
		CRectangle::PrintTotal();
	2)对象名.成员名
		CRectangle r; r.PrintTotal(); //但不具体属于对象r上
	3)指针->成员名
		CRectangle * p = &r;p->PrintTotal();
	4)引用.成员名
		CRectangle & ref = r; int n = ref.nTotalNumber; 


设置静态成员这种机制的目的是将和某些类紧密相关的全局变量和函数写到类里面，看上去像一个整体，易于维护和理解。

注意：在静态成员函数中，不能访问非静态成员变量，也不能调用非静态成员函数。

#include <iostream>
using namespace std;

class CRectangle{
private:
    int w, h;
	static int nTotalArea;
	static int nTotalNumber; 
	//私有静态成员变量，不仅共享而且仅有该类型对象能访问，棒！！
public:
	CRectangle(int w_, int h_); //构造函数
	~CRectangle(); //析构函数
	CRectangle(CRectangle &r); //复制构造函数
	static void PrintTotal(void);//静态成员函数
};

CRectangle::CRectangle(int w_, int h_)
{
	w = w_;
	h = h_;
	nTotalNumber++;
	nTotalArea += w * h;
}

CRectangle::~CRectangle()
{
	nTotalArea -= w * h;
	nTotalNumber--;
}
/*防止调用了复制构造函数，销毁时调用析构函数减少了总数*/
CRectangle::CRectangle( CRectangle & r )
{
	w = r.w; h = r.h;
	nTotalNumber ++;
	nTotalArea += w * h;
}

void CRectangle::PrintTotal(void)
{
	cout << "TotalArea:" << nTotalArea << ", ";
	cout << "nTotalNumber" << nTotalNumber << endl;
	//cout << w << endl;  
	//在静态成员函数中，不能访问非静态成员变量，也不能调用非静态成员函数。
}

//必须在定义类的文件中对静态成员变量进行一次说明
//或初始化。否则编译能通过，链接不能通过
int CRectangle::nTotalNumber = 0;
int CRectangle::nTotalArea = 0;

int main()
{
	CRectangle r1(3,3), r2(2,2);
	//cout << CRectangle::nTotalNumber;
	// Wrong ,私有
	CRectangle::PrintTotal();
	r1.PrintTotal();
	return 0;
}

/*
TotalArea:13, nTotalNumber2
TotalArea:13, nTotalNumber2
*/