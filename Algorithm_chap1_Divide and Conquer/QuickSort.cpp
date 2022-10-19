#include <stdio.h>
#define MAX 3 //배열의 원소 갯수 미리 지정

int arr[MAX]; //정렬할 배열 선언


void QuickSort(int* arr, int left, int right)
{
	if (left >= right)
	{
		return; //만약 left가 right보다 크거나 같으면 더이상 할필요 없음. 탈출. 
	}

	int temp = 0; //바꿀때 필요한 임시값 변수
	int pivot = left + right / 2; //피봇의 인덱스는 중앙값으로 설정
	int l = left; int r = right; //left랑 right는 서로 값 바꿔줄 때 사용해야 하니 미리 arr의 맨 왼쪽이랑 오른쪽 인덱스 저장하기

	temp = arr[pivot];
	arr[pivot] = arr[left];
	arr[left] = temp; //피봇이란 맨 왼쪽값 바꾸기

	pivot = left;  //일단 피봇은 맨 왼쪽에 놓고
	left++; //왼쪽 인덱스 한칸 늘리기

	// 피봇 왼쪽           오른쪽  <- arr의 현재 인덱스 상태

	int leftFlag = 0, rightFlag = 0; //왼쪽/오른쪽에서 피봇과 비교해서 더 작거나/크면 바뀜상태로 표시해줌(바꾸지 않고 인덱스가 다음으로 넘어가면 안되니까!!)


	while (1) //왼쪽과 오른쪽 인덱스가 한칸씩 당기며 중앙으로 와야됨
	{


		if (!leftFlag && arr[left] > arr[pivot]) //현재 왼쪽이 바뀜상태가 아니고, 왼쪽 값이 피봇보다 크다면
		{
			leftFlag = 1; //바뀜상태로 바꿔줌
		}
		else if (!leftFlag) //그냥 바뀜상태가 아니라면
		{
			left++; //인덱스 한칸 늘리기
		}
		//바뀜 상태라면 인덱스 늘리지 말고 그냥 냅두기


		if (!rightFlag && arr[right] < arr[pivot]) //현재 오른쪽이 바뀜상태가 아니고, 오른쪽 값이 피봇보다 작다면
		{
			rightFlag = 1; //바뀜상태로 바꿔줌
		}
		else if (!rightFlag) //그냥 바뀜상태가 아니라면
		{
			right--; //인덱스 한칸 늘리기

		}
		//바뀜 상태라면 인덱스 늘리지 말고 그냥 냅두기


		if (leftFlag && rightFlag) //둘다 바뀜 상태라면 서로 바꾸기
		{
			temp = arr[right];
			arr[right] = arr[left];
			arr[left] = temp;

			leftFlag = 0; rightFlag = 0; //바꿨으니 다시 false로 변환
		}

		if (left + 1 == right) //만약 둘이 바로 옆에 붙어있다면
		{
			break; //탈출 
		}

	}

	temp = arr[left];
	arr[left] = arr[pivot];
	arr[pivot] = temp; //피봇값이랑 left서로 교환

	pivot = left; // 인덱스도 옮겨가기

	QuickSort(arr, l, pivot - 1);
	QuickSort(arr, pivot + 1, r);

}


int main(void)
{


	for (int i = 0; i < MAX; i++)
	{
		scanf_s("%d", &arr[i]); //값 넣어주기
	}

	QuickSort(arr, 0, MAX - 1); //퀵 정렬 함수 호출 

	for (int i = 0; i < MAX; i++)
	{
		printf("%d ", arr[i]); //값 출력
	}


	return 0;
}