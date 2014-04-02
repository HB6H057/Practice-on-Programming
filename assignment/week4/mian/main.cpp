#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

class oper
{
private:
    int num1_len;
    int num2_len;
    int num1[100];
    int num2[100];
    int result[100];
    int op;
public:
    void getNum(void); //加载
    void dispNum(void); //处理载入的字符串
};


void oper::getNum(void)
{
    char str1[100];
    char str2[100];
    char op_[2];

    gets(str1);
    gets(op_);
    gets(str2);

    printf("%s %s %s", str1, op_, str2);

}


int main(void)
{
    oper *a;

    a.getNum();
    return 0;
}
