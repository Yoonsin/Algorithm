#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_INDEX 7

 
//��ü ���� S, S�� �κ����� F1~Fi�� ��Ƴ��� ����Ʈ L //��ü ���Ҵ� 7��.
//F1~Fi�� S�� ��ü�� Ŀ���� �� �ִ� �κ������� ���ο� ���� N�� �ʿ���.


typedef struct FracticalSet { //�κ����� F
	int element[MAX_INDEX]; //������ ����
	int SetSize; //�κ����� �ȿ� ����ִ� ������ ����
	//FracticalSet* next; //���� ���Ұ�
};

typedef struct SetList { //�κ����� F1~Fi�� ��Ƴ��� ����Ʈ L
	FracticalSet* Set[10]; //�κ������� ������ 10��
};

void initAllSet(FracticalSet* s)
{
	s->SetSize = 0;
	for (int i = 1; i <= MAX_INDEX; i++)
	{
		s->element[i] = i;
		s->SetSize++;  //1~7���� 7���� ���Ҹ� ������ �ִ� ��ü���� S �ʱ�ȭ 
	}
}

void InitSetList(SetList* l)
{
	for (int i = 0; i < 10; i++) //�Ѱ��� ���� ��
	{
		for (int j = 0; j < rand()%7+1; j++) //���� 1~7������ �� ������ �ֱ�
		{
			l->Set[i]->element[j] = rand() % 7 + 1; //1~7������ �� �����ϰ� �ֱ�
			l->Set[i]->SetSize++; //���� ������ ++
		}
		
	}
}

void SetCover(FracticalSet* s, SetList* l) //N�� ���� ���� ����= ��ü���տ��� ��� ���� ������ �˻��ϸ� �� ��Ұ� ���� ��
{
	while(s->SetSize == 0) //��ü ������ �������� �� ������
	{
		for (int i = 0; i < 10; i++) //��ü �κ����� ����
		{
			for (int j = 0; j < l->Set[i]->SetSize; j++) //� �κ����� Fi �� ó������ ������ ��� �˻�
			{
				//��ü���հ� ���� ��� �ִ� ��ŭ ��������
			}

			//���� ū ���� �̾Ƽ� ����Ʈ N�� ���̰�
			//S�� �� ���� �� ���ְ� setsize�� �� ����ŭ ���̱� 
		}
	}
}


int main(void)
{
	srand(time(NULL)); //������ ���� �Ź� �ٸ� �õ尪 ����

	FracticalSet* allSet = (FracticalSet*)malloc(sizeof(FracticalSet)); //��ü����
	SetList* setList = (SetList*)malloc(sizeof(SetList)); //�κ����� F1~Fi�� ��Ƴ��� ����Ʈ L
	initAllSet(allSet); //��ü���� �ʱ�ȭ
	InitSetList(setList); //�κ����� ���� �ʱ�ȭ 

	SetCover(allSet, setList);

	return 0;

}