#include <iostream>
#include "Lab7-cdavis56.h"
#include "unixTimer.h"

using namespace std;

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

int main() {
//    stl();
    bubbleSort();
//    insertionSort();
//    selectionSort();
//    mergeSort();
//    quickSort();
    return 0;
}
