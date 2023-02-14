#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>
#include <type_traits>
#include <concepts>
#include <cstddef>
#include <iostream>
#include <algorithm>

//std::totally_ordered is a C++20 "concept". Concepts are a new feature of C++20
//that allows the user to specify requirements for template parameters at compile time.
//totally_ordered ensures that any T passed to this template must be comparable, e.g.
//is usable with the >, <, and == operators -- which is obviously needed for sorting
//
//I choose to do this mainly just because it has been a long time since I have
//written any C++ code, and I wanted to try using some of the cool new features

template<std::totally_ordered T>

//Algorithms is an abstract class which the sorting algorithm classes will inherit from.
//this ensures that they're all implemented in the same way, and links them together
//since they're similar functions. 
class Algorithms{
protected:
    const std::string arrayNotLongEnoughError = "This array is either empty or too short to be sorted!\n";
public:
    //this line causes the compiler to generate a virtual destructor for the derived classes.
    //Without this, the default behavior for destructing the derived classes would be to call
    //the base class destructor, which is not virtual; that would lead to undefined behavior.
    virtual ~Algorithms() = default;

    //This specifies that the sort() function must be implemented in all derived classes, and
    //it is set equal to 0 which denotes that it is a "pure virtual" function, which means it
    //is declared but has no implementation. Only the derived classes for the sorting algorithms
    //should be implementing this function, which is why I choose to do this. This function
    //returns the number of comparisons it made
    virtual size_t sort(std::vector<T>& data) = 0;
};


template<std::totally_ordered T>
class InsertionSort : public Algorithms<T> {
private:
    const std::string algorithmLabel = "Algorithm: Insertion Sort\n";
public:
    //implementation of the InsertionSort algorithm. Returns # of comparisons
    size_t sort(std::vector<T>& data){
        
        //check that the data is of a workable size
        if(data.size() <= 1){
            std::cerr << Algorithms<T>::arrayNotLongEnoughError;
            std::cerr << algorithmLabel;
            std::cerr << "Array Size: " << data.size() << std::endl;
            return -1;
        }

        //initialize comparisons to 0
        size_t comparisons = 0;

        //loop through each element in the data starting at 1
        for(std::size_t i = 1; i < data.size(); i++) {
            //element to be compared & inserted
            T currentElement = data[i];
            
            //initialize j to i-1, this will loop through and find
            //the correct place to insert currentElement
            size_t j = i - 1;

            //move elements that are greater than the currentElement one space ahead.
            //the number of iterations of this loop will be the number of comparisons,
            //so it will also increment that.
            while(j >= 0 && data[j] > currentElement) {
                data[j + 1] = data[j];
                j--;
                ++comparisons;
            }

            //insert the element into the correct position
            data[j + 1] = currentElement;
        }
        
        //return the number of comparisons
        return comparisons;
    }
};

template<std::totally_ordered T>
class QuickSort : public Algorithms<T> {
private:
    size_t comparisons;
    const std::string algorithmLabel = "Algorithm: Quick Sort\n";
    
    ptrdiff_t partition(std::vector<T>& data, ptrdiff_t low, ptrdiff_t high) {
        T pivot = data[high];
        ptrdiff_t i = low - 1;

        for(ptrdiff_t j = low; j < high; j++){
            if(data[j] <= pivot) {
                ++i;
                ++comparisons;
                std::swap(data[i], data[j]);
            }
        }

        std::swap(data[i + 1], data[high]);
        return i + 1;
    }

    void quickSort(std::vector<T>& data, ptrdiff_t low, ptrdiff_t high) {
    	if(low >= high)
    		return;
    
        ptrdiff_t pivotIndex = partition(data, low, high);
        quickSort(data, low, pivotIndex - 1);
        quickSort(data, pivotIndex + 1, high);
    }

public:
    size_t sort(std::vector<T>& data) override { 
        //check that the data is of a workable size
        if(data.size() <= 1){
            std::cerr << Algorithms<T>::arrayNotLongEnoughError;
            std::cerr << algorithmLabel;
            std::cerr << "Array Size: " << data.size() << std::endl;
            return -1;
        }

        comparisons = 0;
        quickSort(data, 0, data.size() - 1);
        return comparisons;
    }
};

template<std::totally_ordered T>
class MergeSort : public Algorithms<T> {
private:
    size_t comparisons;
    const std::string algorithmLabel = "Algorithm: Merge Sort\n";
    
    void merge(std::vector<T>& data, ptrdiff_t low, ptrdiff_t mid, ptrdiff_t high){
        ptrdiff_t subDiv1 = (mid - low) + 1;
        ptrdiff_t subDiv2 = (high - mid);

        std::vector<T> subData1(subDiv1);
        std::vector<T> subData2(subDiv2);

        std::copy(data.begin() + low, data.begin() + (mid+1), subData1.begin());
        std::copy(data.begin() + (mid+1), data.begin() + (high+1), subData2.begin());

        ptrdiff_t i = 0;
        ptrdiff_t j = 0;
        ptrdiff_t k = low;

        while(i < subDiv1 && j < subDiv2) {
            if(subData1[i] <= subData2[j]) {
                data[k] = subData1[i];
                ++i;
            } else {
                data[k] = subData2[j];
                ++j;
            }
            ++k;
            ++comparisons;
        }

        while(i < subDiv1){
            data[k] = subData1[i];
            ++i;
            ++k;
        }

        while(j < subDiv2){
            data[k] = subData2[j];
            ++j;
            ++k;
        }
    }

    void mergeSort(std::vector<T>& data, ptrdiff_t low, ptrdiff_t high) {
//        std::cout << "made it past once " << data.size() << " " << low << " " << high << "\n";

        if(low >= high)
            return;

        ptrdiff_t mid = low + ((high - low) / 2);
        mergeSort(data, low, mid);
        mergeSort(data, mid + 1, high);
        merge(data, low, mid, high);
    }
    
public:
    size_t sort(std::vector<T>& data) override {
        //check that the data is of a workable size
        if(data.size() <= 1){
            std::cerr << Algorithms<T>::arrayNotLongEnoughError;
            std::cerr << algorithmLabel;
            std::cerr << "Array Size: " << data.size() << std::endl;
            return -1;
        }

        comparisons = 0;
        mergeSort(data, 0, data.size() - 1);
        return comparisons;
    }
};

#endif
