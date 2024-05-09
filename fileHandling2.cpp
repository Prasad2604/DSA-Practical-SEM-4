#include<iostream>
#include<fstream>

using namespace std;

class hash{
    int arr[10];
    int arr1[10];
    public:
    hash(){
        for(int i=0;i<10;i++){
            arr[i]=-1;
            arr1[i]=-1;
        }
    }
    int hashing(int x){
        return x%10;
    }
    void prob(int x,int loc,int ind){
        while(arr[ind]!=-1){
            ind = (ind+1)%10;
        }
        arr[ind] = x;
        arr1[ind] = loc;
    }
    void insert(int x,int loc){
        int ind = hashing(x);
        if(arr[ind]==-1){
            arr[ind] = x;
            arr1[ind] = loc;
        }
        else{
            int temp = arr[ind];
            int temp1 = arr1[ind];
            if(hashing(temp)==ind){
                prob(x,loc,ind);
            }
            else{
                arr[ind] = x;
                arr1[ind] = loc;
                prob(temp,temp1,ind);
            }
        }
    }
    int search(int x){
        int ind = hashing(x);
        bool found = 0;
        while(arr[ind]!=-1){
            if(arr[ind]==x){
                found=1;
                cout<<"Element found!!"<<endl;
                return arr1[ind];
            }
            ind = (ind+1)%10;
            if(ind == hashing(x)){
                break;
            }
        }
        if(found==0){
            cout<<"Element not found!!"<<endl;
        }
        return -1;
    }
    void delete_hash(int x){
        int ind = hashing(x);
        while(arr[ind]!=-1){
            if(arr[ind]==x){
                arr[ind]=-1;
                arr1[ind]=-1;
                break;
            }
            ind = (ind+1)%10;
            if(ind==hashing(x)){
                cout<<"Element not found!!"<<endl;
                break;
            }
        }
    }
};