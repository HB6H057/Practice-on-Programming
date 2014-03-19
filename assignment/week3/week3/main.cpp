#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>

#define ARMYNUM makingSque[Army][makingNum]
//Ҫ������ʿ���

const char armyName[2][5] ={"Red", "Blue"}; //��������
const char WarriorName[5][10] = {"dragon", "ninja", "iceman", "lion", "wolf"};  //��ʿ����
const int makingSque[2][5] = { { 2, 3, 4, 1, 0 }, { 3, 0, 1, 2, 4 }}; //��ʿ����˳��

//�� headquarter��һ�����ŵĲ����Լ��þ���սʿ������
class headquarter
{
private:
	int Army; //�������� 0:�� 1:�� 
	int Warriors[5]; //�����ɵ�5����ʿ����
	int Time[4];//ǰ������ʾʱ�䣬��һ����ʾ���
	int HP;  //����Ԫ�����Ϊ-1��֤���Ѿ�û��������
	int makingNum; //׼�����ɵ�սʿ���

public:
	headquarter(int Army_, int HP_) : Army(Army_), HP(HP_) //��ʼ��
	{
		memset(Warriors, 0, sizeof(Warriors)); 
		memset(Time, 0, sizeof(Time));
		makingNum = 0; 
		//��������
	}

	void makingCount(void);//ת����һ���������
	void timeCount(void);  //ʱ���Լ��������
	int Making(int * WarriorHP) ; //����������ʿ
	
};

// ��������makingCount ת����һ���������
void headquarter::makingCount(void)
{
	makingNum++;
	if ( makingNum > 4 )
		makingNum = 0;  //ѭ������
}

// ��������timeCount ��ʾʱ���Լ��������1
void headquarter::timeCount(void) 
{
	Time[3]++;
	Time[0] = Time[3] / 100;
	Time[1] = Time[3] / 10 - Time[0] * 100;
	Time[2] = Time[3] % 10;
}

// ��������Making ����Ϊ����������ʿ
// ��������WarriorHp�Ǹ����� ��ʾ������ʿ������Ԫ
// ���ء���0������ 1��δ����
int headquarter::Making(int * WarriorHP) 
{
	int n = 0;
	if ( HP == -1 )
		return 0;  //�Ѿ�������ɣ�����Ҫ������

	while ( HP < WarriorHP[ARMYNUM] ) //�����ǰҪ������ʿ������Ԫ����ʱ
	{
		n++;
		makingCount(); //��һ����ʿ

		if ( ( n > 5 ) || ( HP == 0 ) )
		{
			HP = -1; //�Ѿ��������
			cout << Time[0] << Time[1] << Time[2]; //������
			cout << " " << armyName[Army] << " headquarter stops making warriors" << endl;
			return 0; 
		}
	}

	
	HP -= WarriorHP[ARMYNUM]; //ɾ������Ԫ
	Warriors[ARMYNUM]++; //��ӵ����ʿ��������

	//004 blue lion 5 born with strength 5,2 lion in red headquarter
	cout << Time[0] << Time[1] << Time[2]; //������
	cout << " " << armyName[Army] << " "; //������� 
	cout << WarriorName[ARMYNUM] << " " << Time[3] + 1 << " ";
	cout << "born with strength " << WarriorHP[ARMYNUM] << ",";
	cout << Warriors[ARMYNUM] << " " << WarriorName[ARMYNUM] << " ";
	cout << "in " << armyName[Army] << " headquarter" << endl;
	//004 blue lion 5 born with strength 5,2 lion in red headquarter

	makingCount();
	timeCount();

	return 1;
}

//��������makingWarrior ������ʿ
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
	int cas; //����������
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