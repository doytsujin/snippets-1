// Thank you https://visualgo.net/bn/sorting
#include <vector>
#include "macros.h"
#include "quicksort.h"

int partition(std::vector<int> &A, int i, int j) 
{
    // p is the pivot
    int p = A[i];

    // S1 and S2 are initially empty
    int m = i;

    // explore the unknown region
    for (int k = i+1; k <= j; k++) {
        // case 2
        if (A[k] < p) {
            m++;
            std::swap(A[k], A[m]);
        }
        // notice that we do nothing in case 1: a[k] >= p
    }
    // final step, swap pivot with a[m]
    std::swap(A[i], A[m]);

    // return the index of pivot
    return m;
}

void quickSort(std::vector<int> &A, int left, int right) 
{
    if (left < right) {
        // O(N)
        int m = partition(A, left, right);

        // A[left..right] ~> A[left..m–1], pivot, A[m+1..right]
        quickSort(A, left, m-1); // recursively sort left subarray

        // A[m] = pivot is already sorted after partition
        quickSort(A, m+1, right); // then sort right subarray
    }
}

void quickSort(std::vector<int> &A) 
{
    const int N = A.size()-1;
    quickSort(A, 0, N);
}
