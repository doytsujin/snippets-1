#include <iostream>
#include "merge.h"
#include "quicksort.h"
#include "macros.h"

using namespace std;

int main()
{
    vector<int> unsorted = {1, 20, 5, 7, 19, 43, 6, -2, -5};
    vector<int> correct = {-5, -2, 1, 5, 6, 7, 19, 20, 43};
    vector<int> sorted;

    cout << "---- Merge Sort ----" << endl;
    PRINT_VECTOR(unsorted);
    sorted = unsorted;
    mergeSort(sorted);
    PRINT_VECTOR(sorted);
    PRINT_VECTOR(correct);
    assert(sorted == correct);

    cout << "---- Quick Sort ----" << endl;
    PRINT_VECTOR(unsorted);
    sorted = unsorted;
    quickSort(sorted);
    PRINT_VECTOR(sorted);
    PRINT_VECTOR(correct);
    assert(sorted == correct);
}
    
