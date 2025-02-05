#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;


ll findLongestIncreasingSubArray(vector<int> &arr){
    
    ll ans=0;
    
    int n=arr.size();
    ll global_max=1;
    ll current_length=1;
    for(int i=1;i<n;i++){
        
        if(arr[i-1]<=arr[i]){
            current_length++;
            global_max=max(current_length,global_max);
            
        }
        else{
            current_length=1;
        
        }
    }

    
    return global_max;
    
}


int main() {
	// your code goes here
	int t;
	cin>>t;
	
	
	while(t--){
	    
	    int n,x;
	    cin>>n>>x;
	    
	    vector<int> arr; 
	    for(int i=1;i<=n;i++){
	        int temp;
	        cin>>temp;
	        arr.push_back(temp);
	    }
	    
	    ll max_increasing_array_before_Multiplier=findLongestIncreasingSubArray(arr);
	    
	    ll max_increasing_array_after_Multiplier=max_increasing_array_before_Multiplier;
	    for(int i=0;i<n;i++){
	        vector<int> A=arr;
	        A[i]=x*A[i];
	        
	        max_increasing_array_after_Multiplier=max(max_increasing_array_after_Multiplier,findLongestIncreasingSubArray(A));  
	    }
	    
	    cout<<max_increasing_array_after_Multiplier<<endl;
	      
	}
}
