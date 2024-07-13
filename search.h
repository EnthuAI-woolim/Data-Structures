#include <stdio.h>
#include <string.h>

// 반복적인 이진 검색 알고리즘
int BinarySearchIterative(int A[], int n, int data) {
    int low = 0;
    int high = n - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if (A[mid] == data) 
            return mid;
        else if (A[mid] < data) 
            low = mid + 1;
        else 
            high = mid - 1;
    }
    return -1;
}

// 재귀적인 이진 검색 알고리즘
int BinarySearchRecursive(int A[], int low, int high, int data) {
    if (low >= high) return -1;
    int mid = (low + high) / 2;
    
    if (A[mid] == data) 
        return mid;
    else if (A[mid] < data) 
        BinarySearchRecursive(A, mid+1, high, data);
    else 
        BinarySearchRecursive(A, low, mid-1, data);
}