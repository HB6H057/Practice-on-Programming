#include <iostream>
#include <string.h>
using namespace std;

class String;


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

class String
{
private:
    char * str1;
    char * str2;
public:
    char str[101];
};

String String::operator + (const char * str1_, const char * str2_)
{
    int flag = 0;

    if (str1) delete [] str1;
    if (str2) delete [] str2; //初始化 以免出错

    str1 = new char[ len( str1_ ) + 1 ];
    str2 = new char[ len( str2_ ) + 1 ];
    strcpy(str1, str1_);
    strcpy(str2, str2_); //拷贝进来

    if (len( str1_ ) >= len( str2_ ) ) //如果第一个数比第二个数位数多（或相等）的时候
    {
        for (int i = 0; i < len( str1_ ); i++)
        {
        	str[i] = ( str1_[i] + str2_[i] + flag - 0x60) \
        	  			% 10) + 0x30;   //取第i位数 
        	flag = ( str1_[i] + str2_[i] + flag ) / 10; //取进位数
        }
        

    }
    else //如果第二个比第一个数位数多
    {

    }


}
String String::operator - (const char * str1_, const char * str2_)
{

}
String String::operator * (const char * str1_, const char * str2_)
{

}
String String::operator / (const char * str1_, const char * str2_)
{

}


