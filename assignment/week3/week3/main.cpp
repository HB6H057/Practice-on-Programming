#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>

#define ARMYNUM makingSque[Army][makingNum]
//要制造武士序号

const char armyName[2][5] ={"Red", "Blue"}; //军团名称
const char WarriorName[5][10] = {"dragon", "ninja", "iceman", "lion", "wolf"};  //武士名称
const int makingSque[2][5] = { { 2, 3, 4, 1, 0 }, { 3, 0, 1, 2, 4 }}; //武士制造顺序

//类 headquarter：一个军团的参数以及该军团战士的制造
class headquarter
{
private:
	int Army; //所属军团 0:红 1:蓝 
	int Warriors[5]; //已生成的5种武士数量
	int Time[4];//前三个表示时间，后一个表示序号
	int HP;  //生命元，如果为-1则证明已经没得制造了
	int makingNum; //准备生成的战士序号

public:
	headquarter(int Army_, int HP_) : Army(Army_), HP(HP_) //初始化
	{
		memset(Warriors, 0, sizeof(Warriors)); 
		memset(Time, 0, sizeof(Time));
		makingNum = 0; 
		//数据清零
	}

	void makingCount(void);//转到下一个制造参数
	void timeCount(void);  //时间以及编号增加
	int Making(int * WarriorHP) ; //单次制造武士
	
};

// 函数——makingCount 转到下一个制造参数
void headquarter::makingCount(void)
{
	makingNum++;
	if ( makingNum > 4 )
		makingNum = 0;  //循环制作
}

// 函数——timeCount 表示时间以及编号增加1
void headquarter::timeCount(void) 
{
	Time[3]++;
	Time[0] = Time[3] / 100;
	Time[1] = Time[3] / 10 - Time[0] * 100;
	Time[2] = Time[3] % 10;
}

// 函数——Making 功能为单次制造武士
// 参数——WarriorHp是个数组 表示各个武士的生命元
// 返回——0：造完 1：未造完
int headquarter::Making(int * WarriorHP) 
{
	int n = 0;
	if ( HP == -1 )
		return 0;  //已经制造完成，不需要制造了

	while ( HP < WarriorHP[ARMYNUM] ) //如果当前要制造武士的生命元不足时
	{
		n++;
		makingCount(); //下一个武士

		if ( ( n > 5 ) || ( HP == 0 ) )
		{
			HP = -1; //已经制造完成
			cout << Time[0] << Time[1] << Time[2]; //输出标号
			cout << " " << armyName[Army] << " headquarter stops making warriors" << endl;
			return 0; 
		}
	}

	
	HP -= WarriorHP[ARMYNUM]; //删掉生命元
	Warriors[ARMYNUM]++; //已拥有武士数量增加

	//004 blue lion 5 born with strength 5,2 lion in red headquarter
	cout << Time[0] << Time[1] << Time[2]; //输出标号
	cout << " " << armyName[Army] << " "; //输出军团 
	cout << WarriorName[ARMYNUM] << " " << Time[3] + 1 << " ";
	cout << "born with strength " << WarriorHP[ARMYNUM] << ",";
	cout << Warriors[ARMYNUM] << " " << WarriorName[ARMYNUM] << " ";
	cout << "in " << armyName[Army] << " headquarter" << endl;
	//004 blue lion 5 born with strength 5,2 lion in red headquarter

	makingCount();
	timeCount();

	return 1;
}

//函数——makingWarrior 制造武士
void makingWarrior(void);

int main(void)
{
	makingWarrior();
	//int WHP[5] = {4, 5, 6, 7, 8};
	//headquarter c1(1, 20);
	//while ( c1.Making( WHP ) );
	return 0;
}

void makingWarrior(void)
{
	int cas; //多少组数据
	cin >> cas;

	int *headquarterHP = new int [cas]; 
	int **warriorHP = new int*[cas];

	for (int i = 0; i < cas; i++)
	{
		warriorHP[i] = new int[5];
	}

	for (int i = 0; i < cas; i++)
	{
		cin >> headquarterHP[i];
		scanf_s("%d %d %d %d %d", warriorHP[i] + 0, warriorHP[i] + 1, \
								  warriorHP[i] + 2, warriorHP[i] + 3, warriorHP[i] + 4);
	}

	for (int i = 0; i < cas; i++)
	{
		headquarter Red(0, headquarterHP[i]);
		headquarter Blue( 1, headquarterHP[i] );
		
		cout << "Case:" << i + 1 << endl;

		while (1)
		{
			int n = 2;
			n -= Red.Making(warriorHP[i]);
			n -= Blue.Making(warriorHP[i]);
			if ( n == 2 )
				break;
		}
	}
	
	
}