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
    // std::vector<int> arr = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    cout << "original arr: ";
    for(int num:arr) cout << num << " ";
    cout << endl;
    
    // 计时
    auto start = chrono::high_resolution_clock::now();
    sortFunc(arr);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double,milli> duration = end - start;
    
    cout << name << " sorted arr: ";
    for(int num:arr) cout << num << " ";
    cout << endl;
    cout << name << " time consumed: " << duration.count() << " ms" << endl;

    bool isSorted = is_sorted(arr.begin(), arr.end());
    cout << name << " isSorted: " << (isSorted ? "YES" : "NO") << endl;
    cout << "---------------------------------" << endl;
}

int main() {
    testSortingAlgorithm("Bubble Sort", mysort::bubbleSort);
    testSortingAlgorithm("Insertion Sort", mysort::insertionSort);
    testSortingAlgorithm("Selection Sort", mysort::selectionSort);

    auto quickSortTest = [](vector<int>& arr) {
        mysort::quickSort(arr, 0, arr.size()-1);
    };
    testSortingAlgorithm("Quick Sort", quickSortTest);

    auto mergeSortTest = [](vector<int>& arr) {
        mysort::mergeSort(arr, 0, arr.size()-1);
    };
    testSortingAlgorithm("Merge Sort", mergeSortTest);

    testSortingAlgorithm("Heap Sort", mysort::heapSort);

    return 0;
}