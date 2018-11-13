//
// Created by Charlie Davis on 11/12/18.
//

#ifndef LAB7_LAB7_CDAVIS56_H
#define LAB7_LAB7_CDAVIS56_H

#include "unixTimer.h"
#include <iostream>
#include <string>
#include <utility>
#include <list>
#include <vector>
#include <set>
#include <map>

using namespace std;

vector<long> getNums(size_t listSize)
{
    vector<long> theList;
    for (size_t i = 0; i < listSize; ++i)
    {
        theList.push_back(rand() % 500 + 1);
    }
    return theList;
}

void bubbleSort(){
    cout << "Bubble vector size: ";
    unsigned long n = 0;
    cin >> n;
    vector<long> stlBubble;
    stlBubble = getNums(n);
    Timer bubbleTimer;
    bubbleTimer.start();

    bool testSwap = true;
    while(testSwap){
        testSwap = false;
        for(unsigned long i = 0; i < stlBubble.size(); i++){
            if(stlBubble[i] > stlBubble[i+1]){
                int temp = stlBubble[i];
                stlBubble[i] = stlBubble[i+1];
                stlBubble[i+1] = temp;
                testSwap = true;
            }
        }






    }










    bubbleTimer.stop();
    cout << bubbleTimer() << endl;
}
void insertionSort(){
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
void selectionSort(){
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
void mergeSort(){
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
void quickSort(){
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

template< typename I >
void printContainer( std::ostream & outfile, I itBegin, I itEnd, std::string left, std::string separator, std::string right ) {
    outfile << left;
    I it = itBegin;
    if( it != itEnd )
    {
        outfile << ( * it );
        ++it;
    }
    while( it != itEnd )
    {
        outfile << separator << ( * it );
        ++it;
    }
    outfile << right;
}

// Print pair< T, U > to outfile.
template< typename T, typename U > std::ostream & operator<<( std::ostream & outfile, const std::pair< T, U > pairTU ) {
    outfile << "< " << pairTU.first << ", " << pairTU.second << " >";
    return outfile;
}

// Print list< T > to outfile.
template< typename T > std::ostream & operator<<( std::ostream & outfile, const std::list< T > & listT ) {
    printContainer( outfile, begin(listT), end(listT),
                    "( ", ", ", " )" );
    return outfile;
}

// Print set< T > to outfile.
template< typename T > std::ostream & operator<<( std::ostream & outfile, const std::set< T > & setT ) {
    printContainer( outfile, setT.begin(), setT.end(),
                    "{ ", ", ", " }" );
    return outfile;
}

// Print map< T, U > to outfile.
template< typename T, typename U > std::ostream & operator<<( std::ostream & outfile, const std::map< T, U > & mapTU ) {
    printContainer( outfile, mapTU.begin(), mapTU.end(),
                    "{ ", ", ", " }" );
    return outfile;
}

// Print vector< Type > to outfile.
template< typename T > std::ostream & operator<<( std::ostream & outfile, const std::vector< T > & vectorT ) {
    printContainer(outfile, vectorT.begin(), vectorT.end(),
                   "[ ", ", ", " ]");
    return outfile;
}

#endif //LAB7_LAB7_CDAVIS56_H