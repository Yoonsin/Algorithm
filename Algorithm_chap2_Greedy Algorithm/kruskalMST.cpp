#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTIX 100
#define INF 1000

int parent[MAX_VERTIX]; //�θ� ���

void SetInit(int num) //���� �ʱ�ȭ
{
	for (int i = 0; i < num; i++)
	{
		parent[i] = -1; //�ϴ� ���յ� �� -1�� �ʱ�ȭ
	}
}

int SetFind(int curr) //������ �� ��Ʈ ã��
{
	if (parent[curr] == -1) //���� �̹� ��Ʈ����
		return curr;  //�׳� ��ȯ�ϸ� ��
	while (parent[curr] != -1) //�ƴϸ�
	{
		curr = parent[curr]; //��� �θ�� �ö󰡱�
	}
	return curr;
}

void SetUnion(int uset,int vset) //���� ��ġ��
{
	if (SetFind(uset) != SetFind(vset))
	{
		parent[vset] = uset; //uset�� vset�� �θ�� �̾��ֱ�
	}
}

typedef struct Line {
	int start, end, weight;
}Line;

typedef struct GraphType{
	Line line[MAX_VERTIX * 2];
	int num; //���� ���� 
}GraphType;


void GraphInit(GraphType* g) //�׷��� �ʱ�ȭ
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
	return (x->weight - y->weight); //������������ ����

}


void Kruskal(GraphType* g) //ũ�罺Į �ּҽ���Ʈ��
{
	SetInit(g->num); //!���� �ʱ�ȭ
	//������ ����ġ ������������ �� ����
	qsort(g->line, g->num, sizeof(Line), compare);
	
	int uset = 0, vset = 0; //�� ���� ��ȣ��
	int acceptedLine = 0; //���� ���õ� Ƚ��
	int i = 0;
	Line e;

	while (acceptedLine < g->num-1) //�ִ��� ���� ���� -1��ŭ ���õǾ���.. g->num�� �����ε�? ���� ������Ѥ�
	{
		e = g->line[i];//�Ǿտ� �ִ� ���� �̾Ƽ�
		uset = SetFind(e.start);
		vset = SetFind(e.end); //�������� ������ �� ��Ʈ ã��.
		if (uset != vset) //��Ʈ�� �ٸ��� (==����Ŭ�� ������ ������)
		{
			SetUnion(uset, vset); //���� ��ġ��
			printf("���� ( start: %d  end: %d ) ����. ����ġ: %d\n", e.start, e.end, e.weight);
			acceptedLine++;
		}
		i++; //i++�����ֱ�
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