#include <stdio.h>
#include <Stdlib.h>
#define MAX_NODE 8

typedef struct Node {
	int weight; //��(����ġ) 
}Node;

typedef struct HeapType {
	Node node[MAX_NODE]; //���� 
	int heap_size; //�����ȿ� ��尡 � �ִ���
}HeapType;

void init_heap(HeapType* h)
{
	h->heap_size = 0;
	//h->node[h->heap_size].weight = 0; //���� 1���� ���� 
	
}

void insert_max_heap(HeapType* h, int item)
{
	h->heap_size += 1;
	int i = h->heap_size;
	while (i != 1) //��Ʈ�� ���� ���� ������
	{
		if (h->node[i / 2].weight < item) //�θ�� ���ؼ� �������� �� ũ��
		{
			h->node[i].weight = h->node[i / 2].weight; //�θ� �ڽ����� ������
			i /= 2; //���� ��ġ�� �θ� ��ġ�� �Ѵܰ� �ö󰣴�.
		}

		if (h->node[i / 2].weight >= item) //�������� �θ𺸴� �۰ų� ������ 
		{
			break; //�׳� ���ڸ��� �ֱ� 
		}
	
	}

	h->node[i].weight = item;
}

int delete_max_heap(HeapType* h)
{
	int pop = h->node[1].weight;
	int temp = h->node[h->heap_size].weight;
	h->heap_size -= 1;
	int parent = 1; int child = 2;
	while (child <= h->heap_size)
	{
		if (child < h->heap_size) //
		{
			if (h->node[child].weight < h->node[child + 1].weight)
			{
				child = child + 1;
			}
		}

		if (temp < h->node[child].weight) //������ ���Һ��� �ڽ��� �� ũ�ٸ� 
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

void print_heap(HeapType* h)
{
	printf("�ִ� ����: ");
	for (int i = 1;i <= h->heap_size;i++)
	{
		printf("%d ", h->node[i].weight);
	}
}

int main(void)
{
	HeapType* h = (HeapType*)malloc(sizeof(HeapType));
	init_heap(h);
	int a[MAX_NODE]; //���� ��尪�� MAX_NODE-1 (����: ������ �ε��� 1���� ��尡 �����ؼ�)

	for (int i = 1;i <= 7;i++)
	{
		insert_max_heap(h, i); //1~6���� �ִ� ������ �ֱ� 
	}

	for (int i = 1;i <= 7;i++) //3�� �ִ� �������� ���� 
	{
		a[i] = delete_max_heap(h);
	}
	printf("�ִ� ������� \n");

	for (int i = 1;i <= 7;i++)
	{
		printf("%d ", a[i]); //���� ���� �� �ִ밪�� �̾��� ���´ٴ°� �ٽ�. ���� �� ��ü�� �׳� ����ϸ� ���� �ȵʤѤ� ����Ʈ�� ���Ѱ���
		//������� �迭�� ��ƾ��� 
		//������ ����. �θ� ��� Ű�� >= �ڽ� ��� Ű�� : �ִ� ���� 
	}

	return 0;
}