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

//Ͱ����
void countSort(int* array, int n) {
	//�ҳ�������������Сֵ
	int min = array[0];
	int max = array[0];
	for (int i = 1; i < n; i++) {
		if (array[i] > max)
			max = array[i];
		if (array[i] < min)
			min = array[i];
	}
	//���ռ�
	int range = max - min + 1;
	int* newH = (int*)malloc(sizeof(int)*range);
	//��ʼ��Ϊ0
	memset(newH, 0, sizeof(int)*range);
	//����
	for (int i = 0; i < n; i++) {
		newH[array[i] - min]++;
	}
	//�ָ�����
	int idx = 0;
	for (int i = 0; i < range; i++) {
		while (newH[i]--) {
			array[idx++] = i + min;
		}
	}
	free(newH);
}

//ð������
//void bubbleSort(int* array, int n) {
//	for (int i = 0; i < n - 1; i++) {
//		for (int j = 1; j < n-i; j++) {
//			if (array[j - 1] > array[j])
//				Swap(array, j - 1, j);
//		}
//	}
//}

//ð������
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

//�������µ�������
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
//������
void heapSort(int* array, int n) {
	//����
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