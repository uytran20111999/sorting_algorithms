#include<iostream>
#include<climits>
using namespace std;
void interchange_sort(int *a,int n){
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (a[i] > a[j])swap(a[i], a[j]);
		}
	}
}
void bubble_sort(int *a,int n){
	for (int i = 0; i < n - 1; i++) {
		for (int j = n-1; j > i ; j--) {
			if (a[j] < a[j - 1])swap(a[j], a[j -1]);
		}
	}
}
void insertion_sort(int*a,int n){
	for (int i = 1; i < n; i++) {
		int x = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > x) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}
void shaker_sort(int *a,int n){
	int l = 0;
	int r = n - 1;
	int k =l;
	while (l < r) {
		for (int i = r; i > l; i--) {
			if (a[i] < a[i - 1]) {
				swap(a[i], a[i - 1]);
				k = i;
			}
		}
		l = k;
		for (int j = l; j < r; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
				k = j;
			}
		}
		r = k;
	}
}
void selection_sort(int *a,int n){
	for (int i = 0; i < n-1; i++) {
		int idx = i;
		for (int j = i + 1; j < n; j++) {
			if (a[idx] > a[j])idx = j;
		}
		swap(a[idx], a[i]);
	}
}
void min_max_sort(int *a,int n){
	if (n > 0) {
		int idmin = 0;
		int idmax = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] < a[idmin]) { idmin = i; }
			if (a[i] > a[idmax]) { idmax = i; }
		}
		int temp = idmin;
		swap(a[idmin], a[0]);
		if (idmax == 0)swap(a[temp], a[n - 1]);
		min_max_sort(a + 1, n - 1);
	}
}
void shell_sort(int* a , int n){
	int k =n/8;
	if (k == 0)k = 1;
	while (k > 0) {
		for (int i = k; i < n; i = i + k) {
			int x = a[i];
			int j = i - k;
			while (j >= 0 && a[j] > x) {
				a[j + k] = a[j];
				j = j - k;
			}
			a[j + k] = x;
		}
		if (k == 2)k = 1;
		else k = (k - 1) / 2;
	}
}
void quick_sort_real(int *a, int L, int R) {
	int i = L;
	int j = R;
	int x = a[(L + R) / 2];
	do {
		while (i <= j) {
			while (a[i] < x)i++;
			while (a[j] > x)j--;
			if (i <= j) {
				swap(a[i++], a[j--]);
			}
		}
	} while (i <= j);
	if (j > L)quick_sort_real(a, L, j);
	if (i < R)quick_sort_real(a, i, R);
}
void quick_sort(int *a, int n) {
	quick_sort_real(a, 0, n - 1);
}
void merge(int *a,int L1,int R1,int L2,int R2){
	int n1 = R1 - L1 + 1;
	int n2 = R2 - L2 + 1;
	int * L = new int[n1 + 1];
	int * R = new int[n2 + 1];
	for (int i = 0; i < n1; i++) {
		L[i] = a[L1 + i];
	}
	for (int j = 0; j < n2; j++) {
		R[j] = a[L2 + j];
	}
	L[n1] = INT_MAX;
	R[n2] = INT_MAX;
	int i = 0;
	int j = 0;
	int n = n1 + n2;
	for (int k = L1; k <=R2; k++) {
		if (L[i] < R[j]) { a[k] = L[i++]; }
		else a[k] = R[j++];
	}
	delete[]L;
	delete[]R;
}
void merge_sort_real(int *a, int L,int R) {
	if (L<R) {
		int mid = (L + R) / 2;
		merge_sort_real(a, L, mid);
		merge_sort_real(a, mid + 1, R);
		merge(a,L,mid,mid+1,R);
	}
}
void merge_sort(int*a, int n) {
	merge_sort_real(a, 0, n - 1);
}
void counting_sort(int *a , int n){
	int max = 0;
	for (int i = 0; i < n; i++) { if (max < a[i])max = a[i]; }
	int * C = new int[max + 1];
	for (int i = 0; i <= max; i++)C[i] = 0;
	int * b = new int[n];
	for (int i = 0; i < n; i++)
	{
		C[a[i]] = C[a[i]] + 1;
	}
	for (int i = 1; i <= max; i++)
	{
		
		C[i] = C[i] + C[i - 1];
	}
	//for (int i = 0; i <= max; i++)cout << C[i] << '\t';
	//cout << endl;
	for (int i = n - 1; i >= 0; i--) {
		b[C[a[i]]-1] = a[i];
		C[a[i]] = C[a[i]] -1;
	}
	for (int i = 0; i < n; i++)a[i] = b[i];
	delete[]b;
	delete[]C;
}
void radix_sort(int *a ,int n){
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > max)max = a[i];
	}
	int d = 0;
	int temp = max;
	int pow = 1;
	while (temp) {
		temp = temp / 10;
		d++;
	}
	int i = 0;
	int *C = new int[10];
	int * B = new int[n];
	while (i < d) {
		for (int i = 0; i < 10; i++)C[i] = 0;
		for (int i = 0; i < n; i++)C[(a[i]/pow) % 10]++;
		for (int i = 1; i < 10; i++)C[i] = C[i] + C[i - 1];
		for (int i = n-1; i >=0; i--) {
			B[C[(a[i] / pow) % 10] - 1] = a[i];
			C[(a[i] / pow) % 10]--;
		}
		for (int i = 0; i < n; i++)a[i] = B[i];
		pow = pow * 10;
		i = i + 1;
	}
	delete[]C;
	delete[]B;
}
void heapify(int *a , int L , int R){
	int i = L;
	int k = 2 * i+1;
	while (k <= R) {
		if (k < R) {
			if (a[k] < a[k + 1])k++;
		}
		if (a[i] >= a[k])break;
		else {
			swap(a[k], a[i]);
			i = k;
			k = 2 * i + 1;
		}
	}
}
void creat_heap(int *a, int n) {
	int x = (n / 2) - 1;
	n = n - 1;
	while (x >= 0) {
		heapify(a, x, n);
		x--;
	}
}
void heap_sort(int *a,int n){
	creat_heap(a, n);
	n = n - 1;
	while (n > 0) {
		swap(a[n], a[0]);
		n--;
		heapify(a, 0, n);
	}
}
void main(){
	int b[] = {4,10,3,5,1};
	int nb = sizeof(b) / 4;
	int a[] = { 29,32,14,17,20,23,69,1,76,23,45,21 };
	int n = sizeof(a) / sizeof(int);
//	interchange_sort(a, n);
//	bubble_sort(a, n);
//	insertion_sort(a, n);
//	shaker_sort(a, n);
//	selection_sort(a, n);
//	min_max_sort(a, n);
//	shell_sort(a, n);
//	quick_sort(a, n);
//	merge_sort(a, n);
//	counting_sort(a, n);
//	radix_sort(a, n);
	heap_sort(b, nb);
	//creat_heap(b, nb);
	for (int i = 0; i < nb; i++)cout << b[i] << ' ';
}