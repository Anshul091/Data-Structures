#include<bits/stdc++.h>
using namespace std;



bool valid(string &s){
    for(int i = 0; i<s.length(); i++){
        s[i] = tolower(s[i]);
        if(s[i] < 'a' || s[i] > 'z'){
            cout<<"Invalid input. Rejecting this input"<<endl;
            return false;
        }
    }
    return true;
}


class node{
    public:
        node* children[26];           // Make the array with the size of the number of different characters present in the string.
        bool endofword;
        node(){
            for(int i = 0; i<26; i++) children[i] = NULL;
            endofword = false;
        }
};



class Trie{
    node *root;
    int size;
    public:
        Trie(){
            this->root = new node();
            this->size = 0;
        }

        void insert(string s){
            node *temp = this->root;
            for(int i = 0; i<s.length(); i++){
                int index = s[i] - 'a';
                if(temp->children[index] == NULL) temp->children[index] = new node();
                temp = temp->children[index];
            }
            if(temp->endofword == false) size++;
            temp->endofword = true;
        }

        bool search(string s){                  // True or false based on whether string is present or not
            node *temp = this->root;
            for(int i = 0; i<s.length(); i++){
                int index = s[i] - 'a';
                if(temp->children[index] == NULL) return false;
                temp = temp->children[index];
            }
            return temp->endofword;
        }
        
        bool deletable(node *a){
            if(a == this->root) return false;
            for(int i = 0; i<26; i++){
                if(a->children[i] != NULL) return false;
            }
            return !a->endofword;
        }


        bool deleteWord(string s){
            if(s.size() == 0) return false;
            node *temp = this->root;
            vector<node*> order{temp};
            for(int i = 0; i<s.length(); i++){
                int index = s[i] - 'a';
                if(temp->children[index] == NULL) return false;
                temp = temp->children[index];
                if(temp != NULL)    order.push_back(temp);
            }
            // cout<<order.size()<<endl;
            int flag = 0;
            if(temp->endofword == true){
                this->size--;
                temp->endofword = false;
                flag = 1;
            }
            for(int i = order.size() - 1; i>=1; i--){
                if(deletable(order[i])){
                    delete order[i];
                    order[i - 1]->children[s[i - 1]] = NULL;
                }
                else break;
            }
            return flag;
        }
        int getSize(){
            return this->size;
        }
};



int main(){
    Trie t;
    cout<<"Enter the number of strings you want to have in the trie: "<<endl;     
    int n;
    cin>>n;
    cout<<"Enter the strings: "<<endl;
    for(int i = 0; i<n; i++){
        string s;
        cin>>s;
        if(valid(s)) t.insert(s);
    }
    while(1){
        cout<<"Enter the operation that you want to do\n1. Insert\n2. Search\n3. Delete\n4. Get size\n5. Exit"<<endl;
        int oper;
        cin>>oper;
        switch(oper){
            case 1:{
                cout<<"Enter the string you want to insert: "<<endl;
                string s;
                cin>>s;
                if(valid(s))  t.insert(s);
                break;
            }
            case 2:{
                cout<<"Enter the string you want to search: "<<endl;
                string s;
                cin>>s;
                if(valid(s)){
                    if(t.search(s)) cout<<"String is present"<<endl;
                    else cout<<"String is not present"<<endl;
                }
                break;
            }
            case 3:{
                cout<<"Enter the string you want to delete: "<<endl;
                string s;
                cin>>s;
                if(valid(s)){
                    if(t.deleteWord(s)) cout<<"String is deleted"<<endl;
                    else cout<<"String is not present"<<endl;
                }
                break;
            }
            case 4:{
                cout<<"Size of the trie is: "<<t.getSize()<<endl;
                break;
            }
            case 5:{
                return 0;
            }
            default:{
                cout<<"Invalid input. Try again"<<endl;
                break;              // Can be commented
            }
        }
    }
    return 0;
}