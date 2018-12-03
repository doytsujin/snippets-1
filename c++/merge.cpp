// Thank you https://visualgo.net/bn/sorting?slide=10-2
#include <vector>
#include <iostream>

using namespace std;

void print(const vector<int> &A) {
    cout << "[]: ";
    for (int i=0; i<A.size(); i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

void merge(vector<int> &A, int low, int mid, int high) {
  // subarray1 = A[low..mid], subarray2 = A[mid+1..high], both sorted
  int N = high-low+1;
  vector<int> B(N, 0);

  int left = low;
  int right = mid+1;
  int i = 0;

  // the merging
  while (left <= mid && right <= high) {
    B[i++] = (A[left] <= A[right]) ? A[left++] : A[right++];
  }
  
  // leftover, if any
  while (left <= mid) {
      B[i++] = A[left++];
  }

  // leftover, if any
  while (right <= high) {
      B[i++] = A[right++];
  }

  // copy back
  for (int k = 0; k < N; k++) {
      A[low+k] = B[k];
  }
}

void mergeSort(vector<int> &A, int low, int high) {
  // the array to be sorted is a[low..high]
  if (low < high) { // base case: low >= high (0 or 1 item)
    int mid = (low+high) / 2;	
    mergeSort(A, low , mid ); // divide into two halves
    mergeSort(A, mid+1, high); // then recursively sort them
    merge(A, low, mid, high); // conquer: the merge subroutine
  }
}

int main()
{
    vector<int> A = {1, 20, 5, 7, 19, 43, 6, -2, -5};
    
    print(A);
    mergeSort(A, 0, A.size());
    print(A);
}
    
