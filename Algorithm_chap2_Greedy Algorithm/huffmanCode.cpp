#include <stdio.h>
#include <stdlib.h>
#define MIN_HEAP 4

char monza[MIN_HEAP + 1][10] = { "" }; //열글자 배열 MIN_HEAP 갯수만큼 생성 및 전부다 NULL로 초기화
int index=0; //현재 인덱스

//최소 히프
typedef struct Node {
	int weight;
	char cr;
	Node* right;
	Node* left;
}Node;

typedef struct HeapType {
	Node node[MIN_HEAP+1]; //인덱스 1부터 접근하니까 배열 크기도 +1 해줘야함
	int heap_size; //히프안에 노드가 몇개 있는지
}HeapType;

//트리 
typedef struct Tree {
	Node* right;
	Node* left;
	Node* root;
}Tree;


void InsertMinHeap(HeapType* h,Node n)
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

Node* bulidHuffmanTree(HeapType* h)
{
	//Node node_1 = DeleteMinHeap(h); pop의 주소값 == node_1의 주소값??

	Node* finalRoot = (Node*)malloc(sizeof(Node));

	for (int i = 0; i < MIN_HEAP - 1; i++) //히프 크기-1만큼 반복 (히프에서 2개씩 뽑는거니까)
	{ //어떻게 노드를 새로 생성시키지? 그대로 배껴쓰지 않고???

		Node node_1 = DeleteMinHeap(h); 
		Node node_2 = DeleteMinHeap(h);

		Node* rootNode = (Node*)malloc(sizeof(Node));
		rootNode->weight = node_1->weight + node_2->weight;
		rootNode->cr = '\0';

		rootNode->left = node_1;
		rootNode->right = node_2; //트리 만들고

		InsertMinHeap(h, rootNode); //루트 다시 민힙에 넣기 

		if (i == MIN_HEAP - 2) //루프가 마지막이면
		{
			finalRoot = rootNode; //마지막 루트, 즉 허프만트리의 맨 위 노드 주기
		}

	}
	return finalRoot;
	
}


void printfTree(Node* t,char (* monza)[10]) //배열포인터는 배열을 가리키는 '하나'의 포인터
{
	int k = 0;

	if (t->right == NULL && t->left == NULL) //말단 노드면
	{
		return; //끝내기
	}

	//허프만 코드 출력은 안에 알파벳이 있을때만 출력해주면 됨
	if (t->cr)
	{
		printf("알파벳 %c의 허프만 코드 : %s ", t->cr, monza[index] );
	}

	//왼쪽 노드에 값있으면 호출하기
	if (t->left)
	{
		//현재노드 인덱스x2 가 왼쪽 노드의 인덱스
		k = 0;
		while (monza[index][k] != '\0') //null만나지 않을 때까지 반복
		{
			monza[index * 2][k] = monza[index][k]; //현재 허프만 코드를 자식 노드에게 넘겨주고
			k++;
		}
		index *=2;
		monza[index][k] = '0';
	

		
		printfTree(t, monza);
		
	}

	//오른쪽 노드에 값있으면 호출하기
	if (t->right)
	{
		//현재노드 인덱스x2+1 가 왼쪽 노드의 인덱스
		k = 0;
		while (monza[index][k] != '\0') //null만나지 않을 때까지 반복
		{
			monza[index * 2][k] = monza[index][k]; //현재 허프만 코드를 자식 노드에게 넘겨주고
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
	Tree* t = (Tree*)malloc(sizeof(HeapType) * MIN_HEAP - 1); //트리는 MIN_HEAP-1갯수만큼 만들어짐 맨 끝 트리가 마지막 트리

	Node node_insert;

	char cr='\0'; int num=0; 
	 int last=0;

	h->heap_size = 0; //히프 초기화

	//알파벳과 정수를 받아준뒤, insertminheap 함수로 그 값들 삽입 MAX_HEAP만큼 반복.이것도 포인터로 받아줘야하나
	for (int i = 0; i < MIN_HEAP; i++)
	{
		printf("알파벳를 입력해주세요: ");
		scanf_s("%c", &cr, sizeof(cr));
		printf("빈도수를 입력해주세요: ");
		scanf_s("%d", &num);
		getchar(); //버퍼 비우기
		
		node_insert.weight = num; node_insert.cr = cr; //입력한거 노드에 넣기
		InsertMinHeap(h, node_insert); //그 노드 최소히프에 넣기
		
	}
	
	
	Node* ft = bulidHuffmanTree(h);


	printfTree(ft, monza);

	return 0;
}