#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>
#include "mySort.h"

using namespace std;

void testSortingAlgorithm(const string& name, void (*sortFunc)(vector<int>&)) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 100);
    std::vector<int> arr(100);
    for(int i=0;i<100;i++) arr[i] = dis(gen);

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

    auto quickSortTest = [](vector<int>& arr) {
        mysort::quickSort(arr, 0, arr.size()-1);
    };

    testSortingAlgorithm("Quick Sort", quickSortTest);

    return 0;
}