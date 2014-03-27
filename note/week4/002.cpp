##赋值运算符‘=’重载

赋值运算符两边的类型可以不匹配
	•把一个int类型变量赋值给一个Complex对象
	•把一个char *类型的字符串赋值给一个字符串对象
	需要重载赋值运算符‘=’
	赋值运算符“=”只能重载为成员函数
#include <string.h>
#include <iostream>
using namespace std;

class String
{
private:
    char * str;
public:
    String():str(NULL){} //初始化
    const char * c_str(void){ return str; } //返回用于显示
    char * operator = ( const char * s ); // = 重载
    ~String(); //析构函数
};

char * String::operator = (const char *s)
{
    if (str) 
        delete []str; //已存在内容则释放
    
    if (s) //s不为空时才复制
    {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
    else
    {
        str = NULL;    
    }
    return str;
} 
String::~String()  //析构函数
{
    if (str)
        delete []str;
}

int main(void)
{
    String s;
    s = "operator123";
    cout << s.c_str() << endl;
    //String s = "123" 错了 这里的 = 是初始化
    return 0;
}

深浅拷贝 （略）