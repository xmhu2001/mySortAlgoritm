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
  
} 
#endif