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
size_t doQuickSort(std::vector<T> data, bool verbose){
    if(verbose) {
        std::cout << "Before QuickSort: ";
        printVector(data);
    }

    QuickSort<T> quickSorter;
    size_t comparisons = quickSorter.sort(data);

    if(verbose) {
        std::cout << "After QuickSort: ";
        printVector(data);
    }

    return comparisons;
}

template <std::totally_ordered T>
size_t doInsertionSort(std::vector<T> data, bool verbose){
    if(verbose) {
        std::cout << "Before InsertionSort: ";
        printVector(data);
    }

    InsertionSort<T> insertionSorter;
    size_t comparisons = insertionSorter.sort(data);

    if(verbose) {
        std::cout << "After InsertionSort: ";
        printVector(data);
    }

    return comparisons;
}

template <std::totally_ordered T>
size_t doMergeSort(std::vector<T> data, bool verbose){
    if(verbose) {
        std::cout << "Before MergeSort: ";
        printVector(data);
    }

    MergeSort<T> mergeSorter;
    size_t comparisons = mergeSorter.sort(data);

    if(verbose) {
        std::cout << "After MergeSort: ";
        printVector(data);
    }

    return comparisons;
}

int main(int argc, char* argv[]){
    //options which can be changed via CLI arguments
    bool verbose = false;
    bool quickSort = true;
    bool mergeSort = true;
    bool insertionSort = true;

    //handle command line arguments
    for(int i = 1; i < argc; i++){
        std::string arg = argv[i]; 

        if(arg == "-h"){
            std::cout << "-h -- Print this menu (cannot be combined with other args)\n";
            std::cout << "-v -- verbose mode, will print the arrays before and after sorting\n";
            std::cout << "-eq or --exclude-quicksort -- this will skip doing quicksort\n";
            std::cout << "-ei or --exclude-insertionsort -- this will skip doing insertion sort\n";
            std::cout << "-em or --exclude-mergesort -- this will skip doing quicksort\n";
            //std::cout << "-d [input file] -- specify a specific input file to sort\n";
            return 1;
        }
        if(arg == "-v"){
            verbose = true;
        }
        if(arg == "-eq" || arg == "--exclude-quicksort") {
            quickSort = false;
        }
        if(arg == "-ei" || arg == "--exclude-insertionsort") {
            insertionSort = false;
        }
        if(arg == "-em" || arg == "--exclude-mergesort") {
            mergeSort = false;
        }
        if(arg == "-d"){
            //implement later
        }
    }
    
    //loop through each file to be sorted
    for(auto p : files::getFilesArray()){
        //print the current file that is being operated on:
        std::cout << p << std::endl;

        //read the current csv file into a vector of Pokemon objects
        std::vector<Pokemon> vec = files::readCSV(p);

        //sort copies of the vector with each sorting algorithm, take note of comparisons
        size_t quicksortComparisons = quickSort ? doQuickSort(vec, verbose) : 0;
        size_t insertionComparisons = insertionSort ? doInsertionSort(vec, verbose) : 0;
        size_t mergesortComparisons = mergeSort ? doMergeSort(vec, verbose) : 0;

        //print the size of the data set
        std::cout << "Size of Dataset: " << vec.size() << std::endl;

        //print how long each sorting algorithm took
        if(quickSort)
            std::cout << "quicksort Comparisons: " << quicksortComparisons << std::endl;
        
        if(insertionSort)
            std::cout << "insertion Comparisons: " << insertionComparisons << std::endl;
            
        if(mergeSort)
            std::cout << "mergesort Comparisons: " << mergesortComparisons << std::endl;
    
        //print an extra newline to separate the data
        std::cout << '\n';
    }
    
    //note to the user
    std::cout << "ending note: this program is compatible with commandline arguments which might\n"
            << "be good for getting a more useful result. Try ./main -h for the help menu\n";
            
    return 0;
}



