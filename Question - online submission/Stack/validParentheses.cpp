//
// Created by amir on 8/19/22.
//

//check valid parenthesis
//leetcode and coding studio - Easy

class Solution {


private:


    bool isOpenBracket(char ch){
        if(ch=='[' or ch=='{' or ch=='('){
            return true;
        }else return false;
    }




    bool isMatch(char a, char b){
        if(a=='[' and b==']'){
            return true;
        }else if(a=='{' and b=='}'){
            return true;
        }else if(a=='(' and b==')'){
            return true;
        }
        else{
            return false;
        }
    }



public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            char element = s[i];
            if(element=='(' or element=='[' or element == '{'){
                st.push(element);
            }else{
                if(!st.empty()){
                    char topBracket = st.top();
                    if(isMatch(topBracket,element)){
                        st.pop();
                    }else{
                        return false;
                    }}else{
                    return false;
                }
            }


        }



        if(st.empty()){
            return true;
        }else{
            return false;
        }

    }
};