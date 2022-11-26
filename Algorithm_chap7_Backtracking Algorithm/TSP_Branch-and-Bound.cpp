//우선순위 큐(민힙)이랑 그래프. 벡터 필요

#include <iostream>
#include <vector>
#define MAX_ELEMENT 200
using namespace std;

typedef struct {
	int key;
}element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

void init_heap(HeapType* h) {
	h->heap_size = 0;
}

void insert_max_heap(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size);

	while ((i != 1) && (item.key > h->heap[i / 2].key)) { //루트가 아니고 부모 키보다 현재 삽입할 키가 크면
		h->heap[i] = h->heap[i / 2]; //부모노드 끌어내리기
		i /= 2; //부모쪽으로 올라가기
	}
	h->heap[i] = item;  //새 노드를 삽입(루트면 while문 없이 이 줄만 실행한다)
}

int main(void) {
	HeapType* h = new HeapType();
	init_heap(h);
}