#include <bits/stdc++.h>

#include "algorithms.h"
#include "pokemon.h"
#include "files.h"

//utility function for printing out a vector
template <typename T>
void printVector(std::vector<T>& vector){
    for(auto i : vector){
        std::cout << i << std::endl;
    }

    std::cout << '\n';
}

template <std::totally_ordered T>
void testQuickSort(std::vector<T> data){
    std::cout << "Before QuickSort: ";
    printVector(data);

    QuickSort<Pokemon> quickSorter;
    quickSorter.sort(data);

    std::cout << "After QuickSort: ";
    printVector(data);
}

template <std::totally_ordered T>
void testInsertionSort(std::vector<T> data){
    std::cout << "Before InsertionSort: ";
    printVector(data);

    InsertionSort<Pokemon> insertionSorter;
    insertionSorter.sort(data);

    std::cout << "After InsertionSort: ";
    printVector(data);
}

template <std::totally_ordered T>
void testMergeSort(std::vector<T> data){
    std::cout << "Before MergeSort: ";
    printVector(data);

    MergeSort<Pokemon> mergeSorter;
    mergeSorter.sort(data);

    std::cout << "After MergeSort: ";
    printVector(data);
}

int main(){
//    testQuickSort(test);
//    testInsertionSort(test);
//    testMergeSort(test);

    std::vector<Pokemon> vec(files::readCSV(files::pokemonRandomSmall));

    testMergeSort(vec);

    return 0;
}
