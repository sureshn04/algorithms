// Merge Sort : O(n Logn)
#include<bits/stdc++.h>

using namespace std;

// Merge two subarrays into sorted array 
void merge(vector<int>& A, int p, int q, int r){
  // length of Left sub array
  int n1 = q - p + 1;
  // length of right sub array
  int n2 = r - q;

  int i, j, k;

  vector<int> L(n1), R(n2);

  // copy the elements to left ans right sub array
  for(i=0; i<n1; ++i)  L[i] = A[p + i];
  for(j=0; j<n2; ++j)  R[j] = A[q + j + 1];

  i=0;
  j=0;
  k=p;

  // Merge the left and right subarray back into A[p..r]
  while(i<n1 && j<n2){
    if(L[i] <= R[j]){
      A[k] = L[i];
      ++i;
    } else {
      A[k] = R[j];
      ++j;
    }
    ++k;
  }

  // copy  the remaining elements in L[] 
  while (i<n1){
    A[k++] = L[i++];
  }

  // copy  the remaining elements in R[] 
  while (j<n2){
    A[k++] = R[j++];
  }
}

// Divide the array into two subarray and merge the two subarray in sorted form.
void merge_sort(vector<int>& A, int p, int r){
  if(p < r){
    // middle index
    int q = (p+r) / 2;

    // divided into two halves
    merge_sort(A, p, q);
    merge_sort(A, q+1, r);

    // merge the two subarray
    merge(A, p, q, r);
  }
}

int main(){

  vector<int> A(11);
  for(int i=0; i<11; ++i){
    A[i] = 10 - i;
  }

  cout<<"Before sort : \n";
  for(int i=0; i<11; ++i)
    cout<<A[i]<<" ";

  cout<<endl;

  merge_sort(A, 0, 11);

  cout<<"After sort : \n";
  for(int i=0; i<11; ++i)
    cout<<A[i]<<" ";

  cout<<endl;

  return 0;
}