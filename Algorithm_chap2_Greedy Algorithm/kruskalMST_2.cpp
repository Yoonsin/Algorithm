//�ϴ� �Ǳ� �Ǵµ� ���� �����ɸ�

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define MAX_VERTICES 100
#define INF 1000

int parent[MAX_VERTICES]; //�θ���

//�ʱ�ȭ
void set_init(int n)
{
	for (int i = 0; i < n; i++)
		parent[i] = -1;
}

//curr�� ���ϴ� ������ ��ȯ�Ѵ�.
int set_find(int curr)
{
	if (parent[curr] == -1)
		return curr; //��Ʈ ����� �ε��� ��ȯ

	while (parent[curr] != -1) 
	{
		curr = parent[curr]; //�θ���� ���� �ö󰡱�
	}
	return curr; //�� �� ��Ʈ��� ��ȯ
}

//�ΰ��� ���Ұ� ���� ������ ��ģ��.
void set_union(int a, int b)
{
	int root1 = set_find(a); //��� a�� ��Ʈ�� ã�´�.
	int root2 = set_find(b); //��� b�� ��Ʈ�� ã�´�.
	if (root1 != root2) //��Ʈ�� ���� ������ (����Ŭ�� ������ ������)
		parent[root1] = root2; //���Ѵ�. �� ���Ⱑ ���ذ� �ȵ�..root2�� �ڽ� ���� ��� �Ǵ°ž�
	//-> ���ʿ� �ڽ���ü�� ���� ó������ Ʈ���� ����� �ִ°��ӱ׷��� ��� ����
}

//���� ����ü
struct Edge { 
	int start, end, weight;
};

typedef struct GraphType {
	int n; //������ ����
	struct Edge edge[2 * MAX_VERTICES];  //�� ����x2 = �����ΰ���..
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

//���� ���� ����
void insert_edge(GraphType* g, int start, int end, int w)
{
	g->edge[g->n].start = start;
	g->edge[g->n].end = end;
	g->edge[g->n].weight = w;
	g->n++; //���� ���� ����
}

//qsort()�� ���Ǵ� �Լ�
int compare(const void* a, const void* b)
{
	struct Edge* x = (struct Edge*)a;
	struct Edge* y = (struct Edge*)b;
	return(x->weight - y->weight); 
}

void kruskal(GraphType* g)
{
	int edge_accepted = 0; //������� ���õ� ������ ��
	int uset, vset; //���� u�� ���� v�� ���� ��ȣ
	struct Edge e;

	set_init(g->n); //���� �ʱ�ȭ
	qsort(g->edge, g->n, sizeof(struct Edge), compare);
	//������ �迭, �迭�� �� ������Ʈ ����, �迭 �Ѱ��� ũ��, �񱳸������� �Լ��� ������

	printf("ũ�罺Į �ּ� ���� Ʈ�� �˰��� \n");
	int i = 0;

	while (edge_accepted < (g->n -1)) //�ּ� ����Ʈ���� ������ �� < (n-1)
	{
		e = g->edge[i];
		uset = set_find(e.start); //���� u�� ���� ��ȣ
		vset = set_find(e.end); //���� v�� ���� ��ȣ
		if (uset != vset) //���� ���� ������ �ٸ���
		{
			printf("���� (%d %d) %d ����\n", e.start, e.end, e.weight);
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






