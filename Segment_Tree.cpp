// Segment Tree is a data Structure which allows to perform range queries and point updates in O(log(n)) time.


#include <bits/stdc++.h>
using namespace std;
 
 
 
typedef long long int ll;                   // Some macros
typedef vector<ll> vl;


struct item{                        // Can use to store mutliple values in a node of the segment tree
    ll sum;
};


struct SegTree{
    ll size;
    vector<item> tree;



    // Utility functions   to be definitely changed as per needs
    item NEUTRAL_ELEMENT = {0};             // Set non-interfering value for the required operation
    item single(ll a){                      // If there is a single element in the array
        return {a};
    }

    item merge(item a1, item a2){           // Operation that you want in the segment tree
        return {a1.sum + a2.sum};
    }





    void init(ll n){                        // Initialising the segment-tree with size 2*2^ceil(log2(n)) - 1
        size = 1;
        while(size < n) size *= 2;
        tree.resize(2*size);                 //Initial value 
    }

    void build(vl &a, ll x, ll lx, ll rx){          // If you build the segment tree with some initial values
        if(rx - lx == 1){                           // It's time complexity is O(n).
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


    void set(ll i, ll v, ll x, ll lx, ll rx){               // i is the index to be updated, v is the value to be updated
        if(rx - lx == 1) {                              //  x is the index of the segment Tree we are considering right now, 
            tree[x] = single(v);                        // lx, rx and the right and the left index of the segment of the array
            return;                                     // We always start x with 0 as 0 is the index of root of the segment tree
        }                                               // Note: Segment tree is a binary-tree stored in an array. Children of x are 2*x + 1, 2*x + 2. Kindof like heap.
        ll mid = (lx + rx) >> 1;                        // So, we are updating those index of segment tree which contains the ith index
        if(i < mid){
            set(i, v, 2*x+1, lx, mid);
        }
        else set(i, v, 2*x+2, mid, rx);
        tree[x] = merge(tree[2*x+1] , tree[2*x+2]);
    }



    void set(ll i, ll v){                               // 0 based - indexing
        set(i, v, 0, 0, size);                          // O(log n) time complexity
    }



    item query(ll l, ll r, ll x, ll lx, ll rx){                         
        if(lx >= r  ||  l >= rx) return NEUTRAL_ELEMENT;                  // Set non-interfering value for the required operation
        if(lx >= l  &&  rx <= r) return tree[x];
        ll mid = (lx + rx) >> 1;
        item s1 = query(l, r, 2*x+1, lx, mid);
        item s2 = query(l, r, 2 * x + 2, mid, rx);
        return merge(s1,s2);
    }



    item query(ll l, ll r) {return query(l, r, 0, 0, size);}                // r is not included in the range, O(log n) time complexity
};


 
int main(){
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