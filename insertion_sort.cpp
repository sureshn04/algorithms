#include <bits/stdc++.h>

using namespace std;

void insertion_sort(vector<int>& a){
    int n = a.size();
    int i, j, key;

    for(j=1; j<n; ++j){
        key = a[j];
        i = j-1;
        while(i>=0 && a[i] > key){
            a[i+1] = a[i];
            --i;
        }
        a[i+1] = key;
    }

}

int main(){
    int n = 10;
    vector<int> a(10);
    srand (time(NULL));
    cout<<"Before sort \n";

    for(int i=0; i<n; ++i){
        a[i] = rand() % 1000;
        cout<<a[i]<<" ";
    }
    cout<<endl;

    insertion_sort(a);

    cout<<"After sort \n";

    for(int i=0; i<n; ++i){

        cout<<a[i]<<" ";
    }
    cout<<endl;

    return 0;
}
