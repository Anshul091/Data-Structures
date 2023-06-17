#include <bits/stdc++.h>
using namespace std;
/* Sparse Table is a data structure which is used to answer range queries in an array in O(1) time. 
    Although there can't be any updation in the array, it provides range queries the fastest.
*/
 
 
typedef long long int ll;
typedef vector<ll> vl;



struct item{
    ll m;
};

struct sparse_table{
    // Utility functions to be changed according to the problem. All the functions in which double counting doesn't affect the answer can be used.
    item combine(item a, item b){
        return {min(a.m, b.m)};
    }
    item single(ll a){          // The value if only single element is present in the range
        return {a};
    }

    ll n;
    vector<vector<item>> st;
    sparse_table(vector<ll> &v){
        n = v.size();
        ll k = log2(n) + 1;
        st.resize(n, vector<item>(k));
        for(ll i = 0; i < n; i++){
            st[i][0] = single(v[i]);
        }
        for(ll j = 1; j < k; j++){
            for(ll i = 0; i + (1 << j) <= n; i++){
                st[i][j] = combine(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    item query(ll l, ll r){                                 // l and r are inclusive
        if(r >= n || l > r || l < 0) return {INT_MAX};
        ll length = (r - l + 1);
        ll k = 0;
        while(1 << (k + 1) <= length) k++;
        return combine(st[l][k], st[r - (1 << k) + 1][k]);
    }
};


void solve(){
    cout<<"Enter the numbers of elements in the array"<<endl;
    ll n;
    cin>>n;
    cout<<"Enter the array"<<endl;
    vl v(n);
    for(ll i = 0; i<n; i++) cin>>v[i];
    sparse_table st(v);
    cout<<"Enter the number of queries"<<endl;
    ll q;   cin>>q;
    if(q < 1) return;
    while(q--){
        cout<<"Enter the range"<<endl;
        ll l, r;
        cin>>l>>r;
        cout<<st.query(l, r).m<<endl;
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();
    return 0;
}