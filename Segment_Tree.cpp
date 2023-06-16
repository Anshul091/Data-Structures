#include <bits/stdc++.h>
using namespace std;
 
 
 
typedef long long int ll;
typedef vector<ll> vl;


struct item{
    ll sum;
};


struct SegTree{
    ll size;
    vector<item> tree;



    // Utility functions   to be definitely changed as per needs
    item NEUTRAL_ELEMENT = {0};
    item single(ll a){
        return {a};
    }

    item merge(item a1, item a2){
        return {a1.sum + a2.sum};
    }





    void init(ll n){
        size = 1;
        while(size < n) size *= 2;
        tree.resize(2*size);                 //Initial value 
    }

    void build(vl &a, ll x, ll lx, ll rx){
        if(rx - lx == 1){
            if(lx < a.size()){
                tree[x] = single(a[lx]);
            }
            return;
        }
        ll mid = (lx + rx) / 2;
        build(a, 2*x+1, lx, mid);
        build(a, 2*x+2, mid, rx);
        tree[x] = merge(tree[2*x+1] , tree[2*x+2]);
    }


    void build(vl &a){
        build(a, 0, 0, size);
    }


    void set(ll i, ll v, ll x, ll lx, ll rx){               // 0 based - indexing
        if(rx - lx == 1) {
            tree[x] = single(v);  
            return;
        }
        ll mid = (lx + rx) >> 1;
        if(i < mid){
            set(i, v, 2*x+1, lx, mid);
        }
        else set(i, v, 2*x+2, mid, rx);
        tree[x] = merge(tree[2*x+1] , tree[2*x+2]);
    }



    void set(ll i, ll v){
        set(i, v, 0, 0, size);
    }



    item query(ll l, ll r, ll x, ll lx, ll rx){                         
        if(lx >= r  ||  l >= rx) return NEUTRAL_ELEMENT;                  // Set non-interfering value for the required operation
        if(lx >= l  &&  rx <= r) return tree[x];
        ll mid = (lx + rx) >> 1;
        item s1 = query(l, r, 2*x+1, lx, mid);
        item s2 = query(l, r, 2 * x + 2, mid, rx);
        return merge(s1,s2);
    }



    item query(ll l, ll r) {return query(l, r, 0, 0, size);}                // r is not included in the range
};


 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cout<<"Enter the length of the array of numbers"<<endl;
    ll n;
    cin>>n;
    vl v(n);
    for(ll i = 0; i<n; i++) cin>>v[i];
    SegTree st;
    st.init(n);
    st.build(v);
    while(1){
        cout<<"Enter 1 to update a value, 2 to query a range, 3 to exit"<<endl;
        ll choice;
        cin>>choice;
        switch (choice)
        {
        case 1:{
            cout<<"Enter the index and the value to be updated"<<endl;
            ll ind, val;
            cin>>ind>>val;
            if(ind < n) st.set(ind, val);
            else cout<<"Invalid index. Try again"<<endl;
            break;
        }
        case 2:{
            cout<<"Enter the range(l, r) to be queried"<<endl;    // Note r is not included in the range
            ll l, r;
            cin>>l>>r;
            if(l >= 0  &&  r <= n  &&  l < r) cout<<st.query(l, r).sum<<endl;
            else cout<<"Invalid range. Try again"<<endl;
            break;
        }
        case 3:
            return 0;
        default:
            cout<<"Invalid input. Try again"<<endl;
            break;
        }
    }
    return 0;
}