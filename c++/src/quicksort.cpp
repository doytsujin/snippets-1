// Thank you https://visualgo.net/bn/sorting
#include <vector>
#include "quicksort.h"

using namespace std;

int partition(vector<int> &A, int i, int j) {
  int p = A[i]; // p is the pivot
  int m = i; // S1 and S2 are initially empty
  for (int k = i+1; k <= j; k++) { // explore the unknown region
    if (A[k] < p) { // case 2
      m++;
      swap(A[k], A[m]); // C++ STL algorithm std::swap
    } // notice that we do nothing in case 1: a[k] >= p
  }
  swap(A[i], A[m]); // final step, swap pivot with a[m]
  return m; // return the index of pivot
}

void quickSort(vector<int> &A, int low, int high) {
  if (low < high) {
    int m = partition(A, low, high); // O(N)
    // A[low..high] ~> A[low..m–1], pivot, A[m+1..high]
    quickSort(A, low, m-1); // recursively sort left subarray
    // A[m] = pivot is already sorted after partition
    quickSort(A, m+1, high); // then sort right subarray
  }
}

void quickSort(vector<int> &A) {
    quickSort(A, 0, A.size());
}
