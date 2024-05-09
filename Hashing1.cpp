#include<iostream>
#include<vector>
using namespace std;

class Hash{
    int n;
    vector<long long int> arr;
    vector<long long int> arr1;
    public:
    vector<long long int> get_wo_rep_array(){
        return arr;
    }
    vector<long long int> get_w_rep_array(){
        return arr1;
    }
    Hash(){
        n=10;
        for(int i=0;i<10;i++){
            arr.push_back(-1);
            arr1.push_back(-1);
        }
    }
    Hash(int n){
        this->n = n;
        for(int i=0;i<n;i++){
            arr.push_back(-1);
            arr1.push_back(-1);
        }
    }
    int hashing(long long int x){
        return x%n;
    }
    int prob(vector<long long int> arr,int x,int ind){
        bool flag=1;
        while(arr[ind]!=-1){
            ind = (ind+1)%n;
            if(hashing(x)==ind){
                flag=0;
                break;
            }
        }
        if(flag){
            return ind;
        }
        return -1;
    }
    void disp(){
        cout<<"Without repetition :- "<<endl;
        for(auto i:arr){
            cout<<i<<" ";
        }
        cout<<endl;
        cout<<"With repetition :- "<<endl;
        for(auto i:arr1){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    void w_o_rep(int x){
        int ind = hashing(x);
        if(arr[ind]==-1){
            arr[ind] = x;
            cout<<x<<" inserted at "<<ind<<endl;
        }
        else{
            ind = prob(arr,x,ind);
            if(ind!=-1){
                arr[ind] = x;
                cout<<x<<" inserted at "<<ind<<endl;
            }
            else{
                cout<<"Table is full!!"<<endl;
            }
        }
    }
    void w_rep(int x){
        int ind = hashing(x);
        if(arr1[ind]==-1){
            arr1[ind] = x;
            cout<<x<<" inserted at "<<ind<<endl;
        }
        else{
            long long int temp = arr1[ind];
            if(hashing(temp)==ind){
                ind = prob(arr1,x,ind);
                arr1[ind] = x;
                cout<<x<<" inserted at "<<ind<<endl;
            }
            else{
                arr1[ind] = x;
                int p = ind;
                ind = prob(arr1,temp,ind);
                arr1[ind] = temp;
                cout<<arr1[ind]<<endl;
                cout<<x<<" inserted at "<<p<<" and "<<temp<<" probed to "<<ind<<endl;
            }
        }
    }

    void search(vector<long long int> arr,long long int key){
        int ind = hashing(key);
        int cmp = 1;
        int flag=1;
        if(arr[ind]==-1){
            // flag=0;
            cout<<key<<" not present in table!!"<<endl;
        }
        else{
            int i=1;
            while(arr[ind]!=key && i<=n-1){
                cmp++;
                ind = (ind+1)%n;
                i++;
            }
            if(arr[ind]==key){
                cout<<key<<" found with "<<cmp<<" comparisions"<<endl;
            }
        }
    }
};

int main(){
    int n;
    cout<<"Enter number of elements :- ";
    cin>>n;
    Hash h(n);
    for(int i=0;i<n;i++){
        long long int key;
        cout<<"Enter key :- ";
        cin>>key;
        h.w_o_rep(key);
        h.w_rep(key);
    }
    h.disp();
    long long int k;
    cout<<"Enter element to search :- ";
    cin>>k;
    vector<long long int> a(n);
    vector<long long int> b(n);
    a = h.get_w_rep_array();
    b = h.get_wo_rep_array();
    cout<<"Searching in with replacement table :- "<<endl;
    h.search(a,k);
    cout<<"Searching in without replacement table :- "<<endl;
    h.search(b,k);
}