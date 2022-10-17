#include <stdio.h>
#include <stdlib.h>
#define MIN_HEAP 4

char monza[MIN_HEAP + 1][10] = { "" }; //������ �迭 MIN_HEAP ������ŭ ���� �� ���δ� NULL�� �ʱ�ȭ
int index=0; //���� �ε���

//�ּ� ����
typedef struct Node {
	int weight;
	char cr;
	Node* right;
	Node* left;
}Node;

typedef struct HeapType {
	Node node[MIN_HEAP+1]; //�ε��� 1���� �����ϴϱ� �迭 ũ�⵵ +1 �������
	int heap_size; //�����ȿ� ��尡 � �ִ���
}HeapType;

//Ʈ�� 
typedef struct Tree {
	Node* right;
	Node* left;
	Node* root;
}Tree;


void InsertMinHeap(HeapType* h,Node n)
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

Node* bulidHuffmanTree(HeapType* h)
{
	//Node node_1 = DeleteMinHeap(h); pop�� �ּҰ� == node_1�� �ּҰ�??

	Node* finalRoot = (Node*)malloc(sizeof(Node));

	for (int i = 0; i < MIN_HEAP - 1; i++) //���� ũ��-1��ŭ �ݺ� (�������� 2���� �̴°Ŵϱ�)
	{ //��� ��带 ���� ������Ű��? �״�� �貸���� �ʰ�???

		Node node_1 = DeleteMinHeap(h); 
		Node node_2 = DeleteMinHeap(h);

		Node* rootNode = (Node*)malloc(sizeof(Node));
		rootNode->weight = node_1->weight + node_2->weight;
		rootNode->cr = '\0';

		rootNode->left = node_1;
		rootNode->right = node_2; //Ʈ�� �����

		InsertMinHeap(h, rootNode); //��Ʈ �ٽ� ������ �ֱ� 

		if (i == MIN_HEAP - 2) //������ �������̸�
		{
			finalRoot = rootNode; //������ ��Ʈ, �� ������Ʈ���� �� �� ��� �ֱ�
		}

	}
	return finalRoot;
	
}


void printfTree(Node* t,char (* monza)[10]) //�迭�����ʹ� �迭�� ����Ű�� '�ϳ�'�� ������
{
	int k = 0;

	if (t->right == NULL && t->left == NULL) //���� ����
	{
		return; //������
	}

	//������ �ڵ� ����� �ȿ� ���ĺ��� �������� ������ָ� ��
	if (t->cr)
	{
		printf("���ĺ� %c�� ������ �ڵ� : %s ", t->cr, monza[index] );
	}

	//���� ��忡 �������� ȣ���ϱ�
	if (t->left)
	{
		//������ �ε���x2 �� ���� ����� �ε���
		k = 0;
		while (monza[index][k] != '\0') //null������ ���� ������ �ݺ�
		{
			monza[index * 2][k] = monza[index][k]; //���� ������ �ڵ带 �ڽ� ��忡�� �Ѱ��ְ�
			k++;
		}
		index *=2;
		monza[index][k] = '0';
	

		
		printfTree(t, monza);
		
	}

	//������ ��忡 �������� ȣ���ϱ�
	if (t->right)
	{
		//������ �ε���x2+1 �� ���� ����� �ε���
		k = 0;
		while (monza[index][k] != '\0') //null������ ���� ������ �ݺ�
		{
			monza[index * 2][k] = monza[index][k]; //���� ������ �ڵ带 �ڽ� ��忡�� �Ѱ��ְ�
			k++;
		}
		index *= 2+1;
		monza[index][k] = '1';
		printfTree(t, monza);

	}
}

int main(void)
{
	HeapType* h = (HeapType*)malloc(sizeof(HeapType));
	Tree* t = (Tree*)malloc(sizeof(HeapType) * MIN_HEAP - 1); //Ʈ���� MIN_HEAP-1������ŭ ������� �� �� Ʈ���� ������ Ʈ��

	Node node_insert;

	char cr='\0'; int num=0; 
	 int last=0;

	h->heap_size = 0; //���� �ʱ�ȭ

	//���ĺ��� ������ �޾��ص�, insertminheap �Լ��� �� ���� ���� MAX_HEAP��ŭ �ݺ�.�̰͵� �����ͷ� �޾�����ϳ�
	for (int i = 0; i < MIN_HEAP; i++)
	{
		printf("���ĺ��� �Է����ּ���: ");
		scanf_s("%c", &cr, sizeof(cr));
		printf("�󵵼��� �Է����ּ���: ");
		scanf_s("%d", &num);
		getchar(); //���� ����
		
		node_insert.weight = num; node_insert.cr = cr; //�Է��Ѱ� ��忡 �ֱ�
		InsertMinHeap(h, node_insert); //�� ��� �ּ������� �ֱ�
		
	}
	
	
	Node* ft = bulidHuffmanTree(h);


	printfTree(ft, monza);

	return 0;
}