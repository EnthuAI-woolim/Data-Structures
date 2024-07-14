#include <stdio.h>
#include <string.h>

// Bubble Sort / O(n^2), O(n^2)
void BubbleSort(int A[], int n) { // 오름차순 정렬
    int pass, i, temp, swapped = 1;
    for(pass = n-1; pass >= 0 && swapped; pass--) {
        swapped = 0;
        for (i = 0; i < pass; i++) {
            if (A[i] > A[i+1]) { 
                // 항목을 교환한다.
                temp = A[i];
                A[i] = A[i+1];
                A[i+1] = temp;
                swapped = 1;
            }
        }
    }
}

// Selection Sort / O(n^2), O(n^2)
void Selection(int A[], int n) {
    int i, j, min, temp;
    for (i = 0; i < n-1; i++) {
        min = i;
        for (j = i+1; j < n; j++) {
            if (A[j] < A[min]) min = j;
        }
        // 항목을 교환한다.
        temp = A[min];
        A[min] = A[i];
        A[i] = temp;
    }
}

// Insertion Sort / O(n) or O(n^2), O(n^2)
void InsertionSort(int A[], int n) {
    int i, j, v;
    for (i = 1; i < n; i++) {
        v = A[i];
        j = i;
        while (j >= 1 && A[j-1] > v) {
            A[j] = A[j-1];
            j--;
        }
        A[j] = v;
    }
}

// Merge Sort / O(nlogn), O(nlogn)
void MergeSort(int A[], int temp[], int left, int right) {
    int mid;
    if (right > left) {
        mid = (right + left) / 2;
        MergeSort(A, temp, left, mid);
        MergeSort(A, temp, mid+1, right);
        Merge(A, temp, left, mid+1, right);
    }
}

void Merge(int A[], int temp[], int left, int mid, int right) {
    int i, left_end, size, temp_pos;
    left_end = mid - 1;
    temp_pos = left;
    size = right - left + 1;

    while ((left <= left_end) && (mid <= right)) { // left쪽과 right쪽 모두 남아있다면
        if (A[left] <= A[mid]) {
            temp[temp_pos] = A[left];
            temp_pos++;
            left++;
        } else {
            temp[temp_pos] = A[mid];
            temp_pos++;
            mid++;
        }
    }
    while (left <= left_end) { // left쪽이 남아있다면
        temp[temp_pos] = A[left];
        temp_pos++;
        left++;
    }
    while (mid <= right) { // right쪽이 남아있다면
        temp[temp_pos] = A[mid];
        temp_pos++;
        mid++;
    }
    for (i = 0; i <= size; i++) { // temp[]에서 A[]로 다시 copy
        A[right] = temp[right];
        right--;
    }
}

// Heap Sort / O(nlogn), O(nlogn)


// Quick Sort / O(nlogn), O(n^2)
void QuickSort(int A[], int low, int high) {
    int pivot;
    if (high >= low) {
        pivot = Partition(A, low, high);
        QuickSort(A, low, pivot-1);
        QuickSort(A, pivot+1, high);
    }
}

int Partition(int A[], int low, int high) {
    int left, right, pivot_item = A[low];
    left = low;
    right = high;
    while (left <= right) {
        /* item <= pivot인 동안 왼쪽으로 옮긴다 */
        while (left <= right && A[left] <= pivot_item) 
            left++;
        /* item > pivot인 동안 오른쪽으로 옮긴다 */
        while (left <= right && A[right] > pivot_item) 
            right--;
        if (left < right) swap(A, left, right);
    }
    /* right가 마지막 pivot의 위치이다 */
    A[low] = A[right];
    A[right] = pivot_item;
    return right;
}

void swap(int A[], int left, int right) {
    int temp = A[left];
    A[left] = A[right];
    A[right] = temp;
}