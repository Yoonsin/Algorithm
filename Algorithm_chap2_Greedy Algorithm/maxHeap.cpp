#include <stdio.h>
#include <Stdlib.h>
#define MAX_NODE 8

typedef struct Node {
	int weight; //값(가중치) 
}Node;

typedef struct HeapType {
	Node node[MAX_NODE]; //히프 
	int heap_size; //히프안에 노드가 몇개 있는지
}HeapType;

void init_heap(HeapType* h)
{
	h->heap_size = 0;
	//h->node[h->heap_size].weight = 0; //노드는 1부터 시작 
	
}

void insert_max_heap(HeapType* h, int item)
{
	h->heap_size += 1;
	int i = h->heap_size;
	while (i != 1) //루트가 되지 않을 때까지
	{
		if (h->node[i / 2].weight < item) //부모와 비교해서 아이템이 더 크면
		{
			h->node[i].weight = h->node[i / 2].weight; //부모 자식으로 내리고
			i /= 2; //현재 위치를 부모 위치로 한단계 올라간다.
		}

		if (h->node[i / 2].weight >= item) //아이템이 부모보다 작거나 같으면 
		{
			break; //그냥 그자리에 있기 
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

		if (temp < h->node[child].weight) //마지막 원소보다 자식이 더 크다면 
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

void print_heap(HeapType* h)
{
	printf("최대 히프: ");
	for (int i = 1;i <= h->heap_size;i++)
	{
		printf("%d ", h->node[i].weight);
	}
}

int main(void)
{
	HeapType* h = (HeapType*)malloc(sizeof(HeapType));
	init_heap(h);
	int a[MAX_NODE]; //히프 노드값은 MAX_NODE-1 (이유: 히프는 인덱스 1부터 노드가 시작해서)

	for (int i = 1;i <= 7;i++)
	{
		insert_max_heap(h, i); //1~6까지 최대 히프에 넣기 
	}

	for (int i = 1;i <= 7;i++) //3개 최대 히프에서 삭제 
	{
		a[i] = delete_max_heap(h);
	}
	printf("최대 히프결과 \n");

	for (int i = 1;i <= 7;i++)
	{
		printf("%d ", a[i]); //히프 뽑을 때 최대값만 뽑아져 나온다는게 핵심. 히프 그 자체를 그냥 출력하면 정렬 안됨ㅡㅡ 딜리트로 팝한값을
		//순서대로 배열에 모아야함 
		//히프의 조건. 부모 노드 키값 >= 자식 노드 키값 : 최대 히프 
	}

	return 0;
}