#include <stdio.h>
#include <stdlib.h>
#define MAX_HEAP 7

//최소 히프
typedef struct Node {
	int weight;
	char cr;
};

typedef struct HeapType {
	Node node[MAX_HEAP];
};

//트리 
typedef struct Tree {
	Node* right;
	Node* left;
	Node* root;
};

void printfTree(t)
{

}

int main(void)
{
	HeapType* h = (HeapType*)malloc(sizeof(HeapType));
	Tree* t = (Tree*)malloc(sizeof(Tree));

	//알파벳과 정수를 받아준뒤, insertminheap 함수로 그 값들 삽입 MAX_HEAP만큼 반복.이것도 포인터로 받아줘야하나

	for (int i = 0; i < MAX_HEAP-1; i++) //히프 크기-1만큼 반복
	{
		node_1= DeleteMinheap();
		node_2 = DeleteMinHeap();

		Node root = { node_1 + node_2 , '\0' };
		t->root = &root;
		t->left = &node_1;
		t->right = &node_2;
		insertminheap(root);
	}

	printfTree(t);

	return 0;
}