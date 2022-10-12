#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_INDEX 8

 
//전체 집합 S, S의 부분집합 F1~Fi를 모아놓은 리스트 L //전체 원소는 7개.
//F1~Fi중 S의 전체를 커버할 수 있는 부분집합의 새로운 모음 N가 필요함.


typedef struct FracticalSet { //부분집합 F
	int element[MAX_INDEX]; //집합의 원소
	int SetSize; //부분집합 안에 들어있는 원소의 갯수
	//FracticalSet* next; //다음 원소값
};

typedef struct SetList { //부분집합 F1~Fi를 모아놓은 리스트 L
	FracticalSet* Set[10]; //부분집합의 갯수는 10개
};

int s[MAX_INDEX] = { 1,2,3,4,5,6,7 };

void InitSetList(SetList* l)
{
	for (int i = 0; i < 10; i++) //한개의 집합 당
	{
		for (int j = 0; j < rand()%7+1; j++) //값을 랜덤개 주기
		{
			l->Set[i]->element[j] = rand() % 7 + 1; //1~7까지의 값
			l->Set[i]->SetSize++; //원소 갯수도 +
		}
		
	}
}

void SetCover()
{

}


int main(void)
{
	srand(time(NULL)); //랜덤을 위해 매번 다른 시드값 생성

	SetList* setList = (SetList*)malloc(sizeof(SetList));
	InitSetList(setList);

	SetCover();

}