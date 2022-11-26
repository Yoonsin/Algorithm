//�켱���� ť(����)�̶� �׷���. ���� �ʿ�

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

	while ((i != 1) && (item.key > h->heap[i / 2].key)) { //��Ʈ�� �ƴϰ� �θ� Ű���� ���� ������ Ű�� ũ��
		h->heap[i] = h->heap[i / 2]; //�θ��� �������
		i /= 2; //�θ������� �ö󰡱�
	}
	h->heap[i] = item;  //�� ��带 ����(��Ʈ�� while�� ���� �� �ٸ� �����Ѵ�)
}

int main(void) {
	HeapType* h = new HeapType();
	init_heap(h);
}