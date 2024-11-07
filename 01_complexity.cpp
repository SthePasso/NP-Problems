/* 
Complexity of our algorithm:
Sort algorithms: https://lamfo-unb.github.io/2019/04/21/Sorting-algorithms/
array -> 6 elements
Buble Sort (O(n^2) = 6^2 = 36)
Merge Sort (O(nlogn) = 6log(6) = 4.7)


Homework:
install github
install terminal bash
*/

#include<iostream>
#include<vector>
#include<chrono>
#include <random>
#include <ctime>

using std::cout;
using std::vector;

class Sort {
public:
    Sort(vector<int>);
    Sort(int);
    ~Sort(){};
    void merge(vector<int>&, int, int);
    void merge_sort();
    void bubble();
    vector<int> getVector();
    void setVector(vector<int>&);
    void merge_partition(vector<int>&, int, int, int);
    vector<int> generateRandomVector(int size, int min, int max);
    vector<int> simpleRandomVector();

private:
    vector<int> array;
};

void Sort::merge_sort(){
    merge(this->array,0,array.size()-1);
}

Sort::Sort(vector<int> vec) {
    array = vec;
}

Sort::Sort(int size) {
    //vector<int> vec =generateRandomVector(size, 0, 100);
    //array = vec;
    vector<int> temp(size);
    this->array = temp;
    simpleRandomVector();
}

// Function to generate a random integer vector
vector<int> Sort::generateRandomVector(int size, int min, int max) {
    std::vector<int> randomVector(size);
    // Seed the random number generator with the current time
    std::mt19937 rng(static_cast<unsigned int>(std::time(0))); // Mersenne Twister RNG
    std::uniform_int_distribution<int> dist(min, max); // Distribution range [min, max]
    unsigned int seed = 999;
    // Fill the vector with random integers
    for (int& num : randomVector) {
        //cout<<"rng:"<<rng<<'\n';
        num = dist(rng);
    }
    return randomVector;
}

vector<int> Sort::simpleRandomVector(){
    for(int i=0; i<this->array.size(); i++){
        //this->array[i] = ((i*13+7)%100)+1; // linear function
        //https://cplusplus.com/reference/cstdlib/rand/#google_vignette
    }
    return this->array;
}



void Sort::bubble() {
    for (int i = 0; i < array.size(); i++) {
        for (int j = i + 1; j < array.size(); j++) {
            if (array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

vector<int> Sort::getVector() {
    for (int i = 0; i < array.size(); i++) {
        cout << array[i] << " ";
    }
    cout << '\n';
    return array;
}

void Sort::setVector(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        this->array[i] = arr[i];
    }
}

void Sort::merge_partition(vector<int>& arr, int left, int middle, int right) {
    int length1 = middle - left + 1;
    int length2 = right - middle;

    vector<int> V1(length1);
    vector<int> V2(length2);

    for (int i = 0; i < length1; i++) {
        V1[i] = arr[i + left];
    }
    for (int i = 0; i < length2; i++) {
        V2[i] = arr[i + middle + 1];
    }

    int i = 0, j = 0, k = left;

    while (i < length1 && j < length2) {
        if (V1[i] <= V2[j]) {
            arr[k] = V1[i];
            i++;
        }
        else {
            arr[k] = V2[j];
            j++;
        }
        k++;
    }

    while (i < length1) {
        arr[k] = V1[i];
        i++;
        k++;
    }

    while (j < length2) {
        arr[k] = V2[j];
        j++;
        k++;
    }
}

void Sort::merge(vector<int>& arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        merge(arr, left, middle);
        merge(arr, middle + 1, right);
        merge_partition(arr, left, middle, right);
    }
}

int main() {
    //Sort s1 = Sort(element);
    Sort s1 = Sort(777);
    cout << "Original array: ";
    vector<int> element = s1.getVector();

    auto startBubble = std::chrono::high_resolution_clock::now();
    s1.bubble();
    auto stopBubble = std::chrono::high_resolution_clock::now();
    auto durationBubble = std::chrono::duration_cast<std::chrono::microseconds>(stopBubble - startBubble);
    cout << "Sorted array by Bubble Sort: ";
    s1.getVector();
    cout << "Duration of Bubble Sort: " << durationBubble.count() << " microseconds\n";
    
    s1.setVector(element); // Reset to original unsorted array

    cout << "\nOriginal array reset: ";
    s1.getVector();


    auto startMerge = std::chrono::high_resolution_clock::now();
    s1.merge_sort(); //merge(element, 0, element.size() - 1);
    auto stopMerge = std::chrono::high_resolution_clock::now();
    auto durationMerge = std::chrono::duration_cast<std::chrono::microseconds>(stopMerge - startMerge);
    cout << "Sorted array by MergeSort: ";
    s1.getVector();
    cout << "Duration of MergeSort: " << durationMerge.count() << " microseconds\n";

    // what is the memory consumption from buble vs merge?
    // only 1 temp variable => O(1)
    // create two subarray => O(n)
    return 0;
}
 //g++ -std=c++11 01_complexity.cpp 