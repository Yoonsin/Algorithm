#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_INDEX 7

 
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

void initAllSet(FracticalSet* s)
{
	s->SetSize = 0;
	for (int i = 1; i <= MAX_INDEX; i++)
	{
		s->element[i] = i;
		s->SetSize++;  //1~7까지 7개의 원소를 가지고 있는 전체집합 S 초기화 
	}
}

void InitSetList(SetList* l)
{
	for (int i = 0; i < 10; i++) //한개의 집합 당
	{
		for (int j = 0; j < rand()%7+1; j++) //값을 1~7까지의 값 랜덤개 주기
		{
			l->Set[i]->element[j] = rand() % 7 + 1; //1~7까지의 값 랜덤하게 주기
			l->Set[i]->SetSize++; //원소 갯수도 ++
		}
		
	}
}

void SetCover(FracticalSet* s, SetList* l) //N에 없는 값이 많고= 전체집합에서 요소 빼고 남은거 검색하면 됨 요소가 많은 거
{
	while(s->SetSize == 0) //전체 집합이 공집합이 될 때까지
	{
		for (int i = 0; i < 10; i++) //전체 부분집합 돌기
		{
			for (int j = 0; j < l->Set[i]->SetSize; j++) //어떤 부분집합 Fi 의 처음부터 끝까지 요소 검색
			{
				//전체집합과 같은 요소 있는 만큼 갯수세기
			}

			//제일 큰 놈을 뽑아서 리스트 N에 붙이고
			//S에 그 값들 다 빼주고 setsize도 뺀 값만큼 줄이기 
		}
	}
}


int main(void)
{
	srand(time(NULL)); //랜덤을 위해 매번 다른 시드값 생성

	FracticalSet* allSet = (FracticalSet*)malloc(sizeof(FracticalSet)); //전체집합
	SetList* setList = (SetList*)malloc(sizeof(SetList)); //부분집합 F1~Fi를 모아놓은 리스트 L
	initAllSet(allSet); //전체집합 초기화
	InitSetList(setList); //부분집합 모음 초기화 

	SetCover(allSet, setList);

	return 0;

}