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
size_t doQuickSort(std::vector<T> data){
    std::cout << "Before QuickSort: ";
    printVector(data);

    QuickSort<Pokemon> quickSorter;
    size_t comparisons = quickSorter.sort(data);

    std::cout << "After QuickSort: ";
    printVector(data);

    return comparisons;
}

template <std::totally_ordered T>
size_t doInsertionSort(std::vector<T> data){
    std::cout << "Before InsertionSort: ";
    printVector(data);

    InsertionSort<Pokemon> insertionSorter;
    size_t comparisons = insertionSorter.sort(data);

    std::cout << "After InsertionSort: ";
    printVector(data);

    return comparisons;
}

template <std::totally_ordered T>
size_t doMergeSort(std::vector<T> data){
    std::cout << "Before MergeSort: ";
    printVector(data);

    MergeSort<Pokemon> mergeSorter;
    size_t comparisons = mergeSorter.sort(data);

    std::cout << "After MergeSort: ";
    printVector(data);

    return comparisons;
}

int main(){
    std::vector<Pokemon> vec(files::readCSV(files::pokemonReverseSortedSmall));

    size_t quicksortComparisons = doQuickSort(vec);
    size_t insertionComparisons = doInsertionSort(vec);
    size_t mergesortComparisons = doMergeSort(vec);

    std::cout << "Size of Dataset: " << vec.size() << std::endl;
    std::cout << "quicksort Comparisons: " << quicksortComparisons << std::endl;
    std::cout << "insertion Comparisons: " << insertionComparisons << std::endl;
    std::cout << "mergesort Comparisons: " << mergesortComparisons << std::endl;

    return 0;
}
