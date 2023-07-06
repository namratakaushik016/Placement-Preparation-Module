class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        set<char>Set;    //creating a set Set;
        
        int Max=0;
        //two pointers
        int start=0;
        int end=0;
        while(start<s.size()){
            
            auto it=Set.find(s[start]);// to find current element is present in the string or not
        
           if(it==Set.end())
           {
               if(start-end+1>Max)
                   Max= start-end+1;
               Set.insert(s[start]);
               start++;
           }
            
            else{
                Set.erase(s[end]);
                end++;
            }
        }
        
        
        
        
        
        
        return Max;
    }
};