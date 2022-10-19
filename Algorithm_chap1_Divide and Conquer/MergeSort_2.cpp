#include <stdio.h>

void merge(int *a, int low, int mid, int hight) //병합
{
	int b[6];
	int i = low; //왼쪽 시작
	int j = mid + 1; //오른쪽 시작
	int k = 0; //배열 b의 인덱스 값

	while (i <= mid && j <= hight)
	{
		if (a[i] <= a[j]) //분리된 왼쪽 배열과 오른쪽 배열 비교. 오른쪽 배열 요소가 더 작으면
			b[k++] = a[i++]; //그거 넣기
		else
			b[k++] = a[j++];
	}

	while (i <= mid)
		b[k++] = a[i++]; //비교하지 않은 왼쪽 배열이 있다면 배열 b에 전부 채우기
	while (j <= hight)
		b[k++] = a[j++]; //비교하지 않은 오른쪽 배열이 있다면 배열 b에 전부 채우기

	k--; //k++ 됬으니까 1개 줄여야됨.

	while (k>=0) //배열 b 내용을 배열 a 내용에 덮어 쓰기
	{
		a[low + k] = b[k]; //..?? 이거 왼쪽인 low가 0이 아닐수도 있으니까 이렇게 쓴거겠지?
		k--;
	}

}

void mergeSort(int* a, int low, int hight) //배열의 요소를 분할하는 함수
{
	int mid;
	if (low < hight) //원소 갯수가 2개 이상일때만
	{
		mid = (low + hight) / 2;
		mergeSort(a, low, mid);//왼쪽 배열의 요소 분리
		mergeSort(a, mid + 1, hight); //오른쪽 배열의 요소 분리
		merge(a, low, mid, hight); //분리된 배열 정렬 및 병합 함수
	}
}

int main(void)
{
	int arr[6] = { 3,4,5,2,1,6 };

	mergeSort(arr, 0, 6 - 1);

	for (int i = 0; i < 6; i++)
	{
		printf("%d ", arr[i]);
	}
}