#include <iostream>
#include "merge.h"
#include "quicksort.h"

using namespace std;

void print(const vector<int> &A) {
    cout << "[]: ";
    for (int i=0; i<A.size(); i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main()
{
    cout << "---- Merge Sort ----" << endl;
    vector<int> A = {1, 20, 5, 7, 19, 43, 6, -2, -5};
    print(A);
    mergeSort(A);
    print(A);

    cout << "---- Quick Sort ----" << endl;
    vector<int> B = {1, 20, 5, 7, 19, 43, 6, -2, -5};
    print(B);
    quickSort(B);
    print(B);
}
    
