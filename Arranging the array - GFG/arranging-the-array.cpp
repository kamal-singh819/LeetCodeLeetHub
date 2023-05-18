//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

void Rearrange(int arr[], int n);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        long long j=0;
      
        Rearrange( arr, n);
      
        for (int i = 0; i < n; i++) 
            cout << arr[i] << " "; 
        cout << endl;  
    }
    return 0; 
} 
// } Driver Code Ends



void Rearrange(int arr[], int n)
{
    vector<int> v;
    for(int i=0; i<n; i++){
        if(arr[i] < 0) v.push_back(arr[i]);
    }
    
    int i = n-1, j = n-1;
    while(i >= 0){
        while(i >= 0 && arr[i] < 0) i--;
        arr[j] = arr[i];
        j--;
        i--;
    }
    for(int k=0; k<v.size(); k++) arr[k] = v[k]; 
}