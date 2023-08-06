class Solution {
public:
   int solve(vector<int>& arr,int s,int e,int k) {
       if(s>e){
           return-1;
       }
       int mid=s+(e-s)/2;
       cout<<arr[mid]<<endl;
       
       if(arr[mid]==k)
           return mid;
       if(arr[mid]<k){
           return solve(arr,mid+1,e,k);
           
       }
       else{
           return solve(arr,s,mid-1,k);
       }
       
   }   
    int search(vector<int>& nums, int target) {
       return solve(nums,0,nums.size()-1,target);
}
};