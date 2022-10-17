#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int weight;
	char cr;
	Node* right;
	Node* left;
}Node;

typedef struct HeapType {
	Node node[9]; //�ε��� 1���� �����ϴϱ� �迭 ũ�⵵ +1 �������
	int heap_size; //�����ȿ� ��尡 � �ִ���
}HeapType;

void InsertMinHeap(HeapType* h, Node n)
{
	h->heap_size += 1;
	int i = h->heap_size;
	while (i != 1) //��Ʈ�� ���� ���� ������
	{
		if (h->node[i / 2].weight > n.weight) //�θ�� ���ؼ� �������� �� ������
		{
			h->node[i] = h->node[i / 2]; //�θ� �ڽ����� ������
			i /= 2; //���� ��ġ�� �θ� ��ġ�� �Ѵܰ� �ö󰣴�.
		}

		if (h->node[i / 2].weight <= n.weight) //�������� �θ𺸴� ũ�ų� ������ 
		{
			break; //�׳� ���ڸ��� �ֱ� 
		}

	}

	h->node[i] = n; // ���� �ִ� ���ȿ� n�� �ּҸ� �ִ´�
}

Node DeleteMinHeap(HeapType* h)
{
	Node pop = h->node[1]; //�Ǿ� ��尡 ����
	Node temp = h->node[h->heap_size]; //���������� �� �ٽ� ����
	h->heap_size -= 1;
	int parent = 1; int child = 2;
	while (child <= h->heap_size)
	{
		if (child < h->heap_size)
		{
			if (h->node[child].weight > h->node[child + 1].weight)
			{
				child = child + 1;
			}
		}

		if (temp.weight > h->node[child].weight) //������ ���Һ��� �ڽ��� �� �۴ٸ� 
		{
			h->node[parent] = h->node[child]; //�ڽĳ�� �θ�� �Ű��ְ� 

		}
		else //�ƴϸ� Ż��  
		{
			break;
		}

		parent = child; //�θ�� �ڽ� ��� �Ѵܰ� ������
		child *= 2;
	}

	h->node[parent] = temp; //Ż���ϸ� �� ��ġ�� ���� . 
	return pop;
}

Node* Peek(HeapType* h)
{
	Node pop = h->node[1]; //�Ǿ� ��尡 ����
	return &pop;
}


int main(void)
{
	HeapType* h = (HeapType*)malloc(sizeof(HeapType));
	Node *a;
	Node node_insert = {1,'a'};
	h->heap_size = 0;
	int num = 0;
	char cr = '\0';
	
	InsertMinHeap(h, node_insert); //�� ��� �ּ������� �ֱ�
	a = Peek(h);

	printf("%p\n",  Peek(h));
	printf("%p\n", a); //������ ���� ��ü�� �ּҰ��� �ٸ�����, ������ ���� ���� �ּҰ��� �� �Լ��� ���� ���� ����. 
	printf("%p", &node_insert);
		
	


	return 0;
}