class Solution {
public:
    bool isValid(string s) {
        stack<char>k;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            //if it is opening bracket then push in stack
            //if it is closing bracket compare it to top and pop
            
            if(ch=='(' || ch=='[' || ch=='{'){
                k.push(ch);
            }
            else{
                //for closing bracket
                if(!k.empty()){
                    char top=k.top();
                    if((ch=='}' && top=='{')||
                        (ch==')' && top=='(')||
                      (ch==']' && top=='[') ){
                        k.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        if(k.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};