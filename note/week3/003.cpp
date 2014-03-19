/*
析构函数是成员函数的一种
•名字与类名相同
•在前面加‘~’
•没有参数和返回值
•一个类最多只有一个析构函数


对象消亡时->自动被调用
•在对象消亡前做善后工作
    •释放分配的空间等

定义类时没写析构函数,则编译器生成缺省析构函数
•不涉及释放用户申请的内存释放等清理工作

定义了析构函数,则编译器不生成缺省析构函数


析构函数和数组
对象数组生命期结束时，对象数组的每个元素的析构函数都会被调用
*/

#include <iostream>
using namespace std;

class String {
public:
	char *str;
	String (){  //构造函数
		cout << "Constructor called" << endl;
		str = new char[10];
	}

	~String(){  //析构函数
		cout << "Destructor called" << endl;
		delete []str;
	}

};

int main(void)
{
	String * c1;
	String c2[2];
	c1 = new String; //构造函数被调用
	delete c1 ; //析构函数被调用
	cout << "-------MAIN-END--------" << endl;
	return 0;
	
	//析构函数被调用两次，因为c2[0]、C2[1]随程序结束被销毁
}




构造函数和析构函数在不同编译器中的表现

各别调用情况不一致
•编译器有bug
•代码优化措施

前面讨论的是C++标准