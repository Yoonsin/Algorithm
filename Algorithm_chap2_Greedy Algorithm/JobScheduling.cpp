#include <stdio.h>
#include <stdlib.h>
#define JOB 7 //�۾��� �� 7��
//�۾��� ���� �ð��� �ߺ����� �ʵ��� ��� �۾��� ���� ���� ���� �����ϴ� ����
//���۽ð��� ���� ������� ���ĵ��ִ� �۾� (s,e) j ����Ʈ l / ���ð��� id�� �ִ� ��ũ�� ����Ʈ �ӽ�

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
	JobList* j = (JobList*)malloc(sizeof(JobList));
	int startTime=0;
	int endTime=0;

	for (int i = 0; i < JOB; i++)
	{
		startTime = 0; endTime = 0;

		printf("�۾� [%d]�� ���۽ð��� ����ð��� �Է��� �ּ���.\n",i);
		printf("���۽ð� : "); scanf_s("%d", &startTime);
		printf("����ð� : "); scanf_s("%d", &endTime);

		j->job[i].start = startTime;
		j->job[i].end = endTime;
	}

	//job[i].start �� ���� ������� sort

	for (int i = 0; i < JOB; i++) //�۾��� ��� ���� ������
	{
		//�ּ��������� �ѹ� ����. seek �ű� ���ð��� ���� �۾� ���۽ð����� ũ�� ��밡���� �ӽ��� ���°���.
		//��밡���� �ӽ��� ������
		  //�ӽ��ϳ� ������ �ű⿡ �Ҵ�.�����ϰ� ������Ű�� �״����� �ּ� ������ �ֱ� 
		  //�ӽ� ���ð� job �ð���ŭ ����.
		//��밡���� �ӽ��� ������(�ּ��������� �̱�)
		  //�ӽ� ���ð� job �ð���ŭ ����
	}


	return 0;
}