class Solution {
public:
    string longestPalindrome(string s) {
        
     int n = s.size();
    string rs(s.rbegin(), s.rend());
    string ans = "";

    vector<vector<int>> dp(2, vector(n+1, 0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(s[i-1] == rs[j-1]){
                dp[i%2][j] = dp[(i+1)%2][j-1] + 1;
            }else{
                dp[i%2][j] = 0;
            }

            if(dp[i%2][j] > ans.size() && i+j == dp[i%2][j]+n){
                ans = s.substr(i-dp[i%2][j], dp[i%2][j]);
            }
        }
    }

    return ans;
}
};