#include <stdio.h>



int Selection(int* arr, int left, int right, int k)
{
	if (left == right)
	{
		return (arr[left]);
	}

	int pivot = (left + right) / 2;
	int high = left + 1;
	int low = right; //왼쪽과 오른쪽의 포인터

	int temp = 0;

	temp = arr[pivot];
	arr[pivot] = arr[left];
	arr[left] = temp;

	while (high <= low)
	{
		while ((high <= right) && (arr[high] <= arr[left]))
		{
			high++;
		}
		while ((low >= left) && (arr[low] >= arr[left]))
		{
			low++;
		}

		if (high > low) //엇갈리면
		{
			break;
		}
		else
		{
			temp = arr[low];
			arr[low] = arr[high];
			arr[high] = temp;
		}
	}

	temp = arr[left];
	arr[left] = arr[low];
	arr[low] = temp;

	int s = low - left; //pivot - left. 인덱스를 빼줬기 때문에 여기서 +1을 해야 k와 같아짐
	if (k <= s)
	{
		Selection(arr, left, low - 1, k);
	}
	else if (k == s + 1)
	{
		return arr[low];
	}
	else
	{
		Selection(arr, low + 1, right, k - (s + 1)); //s그룹에다가 피봇까지 빼줘야함
	}
		


}

int main(void)
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int k = 7;

	printf("%d th number: ", k);
	printf(" %d", Selection(arr, 0, 9, k));

	return 0;
}