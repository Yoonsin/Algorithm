#include <stdio.h>
#include <stdlib.h>
#define MAX_HEAP 7

//�ּ� ����
typedef struct Node {
	int weight;
	char cr;
};

typedef struct HeapType {
	Node node[MAX_HEAP];
};

//Ʈ�� 
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

	//���ĺ��� ������ �޾��ص�, insertminheap �Լ��� �� ���� ���� MAX_HEAP��ŭ �ݺ�.�̰͵� �����ͷ� �޾�����ϳ�

	for (int i = 0; i < MAX_HEAP-1; i++) //���� ũ��-1��ŭ �ݺ�
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