#ifndef MYSORT_H
#define MYSORT_H

#include <vector>

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

// 快排
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

}
#endif