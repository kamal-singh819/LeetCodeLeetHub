//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    using ll = long long int;
    ll mergeFunction(ll arr[], ll low, ll mid, ll high, ll n){
        vector<ll> temp;
        ll left = low; //starting index of left partition
        ll right = mid+1; //starting index of right partition
        ll cnt = 0;
        
        //now store the elements in temp array in sorted order
        while(left <= mid && right <= high){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                cnt += (mid-left+1);
                right++;
            }
        }
        //if any elements still left in left partition
        while(left <= mid){
            temp.push_back(arr[left]);
            left++;
        }
        //same if any elements still left in right partition
        while(right <= high){
            temp.push_back(arr[right]);
            right++;
        }
        
        //now temp array has all elements in sorted array, so copy into arr from temp
        for(int i=low; i<=high; i++){
            arr[i] = temp[i-low];
        }
        return cnt;
    }
    
    
    //this is the mergeSort recursive function
    ll mergeSort(ll arr[], ll low, ll high, ll n){
        ll count = 0;
        if(low >= high) return count;
        ll mid = (low+high)/2;
        count = count + mergeSort(arr, low, mid, n);  //call left 
        count = count + mergeSort(arr, mid+1, high, n); //call right
        count = count + mergeFunction(arr, low, mid, high, n); //merge left and right partition
        return count;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        ll ans = mergeSort(arr, 0, N-1, N);
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends