#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_INDEX 8

 
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

int s[MAX_INDEX] = { 1,2,3,4,5,6,7 };

void InitSetList(SetList* l)
{
	for (int i = 0; i < 10; i++) //�Ѱ��� ���� ��
	{
		for (int j = 0; j < rand()%7+1; j++) //���� ������ �ֱ�
		{
			l->Set[i]->element[j] = rand() % 7 + 1; //1~7������ ��
			l->Set[i]->SetSize++; //���� ������ +
		}
		
	}
}

void SetCover()
{

}


int main(void)
{
	srand(time(NULL)); //������ ���� �Ź� �ٸ� �õ尪 ����

	SetList* setList = (SetList*)malloc(sizeof(SetList));
	InitSetList(setList);

	SetCover();

}