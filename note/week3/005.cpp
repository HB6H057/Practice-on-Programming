成员对象和封闭类
成员对象:一个类的成员变量是另一个类的对象包含成员对象的类叫封闭类(Enclosing) 

#include <iostream>
using namespace std;

class CTyre {
private:
    int radius; //半径
	int width; //宽度
public:
	CTyre()
    {cout << "CTyre constructor" << endl; } //1
	CTyre(int r, int w):radius(r), width(w)
	{
		cout << "CTyre constructor123" << endl;  //为什么这个不会出现
	}
	~CTyre()
	{
		cout << "CTyre Destructor" << endl;	 //6
	}
};

class CEngine{ //引擎类

public:
	CEngine()
	{
		cout << "CEngine constructor" << endl; //2
	}
	~CEngine()
	{
		cout << "CEngine Destructor" << endl; //5
	}
};


class CCar{
private:
	int price; //价格
	CTyre tyre; 
	CEngine engine;
public:
	CCar();
	CCar(int p, int tr, int tw)
	{
		cout << "CCar constructor" << endl; //3
	}
	~CCar()
	{
		cout << "CCar Destructor" << endl; //4
	}
};

int main(){
	CCar car(20000, 17, 255);
	return 0;
}


如果CCar类不定义构造函数,则
CCarcar;// error 编译出错
•编译器不知道car.tyre该如何初始化
•car.engine的初始化没有问题:用默认构造函数

生成封闭类对象的语句->明确“对象中的成员对象”->如何初始化


封闭类构造函数的初始化列表
	定义封闭类的构造函数时,添加初始化列表:
类名::构造函数(参数表):成员变量1(参数表),成员变量2(参数表), ...
{
...
}
成员对象初始化列表中的参数
•任意复杂的表达式
•函数/变量/表达式中的函数,变量有定义


调用顺序
当封闭类对象生成时,
•S1:执行所有成员对象的构造函数
•S2:执行封闭类的构造函数

成员对象的构造函数调用顺序
•和成员对象在类中的说明顺序一致
•与在成员初始化列表中出现的顺序无关

当封闭类的对象消亡时,
•S1:先执行封闭类的析构函数
•S2:执行成员对象的析构函数

析构函数顺序和构造函数的调用顺序相反


