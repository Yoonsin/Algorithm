#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int weight;
	char cr;
	Node* right;
	Node* left;
}Node;

typedef struct HeapType {
	Node node[9]; //인덱스 1부터 접근하니까 배열 크기도 +1 해줘야함
	int heap_size; //히프안에 노드가 몇개 있는지
}HeapType;

void InsertMinHeap(HeapType* h, Node n)
{
	h->heap_size += 1;
	int i = h->heap_size;
	while (i != 1) //루트가 되지 않을 때까지
	{
		if (h->node[i / 2].weight > n.weight) //부모와 비교해서 아이템이 더 작으면
		{
			h->node[i] = h->node[i / 2]; //부모 자식으로 내리고
			i /= 2; //현재 위치를 부모 위치로 한단계 올라간다.
		}

		if (h->node[i / 2].weight <= n.weight) //아이템이 부모보다 크거나 같으면 
		{
			break; //그냥 그자리에 있기 
		}

	}

	h->node[i] = n; // 힙에 있는 노드안에 n의 주소를 넣는다
}

Node DeleteMinHeap(HeapType* h)
{
	Node pop = h->node[1]; //맨앞 노드가 빠짐
	Node temp = h->node[h->heap_size]; //빠진다음에 힙 다시 정렬
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

		if (temp.weight > h->node[child].weight) //마지막 원소보다 자식이 더 작다면 
		{
			h->node[parent] = h->node[child]; //자식노드 부모로 옮겨주고 

		}
		else //아니면 탈출  
		{
			break;
		}

		parent = child; //부모와 자식 모두 한단계 내려감
		child *= 2;
	}

	h->node[parent] = temp; //탈출하면 그 위치에 놓기 . 
	return pop;
}

Node* Peek(HeapType* h)
{
	Node pop = h->node[1]; //맨앞 노드가 빠짐
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
	
	InsertMinHeap(h, node_insert); //그 노드 최소히프에 넣기
	a = Peek(h);

	printf("%p\n",  Peek(h));
	printf("%p\n", a); //포인터 변수 자체의 주소값은 다르지만, 포인터 변수 안의 주소값은 위 함수의 리턴 값과 같다. 
	printf("%p", &node_insert);
		
	


	return 0;
}