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



string print_LCS ( string s1, string s2, int l1, int l2){
    int t[l1+1][l2+1];
    memset(t,0,sizeof(t));
    for(int i=0;i<l1+1;i++){
        for(int j=0;j<l2+1;j++){
            if( i == 0 || j == 0){
                t[i][j] = 0;
            }
        }
    }
    for( int i = 1; i < l1 + 1; i++){
        for( int j = 1; j < l2 + 1; j++){
            if( s1[i-1] == s2[j-1] )
            t[i][j] = 1 + t[i-1][j-1];
            else t[i][j] = max( t[i-1][j], t[i][j-1]);
        }
    }
    int i = l1, j = l2;
    string s = "";
    while( i > 0 && j > 0){
        if( s1[i-1] == s2[j-1] ){
            s.push_back(s1[i-1]);
            i-- , j--;
        }
        else{
            if( t[i][j-1] > t[i-1][j] )j--;
            else i--;
        }
    }
    reverse( s.begin(), s.end() );
    return s;

}
int t[1001][1001];
int LCS ( string s1, string s2, int l1, int l2){
    if( l1 == 0 || l2 == 0 ){
        return 0 ;
    }
    if( t[l1][l2] != -1 ){
        return t[l1][l2] ;
    }
    if( s1[l1-1] == s2[l2-1] ){
        return t[l1][l2] = 1 + LCS( s1, s2, l1-1, l2-1 );
    }
    t[l1][l2] = max ( LCS( s1, s2, l1-1, l2 ), LCS(s1, s2, l1, l2-1));
    return t[l1][l2];
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);    
    #endif
    string s1,s2;
    cin>>s1>>s2;
    int l1 = s1.length(), l2=s2.length();
    memset(t,-1,sizeof(t));
    cout<<LCS(s1,s2,l1,l2)<<endl;
    cout<<print_LCS(s1,s2,l1,l2)<<endl;
    return 0;
}