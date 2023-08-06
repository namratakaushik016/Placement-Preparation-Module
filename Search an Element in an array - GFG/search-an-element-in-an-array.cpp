//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to search x in arr
    // arr: input array
    // X: element to be searched for
    int linear(int arr[], int n, int k) {
        if (n == 0) {
            return -1; // Element not found
        }
        if (arr[0] == k) {
            return 0; // Element found at index 0
        } else {
            int remainingPart = linear(arr + 1, n - 1, k);
            if (remainingPart == -1) {
                return -1; // Element not found in the remaining part
            }
            return remainingPart + 1; // Adjust the index for the remaining part
        }
    }

    int search(int arr[], int N, int X) {
        return linear(arr, N, X);
    }
};

//{ Driver Code Starts.

int main()
{
    int testcases;
    cin>>testcases;
    while(testcases--)
    {
        int sizeOfArray;
        cin>>sizeOfArray;
        int arr[sizeOfArray];
        int x;
        
        for(int i=0;i<sizeOfArray;i++)
        {
            cin>>arr[i];
        }
        cin>>x;
        Solution ob;
        cout<<ob.search(arr,sizeOfArray,x)<<endl; //Linear search
    }

    return 0;
    
}

// } Driver Code Ends