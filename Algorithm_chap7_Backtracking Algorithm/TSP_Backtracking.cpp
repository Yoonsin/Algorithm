//���� C���µ� �����迭�� �ʿ��ؼ� C++�� «���� �ǹ���������

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

#define INF 10000
#define MAX_VERTICES 7

vector<int> v;
int bestSolution = INF;

//�׷��� : ���� ����ġ
//���� : ����, ����, ����ġ
typedef struct GraphType {
	int n; //������ ����
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;

void init(GraphType* g) {
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++) {
		for (c = 0; c < MAX_VERTICES; c++) {
			g->adj_mat[r][c] = 0;
		}
	}
}

void insert_vertex(GraphType* g, int v) {
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "�׷���: ������ ���� �ʰ�");
		return;
	}
	g->n++;
}

void insert_edge(GraphType* g, int start, int end, int weight) {
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "�׷���: ���� ��ȣ ����");
		return;
	}
	g->adj_mat[start][end] = weight;
	g->adj_mat[end][start] = weight;
}

int find_tour(GraphType *g, vector<int> v) {
	if (v.size() == 1)
		return 0;
	int sum = 0;
	for (int i = 0; i < v.size() - 1; i++) {
		int idx_1 = v[i];
		int idx_2 = v[i + 1];
		sum += g->adj_mat[idx_1][idx_2];
	}

	return sum;
}


void backtrackTSP(GraphType* g, vector<int> tour) {
	if (tour.size() == g->n) { //tour�� ������ �� ==> ������ �� ���Խ��״ٸ�
		int tourSolution = find_tour(g,tour);

		tourSolution += g->adj_mat[tour[tour.size() - 1]][0];//������ ������ ���� �������� �Ÿ��� �����ϱ�
		tour.push_back(0);
		
		if (tourSolution < bestSolution) { //�� ª�� �ظ� ã������
			bestSolution = tourSolution;
			//printf("bestSolution : %d\n", bestSolution);
		}
	}
	else {
		int tourLastvtx = tour[tour.size() - 1]; //������ ������ ��
		for (int i = 1; i < g->n; i++) {  
			if (find(tour.begin(), tour.end(), i) == tour.end()) { //���� ���� tour�� ���Ե��� �ʴ� ���̰�
				if (g->adj_mat[tourLastvtx][i] != 0) { //Ȯ�� ������ ���̶��
					
					vector<int> newTour = tour;
					newTour.push_back(i); //���� tour�� �ڿ� �� ���� �߰� �Ѵ�.
					if (find_tour(g, newTour) < bestSolution) { //newTour�� �Ÿ��� bestSolution�� �Ÿ����� �۾ƾ�
						backtrackTSP(g, newTour); //��� �Ʒ��� ������ ����� �� �ְ� �Ѵ�. (�Ÿ��� ũ�� �� �Լ��� �������� ���Ѵ�. = ����ġ��)
					}
				}
			}
		}
	
	}

}

int main(void) {
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);
	//0~4 : a,b,c,d,e�� ��Ÿ����.
	for (int i = 0; i < 5; i++) {
		insert_vertex(g, i);
	}
	insert_edge(g, 0, 1, 2);
	insert_edge(g, 0, 2, 7);
	insert_edge(g, 0, 3, 3);
	insert_edge(g, 0, 4, 10);
	insert_edge(g, 1, 2, 3);
	insert_edge(g, 1, 3, 5);
	insert_edge(g, 1, 4, 4);
	insert_edge(g, 2, 3, 6);
	insert_edge(g, 2, 4, 1);
	insert_edge(g, 3, 4, 9);
	
	
	v.push_back(0); //�⺻������ tour���� ������ 0�� ����.
	backtrackTSP(g, v);
	printf("bestSolution: %d", bestSolution);



	return 0;
}