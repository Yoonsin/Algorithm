#include <stdio.h>

int arr[10] = { 6, 3, 11, 9, 12, 2, 8, 15,4,10};

void QuickSort(int* arr, int start, int end, int k)
{
	if (start == end) //스몰그룹이 1개일경우
	{
		printf("%d", arr[start]); //그냥 그거 출력하면 됨
		//return;
		return;
	}

	int pivot = start;
	int i = start + 1;
	int j = end; //start와 end를 가리키는 포인터 두개
	int temp = 0;

	while (i <= j) //서로 엇갈릴 때까지 반복
	{
		while (i <= end && arr[i] <= arr[pivot]) //끝을 넘지 않고, 피봇값보다 작거나 같으면
		{
			i++; //계속 포인터 늘려주기
		}

		while (j > start && arr[j] >= arr[pivot]) //시작을 넘지않고, 피봇값보다 크거나 같으면
		{
			j--; //계속 포인터 늘려주기
		}

		if (i > j) //서로 엇갈리면
		{
			temp = arr[pivot];
			arr[pivot] = arr[j];
			arr[j] = temp; //피봇과 값 교환..근데 arr[j]값과 피봇과 교환하지..?
		}
		else //아니면
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp; //i와 j 서로 스왑
		}
	}

	int s = j - start;


	if (k<=s)
	{
		QuickSort(arr, start, j - 1,k);
	}
	else if (k == s+1)
	{
		printf("%d", arr[j]);
		//return;
	
	}
	else
	{
		QuickSort(arr, j+1, end, k-(s+1));
	}



}


int main(void)
{
	int k = 8;
	printf("%d 번째 숫자 ", k);
	QuickSort(arr, 0, 9,k);

	
	


	return 0;
}