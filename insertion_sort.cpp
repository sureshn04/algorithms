#include<iostream>
#define ll long long
using namespace std;

void insertion_sort(ll A[], ll n){
  ll i, j, key;
  for(j=1; j<n; ++j){
    key = A[j];
    i = j-1;
    cout<<"\n";
    while(i>=0 && key<A[i]){
      cout<<A[i]<<" =>  "<<i<< " \t";
      A[i+1] = A[i];
      i = i-1;
    }
    cout<<"\n";
    A[i+1] = key;
  }
}

int main(){
  ll n, i;
  cin>>n;
  ll A[n];
  for(i=0; i<n; ++i) cin>>A[i];

  cout<<"before sorting : \n";
  for ( i = 0; i < n; ++i)
  {
    cout<<A[i]<<" ";
  }
  
  insertion_sort(A, n);

  cout<<"\nAfter sorting : \n";
  for ( i = 0; i < n; ++i)
  {
    cout<<A[i]<<" ";
  }
  cout<<"\n";
  return 0;
}