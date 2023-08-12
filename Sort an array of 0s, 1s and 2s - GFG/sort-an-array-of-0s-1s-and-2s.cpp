//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    { 
        //dutch national flag algorithm
        int low=0;
        //Initialize the low pointer to 0.This will be used to keep track of the position where 
       //the next 0 should be placed.
        int high=n-1;
        //Initialize the high pointer to n - 1. 
        //This will be used to keep track of the position where the next 2 should be placed.
        int mid=0;
        //Initialize the mid pointer to 0. 
        //This will be used to traverse the array from the beginning to the end.
        while(mid<=high){
            // Start a loop that runs as long as mid is less than or equal to high. 
            //This loop processes the array elements until the mid and high pointers cross each other.
            switch(a[mid]){
                case 0:
                swap(a[mid],a[low]);
                low++;
                mid++; //Inside the loop, we use a switch-case construct to handle three cases:
                break;
                                          //a. case 0: - If the value at a[mid] is 0:

                                     //Swap the value at a[low] with the value at a[mid]. 
                                    //This moves the 0 to the left side of the array.
                                    //Increment both low and mid. This moves the low pointer to the right.



                
                
                case 1://b. case 1: - If the value at a[mid] is 1:
                mid++;//No swapping is needed for 1.
                break;//Simply increment mid. This moves the mid pointer to the next element
                
                case 2://If the value at a[mid] is 2:
                swap(a[mid],a[high]);//Swap the value at a[mid] with the value at a[high]. This moves the 2 to the right side of the array.
                high--;
                break;//Decrement high. This moves the high pointer to the left.
            }
            
            
        }
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends