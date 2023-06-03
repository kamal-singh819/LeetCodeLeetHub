//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxEqualSum(int N1,int N2,int N3,vector<int> &S1,vector<int> &S2,vector<int> &S3){
        int sum1 = 0, sum2 = 0, sum3 = 0;
        for(int i=0; i<N1; i++) sum1 += S1[i];
        for(int i=0; i<N2; i++) sum2 += S2[i];
        for(int i=0; i<N3; i++) sum3 += S3[i];
        
        if(sum1 == sum2 && sum1 == sum3) return sum1;
        int i = 0, j = 0, k = 0;
        
        while(1){
            if(sum1 == sum2 && sum1 == sum3) return sum1;
            int m = min(sum1, min(sum2, sum3));
            if(m == 0) return 0;
            
            while(i < N1 && sum1 > m){
                sum1 -= S1[i];
                i++;
            }
            while(j < N2 && sum2 > m){
                sum2 -= S2[j];
                j++;
            }
            while(k < N3 && sum3 > m){
                sum3 -= S3[k];
                k++;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        vector<int> s1(n1),s2(n2),s3(n3);
        for(int i=0;i<n1;i++){
            cin>>s1[i];
        }
        for(int i=0;i<n2;i++){
            cin>>s2[i];
        }
        for(int i=0;i<n3;i++){
            cin>>s3[i];
        }
        Solution ob;
        int ans=ob.maxEqualSum(n1,n2,n3,s1,s2,s3);
        cout<<ans<<endl;
    }
    
    return 0;
}
// } Driver Code Ends