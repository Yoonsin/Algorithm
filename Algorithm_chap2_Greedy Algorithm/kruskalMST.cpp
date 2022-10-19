#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTIX 100
#define INF 1000

int parent[MAX_VERTIX]; //부모 노드

void SetInit(int num) //집합 초기화
{
	for (int i = 0; i < num; i++)
	{
		parent[i] = -1; //일단 집합들 다 -1로 초기화
	}
}

int SetFind(int curr) //집합의 각 루트 찾기
{
	if (parent[curr] == -1) //만약 이미 루트노드면
		return curr;  //그냥 반환하면 됨
	while (parent[curr] != -1) //아니면
	{
		curr = parent[curr]; //계속 부모로 올라가기
	}
	return curr;
}

void SetUnion(int uset,int vset) //집합 합치기
{
	if (SetFind(uset) != SetFind(vset))
	{
		parent[vset] = uset; //uset를 vset의 부모로 이어주기
	}
}

typedef struct Line {
	int start, end, weight;
}Line;

typedef struct GraphType{
	Line line[MAX_VERTIX * 2];
	int num; //간선 갯수 
}GraphType;


void GraphInit(GraphType* g) //그래프 초기화
{
	g->num = 0;
	for (int i = 0; i < MAX_VERTIX * 2; i++)
	{
		g->line[g->num].start = 0;
		g->line[g->num].end = 0;
		g->line[g->num].weight = INF;
	}

}

void InsertGraph(GraphType* g, int s, int e, int w)
{
	g->line[g->num].start = s;
	g->line[g->num].end = e;
	g->line[g->num].weight = w;

	g->num++;
}

int compare(const void* a, const void* b)
{
	Line* x = (Line*)a;
	Line* y = (Line*)b;
	return (x->weight - y->weight); //오름차순으로 정렬

}


void Kruskal(GraphType* g) //크루스칼 최소신장트리
{
	SetInit(g->num); //!집합 초기화
	//간선들 가중치 오름차순으로 퀵 정렬
	qsort(g->line, g->num, sizeof(Line), compare);
	
	int uset = 0, vset = 0; //각 집합 번호들
	int acceptedLine = 0; //간선 선택된 횟수
	int i = 0;
	Line e;

	while (acceptedLine < g->num-1) //최대한 정점 갯수 -1만큼 선택되야함.. g->num은 간선인데? 정점 어딨음ㅡㅡ
	{
		e = g->line[i];//맨앞에 있는 간선 뽑아서
		uset = SetFind(e.start);
		vset = SetFind(e.end); //시작점과 끝점의 각 루트 찾기.
		if (uset != vset) //루트가 다르면 (==사이클을 만들지 않으면)
		{
			SetUnion(uset, vset); //서로 합치기
			printf("간선 ( start: %d  end: %d ) 선택. 가중치: %d\n", e.start, e.end, e.weight);
			acceptedLine++;
		}
		i++; //i++시켜주기
	}


}



int main(int argv, char* argc)
{
	GraphType* g;
	g = (GraphType *)malloc(sizeof(GraphType));

	GraphInit(g);
	
	InsertGraph(g, 0, 1, 29);
	InsertGraph(g, 1, 2, 16);
	InsertGraph(g, 2, 3, 12);
	InsertGraph(g, 3, 4, 22);
	InsertGraph(g, 4, 5, 27);
	InsertGraph(g, 5, 0, 10);
	InsertGraph(g, 6, 1, 15);
	InsertGraph(g, 6, 3, 18);
	InsertGraph(g, 6, 4, 25);

	Kruskal(g);
	free(g);

	return 0;
}