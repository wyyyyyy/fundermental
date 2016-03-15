// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void insert_sort(int arr[], int arr_len);
void select_sort(int arr[], int arr_len);
void merge_sort(int arr[], int arr_len);
void do_merge_sort(int arr[], int tmp[], int len);
void do_merge_sort_iterative(int arr[], int tmp[], int len);

int main(int argc, char * argv[])
{
	int arr[] = { 5,3,7,30,1,62,9,9,22,49};
	int arr_len = sizeof(arr)/sizeof(int);
	//insert_sort(arr, arr_len);
	//select_sort(arr, arr_len);
	merge_sort(arr, arr_len);
	cout << "Hello, World!" << endl;
	for (int i = 0; i < arr_len; i++) {
		cout << arr[i] << endl;
	}

	
}


/*��������-�����򣬱Ƚϴ����븳ֵ������������1+2+...+n ~ O(n^2), ��1,2,3....,n��ƽ�������һ����ڵ�ǰ�����ַ���һ��С�ڣ�Ҳ��~O(n^2)*/
void insert_sort(int arr[], int arr_len) {
	int i,j,k;
	for (i = 1; i < arr_len; i++) {
		j = arr[i];
		k = i-1;
		while (j > arr[k] && k>=0) {
			arr[k + 1] = arr[k];
			k--;
		}
		arr[k + 1] = j;
	}
}

/*ѡ������, �Ƚϴ���������ΪO(n^2)����ֵ�����ϲ��������١�ƽ���������������ͬ����Ϊ��Ҫ�Ƚ�n-i�Σ����ܲ���Ҫ���������Ӷ���ΪO(n^2)*/
void select_sort(int arr[], int arr_len) {
	int i, j, min, min_idx;
	for (i = 0; i < arr_len - 1; i++) {		//�ҵ���iС�ģ����ڵ�i-1λ
		min = arr[i];
		min_idx = i;
		for (j = i + 1; j < arr_len; j++) {
			if (arr[j] < min) {
				min = arr[j];
				min_idx = j;
			}
		}
		arr[min_idx] = arr[i];
		arr[i] = min;
	}
}

/*�鲢����******************************************************************************/
void merge_sort(int arr[], int arr_len) {
	int tmp[30];
	//do_merge_sort(arr, tmp, arr_len);
	do_merge_sort_iterative(arr, tmp, arr_len);
	return;
}

void do_merge_sort(int arr[], int tmp[], int len) {
	int i=0, left_start=0, left_end, right_start, right_end=len-1, mid;
	
	if (len <= 1)
		return;
	
	mid = len >> 1;
	left_end = mid-1;
	right_start = mid;
	
	do_merge_sort(arr, tmp, left_end - left_start+1);
	do_merge_sort(arr + right_start, tmp + right_start, right_end - right_start + 1);

	while (left_start <= left_end && right_start <= right_end) {
		tmp[i++] = (arr[left_start] > arr[right_start]) ? arr[left_start++] : arr[right_start++];
	}
	while (left_start <= left_end) {
		tmp[i++] = arr[left_start++];
	}
	while (right_start <= right_end) {
		tmp[i++] = arr[right_start++];
	}
	
	for (i = 0; i < len; i++) {
		arr[i] = tmp[i];
	}
}

void do_merge_sort_iterative(int arr[], int tmp[], int len) {
	int i,cur,step,left_start,left_end, right_start, right_end;
	for (step = 1; step < len; step += step) {
		i = 0;
		for (cur = 0; cur < len; cur += 2*step) {
			left_start = cur;
			left_end = ((left_start + step)>=len) ? (len) : (left_start + step);
			right_start = ((left_start + step) >= len) ? (len) : (left_start + step);
			right_end = ((left_start + step*2)>=len) ? (len) : (left_start + step*2);
			while (left_start < left_end && right_start < right_end) {
				tmp[i++] = (arr[left_start]>arr[right_start]) ? arr[left_start++] : arr[right_start++];
			}
			while (left_start < left_end) {
				tmp[i++] = arr[left_start++];
			}
			while (right_start < right_end) {
				tmp[i++] = arr[right_start++];
			}
		}
		for (i = 0; i < len; i++) {
			arr[i] = tmp[i];
		}
	}
}