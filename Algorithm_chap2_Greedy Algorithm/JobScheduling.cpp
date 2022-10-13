#include <stdio.h>
#include <stdlib.h>
#define MAX_NODE 8;
#define JOB 7 //작업은 총 7개
//작업의 수행 시간이 중복되지 않도록 모든 작업을 가장 적은 수에 배정하는 문제
//시작시간이 작은 순서대로 정렬되있는 작업 (s,e) j 리스트 l / 사용시간과 id가 있는 링크드 리스트 머신

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
		if (h->node[i / 2].weight > item) //부모와 비교해서 아이템이 더 작으면
		{
			h->node[i].weight = h->node[i / 2].weight; //부모 자식으로 내리고
			i /= 2; //현재 위치를 부모 위치로 한단계 올라간다.
		}

		if (h->node[i / 2].weight <= item) //아이템이 부모보다 크거나 같으면 
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

int seek_max_heap(HeapType* h)
{
	return h->node[1].weight;
}

typedef struct Job
{
	int start; //시작시간
	int end; //종료시간

}Job;

typedef struct JobList
{
	Job job[JOB];
}JobList;

typedef struct Machine
{
	int availTime; //사용시간
	int id; //id
};

int main(void)
{
	HeapType* h = (HeapType*)malloc(sizeof(HeapType)); //최소 히프
	JobList* j = (JobList*)malloc(sizeof(JobList));
	int startTime=0;
	int endTime=0;

	for (int i = 0; i < JOB; i++)
	{
		j->job[i].start = i;
		j->job[i].end = i + 3;

		
		/*startTime = 0; endTime = 0;

		printf("작업 [%d]의 시작시간과 종료시간을 입력해 주세요.\n",i);
		printf("시작시간 : "); scanf_s("%d", &startTime);
		printf("종료시간 : "); scanf_s("%d", &endTime);

		j->job[i].start = startTime;
		j->job[i].end = endTime;*/
	}

	//job[i].start 가 작은 순서대로 sort 일단 sort는 나중에 

	for (int i = 0; i < JOB; i++) //작업이 모두 끝날 때까지
	{
		//최소히프에서 한번 보고. seek 거기 사용시간이 현재 작업 시작시간보다 크면 사용가능한 머신이 없는거임.
		if (j->job[i].start > seek_max_heap(h))//사용가능한 머신이 없으면
		{

		}
		else //사용가능한 머신이 있으면(최소히프에서 뽑기)
		{

		}
		
		
		  //머신하나 생성후 거기에 할당.생성하고 증가시키고 그다음에 최소 히프에 넣기 
		  //머신 사용시간 job 시간만큼 증가.
		
		  //머신 사용시간 job 시간만큼 증가
	}


	return 0;
}