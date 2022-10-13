#include <stdio.h>
#include <stdlib.h>
#define MIN_HEAP 7

//�ּ� ����
typedef struct Node {
	int weight;
	char cr;
};

typedef struct HeapType {
	Node node[MIN_HEAP];
	int heap_size; //�����ȿ� ��尡 � �ִ���
};


void InsertMinHeap(HeapType* h,Node n)
{
	h->heap_size += 1;
	int i = h->heap_size;
	while (i != 1) //��Ʈ�� ���� ���� ������
	{
		if (h->node[i / 2].weight > n.weight) //�θ�� ���ؼ� �������� �� ������
		{
			h->node[i].weight = h->node[i / 2].weight; //�θ� �ڽ����� ������
			i /= 2; //���� ��ġ�� �θ� ��ġ�� �Ѵܰ� �ö󰣴�.
		}

		if (h->node[i / 2].weight <= n.weight) //�������� �θ𺸴� ũ�ų� ������ 
		{
			break; //�׳� ���ڸ��� �ֱ� 
		}

	}

	h->node[i].weight = n.weight;
	h->node[i].cr = n.cr;
}

Node DeleteMinHeap(HeapType* h)
{
	Node pop = h->node[1];
	int temp = h->node[h->heap_size].weight;
	h->heap_size -= 1;
	int parent = 1; int child = 2;
	while (child <= h->heap_size)
	{
		if (child < h->heap_size) //
		{
			if (h->node[child].weight > h->node[child + 1].weight)
			{
				child = child + 1;
			}
		}

		if (temp > h->node[child].weight) //������ ���Һ��� �ڽ��� �� �۴ٸ� 
		{
			h->node[parent].weight = h->node[child].weight; //�ڽĳ�� �θ�� �Ű��ְ� 

		}
		else //�ƴϸ� Ż��  
		{
			break;
		}

		parent = child; //�θ�� �ڽ� ��� �Ѵܰ� ������
		child *= 2;
	}

	h->node[parent].weight = temp; //Ż���ϸ� �� ��ġ�� ���� . 
	return pop;
}



//Ʈ�� 
typedef struct Tree {
	Node* right;
	Node* left;
	Node* root;
};

void printfTree(Tree* t)
{

}

int main(void)
{
	HeapType* h = (HeapType*)malloc(sizeof(HeapType));
	Tree* t = (Tree*)malloc(sizeof(Tree));

	char cr; int num; Node node_insert;

	//���ĺ��� ������ �޾��ص�, insertminheap �Լ��� �� ���� ���� MAX_HEAP��ŭ �ݺ�.�̰͵� �����ͷ� �޾�����ϳ�
	for (int i = 0; i < MIN_HEAP; i++)
	{
		printf("�󵵼��� �Է����ּ���: ");
		scanf_s("%d", &num);
		printf("���ĺ��� �Է����ּ���: ");
		scanf_s("%c", &cr);
		
		node_insert.weight = num; node_insert.cr = cr; //�Է��Ѱ� ��忡 �ֱ�
		InsertMinHeap(h, node_insert); //�� ��� �ּ������� �ֱ�
		
	}
	

	Node node_1;
	Node node_2; //���� �������� �ִ� ��� 2�� �޾��� ���� ����

	for (int i = 0; i < MIN_HEAP-1; i++) //���� ũ��-1��ŭ �ݺ� (�������� 2���� �̴°Ŵϱ�)
	{
		node_1= DeleteMinHeap(h);
		node_2 = DeleteMinHeap(h);

		Node root = { node_1.weight + node_2.weight , '\0' };
		t->root = &root;
		t->left = &node_1;
		t->right = &node_2; //Ʈ�� ����
		InsertMinHeap(h,root);
	}

	printfTree(t);

	return 0;
}