//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int binarySearch(int arr[], int start, int end, int element) {
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] == element) {
                return mid;
            } else if (arr[mid] < element) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1; // Return -1 if the element is not found
    }

    int kthSmallest(int arr[], int l, int r, int k) {
        sort(arr, arr + r + 1); // Sort the array before applying binary search
        int index = binarySearch(arr, l, r, arr[k-1]);
        return arr[index];
    }
    
};

//{ Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends