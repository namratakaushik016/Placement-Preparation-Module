class Solution {
public:
    string reverseWords(string s) {
        vector<string>words;
        int i=0;
        
        while(i<s.size()){
            while(s[i]==' ' && i<s.size()){
                i++;
                continue;
            }
            if(i==s.size()) break;
            string temp="";
            while(s[i]!=' ' && i<s.size()){
                temp+=s[i];
                i++;
            }
            words.push_back(temp);
        }
        reverse(words.begin(),words.end());
        string ans="";
        
        for(int i=0;i<words.size();i++){
            ans+=words[i];
            if(i!=words.size()-1){
                ans +=" ";
            }
        }
        return ans;
    }
};