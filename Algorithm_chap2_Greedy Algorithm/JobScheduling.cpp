#include <stdio.h>
#include <stdlib.h>
#define JOB 7 //작업은 총 7개
//작업의 수행 시간이 중복되지 않도록 모든 작업을 가장 적은 수에 배정하는 문제
//시작시간이 작은 순서대로 정렬되있는 작업 (s,e) j 리스트 l / 사용시간과 id가 있는 링크드 리스트 머신

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
	JobList* j = (JobList*)malloc(sizeof(JobList));
	int startTime=0;
	int endTime=0;

	for (int i = 0; i < JOB; i++)
	{
		startTime = 0; endTime = 0;

		printf("작업 [%d]의 시작시간과 종료시간을 입력해 주세요.\n",i);
		printf("시작시간 : "); scanf_s("%d", &startTime);
		printf("종료시간 : "); scanf_s("%d", &endTime);

		j->job[i].start = startTime;
		j->job[i].end = endTime;
	}

	//job[i].start 가 작은 순서대로 sort

	for (int i = 0; i < JOB; i++) //작업이 모두 끝날 때까지
	{
		//최소히프에서 한번 보고. seek 거기 사용시간이 현재 작업 시작시간보다 크면 사용가능한 머신이 없는거임.
		//사용가능한 머신이 없으면
		  //머신하나 생성후 거기에 할당.생성하고 증가시키고 그다음에 최소 히프에 넣기 
		  //머신 사용시간 job 시간만큼 증가.
		//사용가능한 머신이 있으면(최소히프에서 뽑기)
		  //머신 사용시간 job 시간만큼 증가
	}


	return 0;
}