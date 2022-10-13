#include <stdio.h>
#include <stdlib.h>
#define MAX_NODE 8;
#define JOB 7 //�۾��� �� 7��
//�۾��� ���� �ð��� �ߺ����� �ʵ��� ��� �۾��� ���� ���� ���� �����ϴ� ����
//���۽ð��� ���� ������� ���ĵ��ִ� �۾� (s,e) j ����Ʈ l / ���ð��� id�� �ִ� ��ũ�� ����Ʈ �ӽ�

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
		if (h->node[i / 2].weight > item) //�θ�� ���ؼ� �������� �� ������
		{
			h->node[i].weight = h->node[i / 2].weight; //�θ� �ڽ����� ������
			i /= 2; //���� ��ġ�� �θ� ��ġ�� �Ѵܰ� �ö󰣴�.
		}

		if (h->node[i / 2].weight <= item) //�������� �θ𺸴� ũ�ų� ������ 
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

int seek_max_heap(HeapType* h)
{
	return h->node[1].weight;
}

typedef struct Job
{
	int start; //���۽ð�
	int end; //����ð�

}Job;

typedef struct JobList
{
	Job job[JOB];
}JobList;

typedef struct Machine
{
	int availTime; //���ð�
	int id; //id
};

int main(void)
{
	HeapType* h = (HeapType*)malloc(sizeof(HeapType)); //�ּ� ����
	JobList* j = (JobList*)malloc(sizeof(JobList));
	int startTime=0;
	int endTime=0;

	for (int i = 0; i < JOB; i++)
	{
		j->job[i].start = i;
		j->job[i].end = i + 3;

		
		/*startTime = 0; endTime = 0;

		printf("�۾� [%d]�� ���۽ð��� ����ð��� �Է��� �ּ���.\n",i);
		printf("���۽ð� : "); scanf_s("%d", &startTime);
		printf("����ð� : "); scanf_s("%d", &endTime);

		j->job[i].start = startTime;
		j->job[i].end = endTime;*/
	}

	//job[i].start �� ���� ������� sort �ϴ� sort�� ���߿� 

	for (int i = 0; i < JOB; i++) //�۾��� ��� ���� ������
	{
		//�ּ��������� �ѹ� ����. seek �ű� ���ð��� ���� �۾� ���۽ð����� ũ�� ��밡���� �ӽ��� ���°���.
		if (j->job[i].start > seek_max_heap(h))//��밡���� �ӽ��� ������
		{

		}
		else //��밡���� �ӽ��� ������(�ּ��������� �̱�)
		{

		}
		
		
		  //�ӽ��ϳ� ������ �ű⿡ �Ҵ�.�����ϰ� ������Ű�� �״����� �ּ� ������ �ֱ� 
		  //�ӽ� ���ð� job �ð���ŭ ����.
		
		  //�ӽ� ���ð� job �ð���ŭ ����
	}


	return 0;
}