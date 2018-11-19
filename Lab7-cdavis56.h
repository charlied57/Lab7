//
// Created by Charlie Davis on 11/12/18.
//

#ifndef LAB7_LAB7_CDAVIS56_H
#define LAB7_LAB7_CDAVIS56_H

#include "unixTimer.h"
#include <iostream>
#include <vector>

using namespace std;

vector<long> getNums(size_t listSize) {
    vector<long> theList;
    for (size_t i = 0; i < listSize; ++i)
    {
        theList.push_back(rand() % 500 + 1);
    }
    return theList;
}

void stl(){
    cout << "STL vector size: ";
    unsigned long n = 0;
    cin >> n;
    vector<long> stlVector;
    stlVector = getNums(n);
    Timer stlTimer;
    stlTimer.start();
    sort(begin(stlVector), end(stlVector));
    stlTimer.stop();
    cout << stlTimer() << endl;
}

void bubbleSort(){
    cout << "Bubble vector size: ";
    unsigned long n = 0;
    cin >> n;
    vector<long> stlBubble;
    stlBubble = getNums(n);
//    for(int i = 0; i < stlBubble.size()-1; i++){
//        cout << stlBubble[i] << ", ";
//    }
//    cout << stlBubble[stlBubble.size() -1] << endl;
    Timer bubbleTimer;
    bubbleTimer.start();

    bool testSwap = true;
    while(testSwap){
        testSwap = false;
        for(unsigned long i = 0; i < stlBubble.size()-1; i++){
            if(stlBubble[i] > stlBubble[i+1]){
                int temp = stlBubble[i];
                stlBubble[i] = stlBubble[i+1];
                stlBubble[i+1] = temp;
                testSwap = true;
            }
        }
    }
    bubbleTimer.stop();
//    for(int i = 0; i < stlBubble.size()-1; i++){
//        cout << stlBubble[i] << ", ";
//    }
//    cout << stlBubble[stlBubble.size() -1] << endl;
    cout << bubbleTimer() << endl;
}

void insertionSort(){
    cout << "Insertion vector size: ";
    unsigned long n = 0;
    cin >> n;
    vector<long> insertionVector;
    insertionVector = getNums(n);
//    for(int i = 0; i < insertionVector.size()-1; i++){
//        cout << insertionVector[i] << ", ";
//    }
    Timer insertionTimer;
    insertionTimer.start();

    for(long i = i; i < insertionVector.size(); i++){
        for(long j = i; j > 0; j--){
            int currentInt = insertionVector[j];
            if(currentInt < insertionVector[j-1]) {
                insertionVector[j] = insertionVector[j - 1];
                insertionVector[j - 1] = currentInt;
                //break;
            }
        }
    }
    insertionTimer.stop();
//    for(int i = 0; i < insertionVector.size()-1; i++){
//        cout << insertionVector[i] << ", ";
//    }
    cout << insertionTimer() << endl;
}

void selectionSort(){
    cout << "STL vector size: ";
    unsigned long n = 0;
    cin >> n;
    vector<long> selectionVector;
    selectionVector = getNums(n);
    for(int i = 0; i < selectionVector.size()-1; i++){
        cout << selectionVector[i] << ", ";
    }
    cout << selectionVector[selectionVector.size() -1] << endl;
    Timer selectionTimer;
    selectionTimer.start();

    for(unsigned long i = 0; i < selectionVector.size() - 1; i++){
        unsigned long front = i;
        for(unsigned long j = front + 1; j < selectionVector.size(); j++){
            if(selectionVector[j] < selectionVector[i]){
                int temp = selectionVector[i];
                selectionVector[i] = selectionVector[j];
                selectionVector[j] = temp;
            }
        }
    }
    selectionTimer.stop();
    for(int i = 0; i < selectionVector.size()-1; i++){
        cout << selectionVector[i] << ", ";
    }
    cout << selectionVector[selectionVector.size() -1] << endl;
    cout << selectionTimer() << endl;
}

void mergeSort(vector <long> & mergeVector, long L, long middleIndex, long R){

    long firstArraySize = middleIndex - L + 1;
    long secondArraySize = R - middleIndex;

    vector<long> tempOneArray;
    vector<long> tempTwoArray;
    for(long i = 0; i < firstArraySize; i++){
        tempOneArray.push_back(mergeVector[L + i]);
    }
    for(long i = 0; i < secondArraySize; i++){
        tempTwoArray.push_back(mergeVector[middleIndex + 1 + i]);
    }

    long firstArrayIndex = 0;
    long secondArrayIndex = 0;
    long mainArrayIndex = L;

    while(firstArrayIndex < firstArraySize && secondArrayIndex < secondArraySize){
        if(tempOneArray[firstArrayIndex] < tempTwoArray[secondArrayIndex]){
            mergeVector[mainArrayIndex] = tempOneArray[firstArrayIndex];
            firstArrayIndex++;
        }
        else{
            mergeVector[mainArrayIndex] = tempTwoArray[secondArrayIndex];
            secondArrayIndex++;
        }
        mainArrayIndex++;
    }
    while(firstArrayIndex < firstArraySize){
        mergeVector[mainArrayIndex] = tempOneArray[firstArrayIndex];
        firstArrayIndex++;
        mainArrayIndex++;
    }
    while(secondArrayIndex < secondArraySize){
        mergeVector[mainArrayIndex] = tempTwoArray[secondArrayIndex];
        secondArrayIndex++;
        mainArrayIndex++;
    }



}

void partition(vector <long> & mergeVector, long L, long R){
    if(L < R){
        long middleIndex = L + (R - L) / 2;

        partition(mergeVector, L, middleIndex);
        partition(mergeVector, middleIndex + 1, R);
        mergeSort(mergeVector, L, middleIndex, R);
    }
}

void mergeSetupAndRun(){
    cout << "Merge vector size: ";
    unsigned long n = 0;
    cin >> n;
    vector<long> mergeVector;
    mergeVector = getNums(n);
//    for(int i = 0; i < mergeVector.size()-1; i++){
//    cout << mergeVector[i] << ", ";
//    }
//    cout << endl;
    Timer mergeTimer;
    mergeTimer.start();
    partition(mergeVector, 0, mergeVector.size() - 1);
    mergeTimer.stop();
//    for(int i = 0; i < mergeVector.size()-1; i++){
//        cout << mergeVector[i] << ", ";
//    }
//    cout << endl;
    cout << mergeTimer() << endl;
}

int splitVector(vector<long> & quickVector, long left, long right) {
    // define variables
    long pivot = quickVector[left];
     long leftIndex = left+1;
     long rightIndex = right;
     long temp;

     // itterate through elements in vector
    while (leftIndex != rightIndex) {
        // move on if no swap is needed
        if (quickVector[leftIndex]  <= pivot){
            leftIndex++;
        }
        // move if no element is swapped
        else {
            while (( leftIndex != rightIndex)  && (pivot < quickVector[rightIndex])){
                rightIndex--;
            }
            // swap elements
            temp =  quickVector[rightIndex];
            quickVector[rightIndex] = quickVector[leftIndex];
            quickVector[leftIndex] = temp;
        }
    }

    // swap pivot
    if (quickVector[leftIndex]>pivot) leftIndex--;
    quickVector[left] = quickVector[leftIndex];
    quickVector[leftIndex] = pivot;

    return (leftIndex);
}

void quickSort(vector <long> & quickVector, long L, long R) {
    // split up into separate elements
    if (L < R) {
        long pivot = splitVector(quickVector, L, R);
        // recursion
        quickSort(quickVector, L, pivot - 1);
        quickSort(quickVector, pivot + 1, R);
    }
}

void quickSortSetupThenRun(){
    // After many attempts I was unable to get my quicksort to function properly, I redid it using code at
    // https://gist.github.com/raarce/4069108#file-qs-cpp-L13
    // as the framework as my code.
    cout << "Quick vector size: ";
    unsigned long n = 0;
    cin >> n;
    vector<long> quickVector;
    quickVector = getNums(n);
    Timer quickTimer;
//    for(int i = 0; i < quickVector.size()-1; i++){
//    cout << quickVector[i] << ", ";
//    }
//    cout << endl;
    quickTimer.start();
    quickSort(quickVector, 0, quickVector.size()-1);
    quickTimer.stop();
//    for(int i = 0; i < quickVector.size()-1; i++){
//        cout << quickVector[i] << ", ";
//    }
//    cout << endl;
    cout << quickTimer() << endl;
}
#endif //LAB7_LAB7_CDAVIS56_H