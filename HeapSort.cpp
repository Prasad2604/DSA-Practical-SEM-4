#include<iostream>
#include<vector>

using namespace std;

class HeapSort{
    private:
    void heapify(vector<int> &arr,int n,int i){
        int largest = i;
        int left = 2*i+1;
        int right = 2*i+2;
        if(left<n && arr[left]>arr[largest]){
            largest = left;
        }
        if(right<n && arr[right]>arr[largest]){
            largest = right;
        }
        if(i!=largest){
            swap(arr[i],arr[largest]);
            // PrintArray(arr);
            heapify(arr,n,largest);

        }
    }
    // void buildMaxHeap(vector<int> &arr,int n){
    //     int start = n/2-1; //last internal node
    //     for(int i=start;i>=0;i--){
    //         heapify(arr,n,i);
    //     }
    // }
    public:
    void buildMaxHeap(vector<int> &arr,int n){
        int start = (n/2)-1; //last internal node
        for(int i=start;i>=0;i--){
            this->heapify(arr,n,i);
        }
        // PrintArray(arr);
    }
    void sort(vector<int> &arr,int n){
        buildMaxHeap(arr,n);
        
        for(int i=n-1;i>=0;i--){
            swap(arr[0],arr[i]);
            this->heapify(arr,i,0);
        }
    }
    void PrintArray(vector<int>&arr){
        for(auto i:arr){
            cout<<i<<" ";
        }
        cout<<endl;
    }
};


int main(){
    HeapSort h;
    int n;
    cout<<"Enter number of elements you wanna insert :- ";
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Original Array :- "<<endl;
    h.PrintArray(arr);
    cout<<"Max Heap :- "<<endl;
    h.buildMaxHeap(arr,n);
    h.PrintArray(arr);
    cout<<"Sorted Array :- "<<endl;
    h.sort(arr,n);
    h.PrintArray(arr);
}