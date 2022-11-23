#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

#define INF 10000
#define MAX_VERTICES 7

vector<int> v;
int bestSolution = INF;

//그래프 : 간선 가중치
//간선 : 시작, 종료, 가중치
typedef struct GraphType {
	int n; //정점의 개수
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
		fprintf(stderr, "그래프: 정점의 개수 초과");
		return;
	}
	g->n++;
}

void insert_edge(GraphType* g, int start, int end, int weight) {
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}
	g->adj_mat[start][end] = weight;
	g->adj_mat[end][start] = weight;
}

int find_tour(GraphType *g, vector<int> v) {
	if (v.size() == 1)
		return -1;
	int sum = 0;
	for (int i = 0; i < v.size() - 1; i++) {
		int idx_1 = v[i];
		int idx_2 = v[i + 1];
		sum += g->adj_mat[idx_1][idx_2];
	}

	return sum;
}


void backtrackTSP(GraphType* g, vector<int> tour) {
	if (tour.size() == g->n) { //tour가 완전한 해 ==> 정점을 다 포함시켰다면
		int tourSolution = find_tour(g,tour);
		if (tourSolution < bestSolution) { //더 짧은 해를 찾았으면
			bestSolution = tourSolution;
			printf("bestSolution : %d\n", bestSolution);
		}
	}
	else {
		int tourLastvtx = tour[tour.size() - 1];
		for (int i = 1; i < g->n; i++) {  //반례 [1][2] 했는데 [2][1]도 되면 안됨..
			if (find(tour.begin(), tour.end(), i) == tour.end()) { //tour에 포함되지 않고
				if (g->adj_mat[tourLastvtx][i] != 0) { //확장 가능한 점이라면
					vector<int> newTour = tour;
					newTour.push_back(i); //기존 tour의 뒤에 그 점을 추가 한다.
					if (find_tour(g, newTour) < bestSolution) {
						backtrackTSP(g, newTour);
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
	//0~4 : a,b,c,d,e,
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
	
	
	v.push_back(0); //기본적으로 tour에는 시작점 0dl emfdjrka
	backtrackTSP(g, v);




	return 0;
}