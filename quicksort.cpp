#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ld = long double;
#define ff first
#define ss second
#define pb push_back
#define po pop_back
#define all(v) v.begin(),v.end()
#define fo(i,a,n) for ( int i = a; i < n; i++ )
#define of(i,n,a) for ( int i = n; i > a; i-- )
#define TT ll tttt;cin >> tttt; while ( tttt-- )
#define MOD 1000000007
 
ll nxt(){ll TV;cin>>TV;return TV;}
ll gcd(ll a,ll b){
    if(a==0)return b;if(b==0)return a;if(a==b)return a;
    if(a>b)return gcd(a-b,b);
    return gcd(a,b-a);
}

ll power(ll a, ll n,ll p)
{    a%=p;
ll res=1; while(n>0){ if(n&1LL)res=res*a%p; a=a*a%p; n>>=1; } return res; }

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
vector<int> Quicksort(vector<int> &v, int lb, int ub ){
    if (lb < ub){
        int loc = Partition (v, lb, ub);
        Quicksort (v, lb, loc - 1);
        Quicksort (v, loc + 1, ub);
    }
    return v ;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);    
    #endif
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    Quicksort(v,0,v.size()-1);
    for(int i=0;i<n;i++)cout<<v[i]<<" ";
    cout<<endl;
    return 0;
}