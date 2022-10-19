//일단 되긴 되는데 뭔가 오래걸림

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define MAX_VERTICES 100
#define INF 1000

int parent[MAX_VERTICES]; //부모노드

//초기화
void set_init(int n)
{
	for (int i = 0; i < n; i++)
		parent[i] = -1;
}

//curr가 속하는 집합을 반환한다.
int set_find(int curr)
{
	if (parent[curr] == -1)
		return curr; //루트 노드의 인덱스 반환

	while (parent[curr] != -1) 
	{
		curr = parent[curr]; //부모노드로 한층 올라가기
	}
	return curr; //맨 위 루트노드 반환
}

//두개의 원소가 속한 집합을 합친다.
void set_union(int a, int b)
{
	int root1 = set_find(a); //노드 a의 루트를 찾는다.
	int root2 = set_find(b); //노드 b의 루트를 찾는다.
	if (root1 != root2) //루트가 같지 않으면 (사이클을 만들지 않으면)
		parent[root1] = root2; //합한다. 난 여기가 이해가 안돼..root2의 자식 노드는 어떻게 되는거야
	//-> 애초에 자식자체가 없고 처음부터 트리를 만들어 주는거임그래서 상관 없음
}

//간선 구조체
struct Edge { 
	int start, end, weight;
};

typedef struct GraphType {
	int n; //간선의 갯수
	struct Edge edge[2 * MAX_VERTICES];  //왜 정점x2 = 간선인거지..
}GraphType;

void graph_init(GraphType* g)
{
	g->n = 0;
	for (int i = 0; i < 2 * MAX_VERTICES; i++)
	{
		g->edge[i].start = 0;
		g->edge[i].end = 0;
		g->edge[i].weight = INF;
	}
}

//간선 삽입 연산
void insert_edge(GraphType* g, int start, int end, int w)
{
	g->edge[g->n].start = start;
	g->edge[g->n].end = end;
	g->edge[g->n].weight = w;
	g->n++; //간선 갯수 증가
}

//qsort()에 사용되는 함수
int compare(const void* a, const void* b)
{
	struct Edge* x = (struct Edge*)a;
	struct Edge* y = (struct Edge*)b;
	return(x->weight - y->weight); 
}

void kruskal(GraphType* g)
{
	int edge_accepted = 0; //현재까지 선택된 간선의 수
	int uset, vset; //정점 u와 정점 v의 집합 번호
	struct Edge e;

	set_init(g->n); //집합 초기화
	qsort(g->edge, g->n, sizeof(struct Edge), compare);
	//정렬할 배열, 배열의 총 엘리먼트 갯수, 배열 한개의 크기, 비교를수행할 함수의 포인터

	printf("크루스칼 최소 신장 트리 알고리즘 \n");
	int i = 0;

	while (edge_accepted < (g->n -1)) //최소 신장트리의 간선의 수 < (n-1)
	{
		e = g->edge[i];
		uset = set_find(e.start); //정점 u의 집합 번호
		vset = set_find(e.end); //정점 v의 집합 번호
		if (uset != vset) //서로 속한 집합이 다르면
		{
			printf("간선 (%d %d) %d 선택\n", e.start, e.end, e.weight);
			edge_accepted++;
			set_union(uset, vset);
		}
		i++;
	}

}

int main(int argc,char* argv)
{
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	graph_init(g);

	insert_edge(g, 0, 1, 29);
	insert_edge(g, 1, 2, 16);
	insert_edge(g, 2, 3, 12);
	insert_edge(g, 3, 4, 22);
	insert_edge(g, 4, 5, 27);
	insert_edge(g, 5, 0, 10);
	insert_edge(g, 6, 1, 15);
	insert_edge(g, 6, 3, 18);
	insert_edge(g, 6, 4, 25);

	kruskal(g);
	free(g);
	return 0;



}






