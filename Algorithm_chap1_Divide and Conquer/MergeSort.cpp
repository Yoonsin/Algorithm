#include <stdio.h>

int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };


void Merge(int *arr,int start,int mid,int end) //합병
{
	int b[11];
	int k = 0; //b의 인덱스 변수

	int i = start; //왼쪽 시작 
	int j = mid + 1; //오른쪽 시작
	


	while (i <= mid && j <= end) //i는 mid까지
	{
		if (arr[i] <= arr[j]) //왼쪽 배열 요소가 더 작으면
		{
			b[k++] = arr[i++];
		}
		else //오른쪽 배열 요소가 더 작으면
		{
			b[k++] = arr[j++];
		}
	}

	while (i <= mid)
		b[k++] = arr[i++]; //비교하지 않은 왼쪽 배열이 있다면 배열 b에 전부 채우기

	while (j <= end)
		b[k++] = arr[j++]; //비교하지 않은 오른쪽 배열이 있다면 배열 b에 전부 채우기

	k--; //마지막에 k++되니까 -1줘야됨

	while (k>=0)
	{
		arr[start + k] = b[k]; //..?? 이거 왼쪽인 low가 0이 아닐수도 있으니까 이렇게 쓴거겠지?
		k--;
	}
}


void MergeSort(int *arr,int start,int end) //분할
{
	int mid;
	
	if (start < end) //갯수가 2개이상 차이날때만 조건문 안의 분할 실행
	{
		mid = (start + end) / 2; //왜 mid는 mergesort에 넣지 않고 그냥 여기서 실행할까?*/
		MergeSort(arr, start,mid);
		MergeSort(arr,mid+1,end );
		Merge(arr, start, mid, end);
	}

}

int main(void)
{
	MergeSort(arr, 0,9);

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}