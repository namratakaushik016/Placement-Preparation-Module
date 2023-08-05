//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    if (m > n) {
        return -1; // Not enough packets to distribute among students
    }

    sort(a.begin(), a.end());

    long long minDiff = a[m - 1] - a[0]; // Initialize with the maximum difference for the first possible window
    for (long long i = 1; i <= n - m; ++i) {
        minDiff = min(minDiff, a[i + m - 1] - a[i]);
    }

    return minDiff;
    }   
};

//{ Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
// } Driver Code Ends