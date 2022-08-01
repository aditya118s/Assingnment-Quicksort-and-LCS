#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int Partition(vector<int> &v, int lb, int ub ){
    int pivot = v[lb];
    int start = lb;
    int end = ub;
    while (start < end){
        while (v[start] <= pivot) start++;
        while (v[end] > pivot) end--;
        if (start < end)
        swap ( v[start], v[end]);
    }
    swap ( v[lb], v[end]);
    return end ;
}
vector<int> quickSort(vector<int> &v, int lb, int ub ){
    if (lb < ub){
        int loc = Partition (v, lb, ub);
        quickSort (v, lb, loc - 1);
        quickSort (v, loc + 1, ub);
    }
    return v ;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    quickSort(v,0,v.size()-1);
    for(int i=0;i<n;i++)cout<<v[i]<<" ";
    cout<<endl;
    return 0;
}
