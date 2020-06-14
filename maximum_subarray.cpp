/*
  * Maximum subarray problem
  * Running Time : O(n lgn)
*/

#include<bits/stdc++.h>

using namespace std;

//Find a maximum subarray that crosses the midpoint and return sum of the value in maximum subarray
int Maximum_Cross_Subarray(int *A, int low, int mid, int high){
  int left_sum = 0, sum = 0, right_sum = 0, i;
  
  // find a maximum subarray of the left half
  for(i=mid; i>=0; --i){
    sum += A[i];
    if(sum > left_sum)
      left_sum = sum;
  }

  sum = 0;

  // find a maximum subarray of the right half
  for(i=mid+1; i<high; ++i){
    sum += A[i];
    if(sum > right_sum)
      right_sum = sum;
  }

  // return the sum of the value in maximum subarray 
  return left_sum + right_sum;
}

// Divide and Conquer method for Maximum subarray problem
int Maximum_Subarray(int *A, int low, int high){
  if(low == high) //base case: having only one value
    return A[low];
  else{

    int left_sum, right_sum, cross_sum, mid;
    mid = (low + high)/2;

    left_sum = Maximum_Subarray(A, low, mid);
    right_sum = Maximum_Subarray(A, mid+1, high);
    cross_sum = Maximum_Cross_Subarray(A, low, mid, high);

    // compare and return the maximum value
    if(left_sum >= right_sum && left_sum >= cross_sum)
      return left_sum;
    else if(right_sum >= left_sum && right_sum >= cross_sum)
      return right_sum;
    else 
      return cross_sum;
  }
}

int main(){

  int n, i;
  cin>>n;
  int A[n];

  for(i=0; i<n; ++i){
    cin>>A[i];
  }

  int sum =  Maximum_Subarray(A, 0, n);

  cout<<"The maximum value of a subarray is "<<sum<<endl;

}