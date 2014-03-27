友元
	友元函数:一个类的友元函数可以访问该类的私有成员.
	友元类:A是B的友元类A的成员函数可以访问B的私有成员.

#include "iostream"
using namespace std;
class c3;
class c1{
private:
    int dat;
public:
	c1()
	{
		dat = 1;
	}
	friend c3; //友元类
};

class c2{
private:
	int water;
public:
	c2()
	{
		water = 2;
	}
	friend void c3::Print1(void); //友元函数
};


class c3{
public:
	void Print1(void)
	{
		cout << c2.water << endl;
		cout << c1.dat << endl; //可以调用
	}
	void Print2(void)
	{
		cout << c1.dat << endl; 
		//cout << c2.water << endl;
	}
};


int main(void)
{

    return 0;
}



Note:友元类之间的关系不能传递,不能继承