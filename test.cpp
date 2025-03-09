#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <algorithm>
#include "mySort.h"

using namespace std;

void testSortingAlgorithm(const string& name, void (*sortFunc)(vector<int>&)) {
    vector<int> arr = {3, 2, 1, 5, 4, 9, 11, 7, 21, 0};
    cout << "原始数组: ";
    for(int num:arr) cout << num << " ";
    cout << endl;
    
    // 计时
    auto start = chrono::high_resolution_clock::now();
    sortFunc(arr);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double,milli> duration = end - start;
    
    cout << name << " 排序后的数组: ";
    for(int num:arr) cout << num << " ";
    cout << endl;
    cout << name << " 排序耗时: " << duration.count() << " 毫秒" << endl;

    bool isSorted = is_sorted(arr.begin(), arr.end());
    cout << name << " 是否排序: " << (isSorted ? "YES" : "NO") << endl;
}

int main() {
    testSortingAlgorithm("Bubble Sort", mysort::bubbleSort);
    return 0;
}