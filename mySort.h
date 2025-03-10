#ifndef MYSORT_H
#define MYSORT_H

#include <vector>
#include <cstdlib>

namespace mysort {
// 冒泡排序
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for(int i=0;i<n;i++) {
        for(int j=0;j<n-i-1;j++) {
            if(arr[j]>arr[j+1]) std::swap(arr[j],arr[j+1]);
        }
    }
}  

// 插入排序
void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for(int i=1;i<n;i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    } 
}

// 选择排序
void selectionSort(std::vector<int>& arr) {
    int n = arr.size();
    for(int i=0;i<n-1;i++){
        int minIndex = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]) minIndex = j;
        }
        if(minIndex!=i) std::swap(arr[i],arr[minIndex]);
    }
}

// 快速排序
int partition(std::vector<int>&arr, int low, int high) {
    int pivot = arr[low];
    while(low<high) {
        while(low<high && arr[high]>=pivot) high--;
        arr[low] = arr[high];
        while(low<high && arr[low]<=pivot) low++;
        arr[high] = arr[low];
    }
    arr[low] = pivot;
    return low;
}

int randomized_partition(std::vector<int>& arr, int low, int high) {
    int i = rand() % (high - low + 1) + low; 
    std::swap(arr[low], arr[i]);
    return partition(arr, low, high);
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if(low<high) {
        int pi = randomized_partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
} 

// 归并排序
void mergeArray(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<int> L(n1), R(n2);
    for(int i=0;i<n1;i++) L[i] = arr[left+i];
    for(int i=0;i<n2;i++) R[i] = arr[mid+1+i];
    int i=0, j=0, k=left;
    while(i<n1 && j<n2) {
        if(L[i]<=R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while(i<n1) arr[k++] = L[i++];
    while(j<n2) arr[k++] = R[j++];
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if(left<right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        mergeArray(arr, left, mid, right);   
    }
}

// 堆排序
// 通过数组存储，从最后一个父节点开始遍历，调整堆，之后调整子树
void maxheapify(std::vector<int>& arr, int i, int n) {
    int left = 2*i + 1;
    int right = 2*i + 2;
    int largest = i;
    if(left<n && arr[left]>arr[largest]) largest = left;
    if(right<n && arr[right]>arr[largest]) largest = right;
    if(largest!=i) {
        std::swap(arr[i], arr[largest]);
        maxheapify(arr, largest, n);
    }
}

void heapSort(std::vector<int>& arr) {
    int n = arr.size();
    for(int i=n/2-1;i>=0;i--) maxheapify(arr, i, n);
    for(int i=n-1;i>=0;i--) {
        std::swap(arr[0], arr[i]);
        maxheapify(arr, 0, i);
    }
}

}
#endif