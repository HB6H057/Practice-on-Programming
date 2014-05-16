#include <iostream>
#include <vector>

using namespace std;

class bigNum
{
private:
    vector< int > num1;     //操作数1
    vector< int > num2;     //操作数2
    vector< int > result;   //计算结果
    int op;                 //计算符号
public:
    void str2num(const string s1, const string s2, const string op_);
    //处理数据

};

void bigNum::process_str(const string s1, const string s2, const string op_)
{

    int ix = 0; //自家
    //符号判定
    if ( op_[0] == '+' )
        op = 0;
    else if (op_[0] == '-')
        op = 1;
    else if (op_[0] == '*')
        op = 2;
    else
        op = 3;
    for (int i = s1.size() - 1; i < 0; i++ )
        {

        }


}

int main(void)
{

    return 0;
}
