#include<bits/stdc++.h>
using namespace std;


struct DSU {
  vector<int> par, rnk, sz;
  int c;
  DSU(int n) : par(n + 1), rnk(n + 1, 0), sz(n + 1, 1), c(n) {
    for (int i = 1; i <= n; ++i) par[i] = i;
  }
  int find(int i) {
    return (par[i] == i ? i : (par[i] = find(par[i])));
  }
  bool same(int i, int j) {
    return find(i) == find(j);
  }
  int get_size(int i) {
    return sz[find(i)];
  }
  int count() {
    return c;    //connected components
  }
  int merge(int i, int j) {
    if ((i = find(i)) == (j = find(j))) return -1;
    else --c;
    if (rnk[i] > rnk[j]) swap(i, j);
    par[i] = j;
    sz[j] += sz[i];
    if (rnk[i] == rnk[j]) rnk[j]++;
    return j;
  }
};

int main(){
    cout<<"Enter the numbers of elements pushed in the DSU"<<endl;
    int n;
    cin>>n;
    DSU d(n);
    while(1){
        cout<<"1 for merging two elements\n2 for finding the parent of an element\n3 for finding the size of the component of an element\n4 for finding the number of connected components\n5 for exiting"<<endl;
        int choice;  cin>>choice;
        switch (choice)
        {
        case 1: 
            cout<<"Enter the two elements to be merged"<<endl;
            int a, b;
            cin>>a>>b;
            if(a > n || b > n || a < 1 || b < 1){
                cout<<"Invalid input"<<endl;
            }
            else if(d.same(a, b)){
                cout<<"The elements are already in the same component"<<endl;
            }
            else{
                d.merge(a, b);
                cout<<"The elements have been merged"<<endl;
            }
            break;
        case 2:
            cout<<"Enter the element whose parent is to be found"<<endl;
            int x;
            cin>>x;
            if(x > n || x < 1){
                cout<<"Invalid input"<<endl;
            }
            else{
                cout<<"The parent of "<<x<<" is "<<d.find(x)<<endl;
            }
            break;
        case 3:
            cout<<"Enter the element whose component size is to be found"<<endl;
            int y;
            cin>>y;
            if(y > n || y < 1){
                cout<<"Invalid input"<<endl;
            }
            else{
                cout<<"The size of the component of "<<y<<" is "<<d.get_size(y)<<endl;
            }
            break;
        case 4:
            cout<<"The number of connected components are "<<d.count()<<endl;
            break;
        case 5:
            return 0;
        default:
            break;
        }
    }
    return 0;
}