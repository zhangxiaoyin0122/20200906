#include <iostream>
#include <vector>
using namespace std;


void Swap(int* array, int left, int right) {
	int temp = array[left];
	array[left] = array[right];
	array[right] = temp;
}
bool FindNum(vector<vector<int>> v, int target) {
	size_t i = 0;
	int j = v[0].size() - 1;

	while (i < v.size() && j >= 0) {
		if (v[i][j] < target) {
			i++;
		}
		else if (v[i][j] > target) {
			j--;
		}
		else {
			return true;
		}
	}
	return false;
}

//桶排序
void countSort(int* array, int n) {
	//找出数组中最大和最小值
	int min = array[0];
	int max = array[0];
	for (int i = 1; i < n; i++) {
		if (array[i] > max)
			max = array[i];
		if (array[i] < min)
			min = array[i];
	}
	//开空间
	int range = max - min + 1;
	int* newH = (int*)malloc(sizeof(int)*range);
	//初始化为0
	memset(newH, 0, sizeof(int)*range);
	//计数
	for (int i = 0; i < n; i++) {
		newH[array[i] - min]++;
	}
	//恢复数组
	int idx = 0;
	for (int i = 0; i < range; i++) {
		while (newH[i]--) {
			array[idx++] = i + min;
		}
	}
	free(newH);
}

//冒泡排序
//void bubbleSort(int* array, int n) {
//	for (int i = 0; i < n - 1; i++) {
//		for (int j = 1; j < n-i; j++) {
//			if (array[j - 1] > array[j])
//				Swap(array, j - 1, j);
//		}
//	}
//}

//冒泡排序
void bubbleSort(int* array, int n) {
	while (n) {
		int flag = 1;
		for (int i = 0; i < n - 1; i++) {
			if (array[i] > array[i + 1]) {
				Swap(array, i, i + 1);
				flag = 0;
			}
		}
		if (flag == 1)
			break;
		n--;
	}
}

//利用向下调整建堆
void shiftDown(int* array, int n,int parent) {
	int child = parent * 2 + 1;
	while (child < n) {
		if (child + 1 < n && array[child] < array[child + 1])
			child++;
		if (array[child] > array[parent])
			Swap(array, parent, child);
		else
			break;
	}
}
//堆排序
void heapSort(int* array, int n) {
	//建堆
	for (int i = (n - 2) / 2; i >= 0; i--) {
		shiftDown(array, n, i);
	}
	while (n) {
		Swap(array, 0, n - 1);
		n--;
		shiftDown(array, n, 0);
	}
}

void print(int* array,int n) {
	for (int i = 0; i < n;i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}
int main() {
	int array[] = { 4,5,9,6,7,3,2,8,1 };
	int size = sizeof(array) / sizeof(array[0]);
	print(array, size);
	//countSort(array, size);
	//bubbleSort(array, size);
	heapSort(array, size);
	print(array, size);
	return 0;
}