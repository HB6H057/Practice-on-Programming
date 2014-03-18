#include "string"
#include <stdio.h>
#include <iostream>
using namespace std;
#define WARNUM createSeq[team][createNum]


char Knight[5][50] = {"dragon", "ninja", "iceman", "lion", "wolf"};
char Team[2][50] = {"Red", "Blue"};

int createSeq[2][5] = {2, 3, 4, 1, 0, 3, 0, 1, 2, 4}; //��������

int knightHp[5] = {0};//�³�����Ӣ������Ԫ


class headquarter //����
{
private:
    int hp; //����Ԫ
	int hs[4]; //ʱ����
    int team; //�����ĸ��ܲ� 0��ʾ�� 1��ʾ��
    int knightCout[5];//Ӣ������ 0~4��ʾdragon~wolf
    int createNum; //���β�����Ӣ�����
public:

    headquarter(int hp_, int team_) //��ʼ������Ԫ
    {
		int i;
        hp = hp_;
        team = team_; //ѡ�����
		createNum = 0;
		for (i = 0; i < 4; i++)
		{
			hs[i] = 0;
		}

		for (i = 0; i < 5; i++)
		{
			knightCout[i] = 0;
		}
		
    }
    int createKnight(void); //����ʿ�� i + 1Ϊ���
	void Print(void); //���ش�ӡ
    void numUp(void) //���++
    {
    	hs[3]++;
    	hs[0] = hs[3] / 100;
    	hs[1] = hs[3] / 10 - hs[0] * 100;
    	hs[2] = hs[3] % 10;


    }
};
int headquarter::createKnight(void) //����ʿ��
{
	int n = 0; //ѭ������

	if (hp == -1)
		return 0; //����Ԫ�Ѿ�������

	numUp(); //���++
	while ( hp < knightHp[WARNUM] )
	{
    	createNum++;
    	if (createNum > 4)
    		createNum = 0;

    	n++;

		if ( (n > 5) || (hp == 0)) //ѭ��һ�ܺ� ����ֵ����������Ӣ����
    	{
    		//red headquarter stops making warriors
    		printf("%d%d%d ",hs[0], hs[1], hs[2]);
    		printf("%s headquarter stops making warriors\n", Team[team]);
    		hp = -1;
    		return 0;
    	}
	}

	knightCout[WARNUM]++; //��Ӣ��������1
	hp -= knightHp[WARNUM]; //����Ԫ����


	//000 red iceman 1 born with strength 5,1 iceman in red headquarter
	printf("%d%d%d %s %s %d born with", \
			hs[0], hs[1], hs[2], Team[team], Knight[WARNUM], hs[3]);
	printf(" strength %d,%d %s in %s headquarter\n", \
			knightHp[WARNUM], knightCout[WARNUM], Knight[WARNUM], Team[team]);

    createNum++;
    if (createNum > 4)
        createNum = 0;

	return 1;
}

void headquarter::Print(int cas)
{
	int hpSum[cas];
	
}

int main(void)
{

	int cas = 0;
	int hpSum = 0;
    int n = 1;

	scanf_s("%d", &cas);
	scanf_s("%d", &hpSum);
	scanf_s("%d %d %d %d %d", knightHp + 0, knightHp + 1, knightHp + 2, \
							knightHp + 3, knightHp + 4);

	cout << "case:" << cas <<endl;
	headquarter c1(hpSum, 0);
	headquarter c2(hpSum, 1);

	while (1)
    {
        if ( !c1.createKnight() )
			n++;
        if ( !c2.createKnight() )
			n++;
		if (n == 2)
			break;
		n = 0;
    }
    return 0;

}
