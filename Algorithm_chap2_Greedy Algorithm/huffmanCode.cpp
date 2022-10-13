#include <stdio.h>
#include <stdlib.h>
#define MIN_HEAP 7

//최소 히프
typedef struct Node {
	int weight;
	char cr;
};

typedef struct HeapType {
	Node node[MIN_HEAP];
	int heap_size; //히프안에 노드가 몇개 있는지
};


void InsertMinHeap(HeapType* h,Node n)
{
	h->heap_size += 1;
	int i = h->heap_size;
	while (i != 1) //루트가 되지 않을 때까지
	{
		if (h->node[i / 2].weight > n.weight) //부모와 비교해서 아이템이 더 작으면
		{
			h->node[i].weight = h->node[i / 2].weight; //부모 자식으로 내리고
			i /= 2; //현재 위치를 부모 위치로 한단계 올라간다.
		}

		if (h->node[i / 2].weight <= n.weight) //아이템이 부모보다 크거나 같으면 
		{
			break; //그냥 그자리에 있기 
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

		if (temp > h->node[child].weight) //마지막 원소보다 자식이 더 작다면 
		{
			h->node[parent].weight = h->node[child].weight; //자식노드 부모로 옮겨주고 

		}
		else //아니면 탈출  
		{
			break;
		}

		parent = child; //부모와 자식 모두 한단계 내려감
		child *= 2;
	}

	h->node[parent].weight = temp; //탈출하면 그 위치에 놓기 . 
	return pop;
}



//트리 
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

	//알파벳과 정수를 받아준뒤, insertminheap 함수로 그 값들 삽입 MAX_HEAP만큼 반복.이것도 포인터로 받아줘야하나
	for (int i = 0; i < MIN_HEAP; i++)
	{
		printf("빈도수를 입력해주세요: ");
		scanf_s("%d", &num);
		printf("알파벳를 입력해주세요: ");
		scanf_s("%c", &cr);
		
		node_insert.weight = num; node_insert.cr = cr; //입력한거 노드에 넣기
		InsertMinHeap(h, node_insert); //그 노드 최소히프에 넣기
		
	}
	

	Node node_1;
	Node node_2; //제일 작은값이 있는 노드 2개 받아줄 변수 선언

	for (int i = 0; i < MIN_HEAP-1; i++) //히프 크기-1만큼 반복 (히프에서 2개씩 뽑는거니까)
	{
		node_1= DeleteMinHeap(h);
		node_2 = DeleteMinHeap(h);

		Node root = { node_1.weight + node_2.weight , '\0' };
		t->root = &root;
		t->left = &node_1;
		t->right = &node_2; //트리 생성
		InsertMinHeap(h,root);
	}

	printfTree(t);

	return 0;
}