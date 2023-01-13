//
// Created by amirp on 11/6/2022.
//
//Reverse String Using Stack - GFG

//return the address of the string
char* reverse(char *S, int len)
{
    //code here
    stack<char>st;
    for(int i=0;i<len;i++){
        st.push(S[i]);
    }
    char *answer =new char[len];
    int i=0;
    while(!st.empty()){
        answer[i]=st.top();
        i++;
        st.pop();
    }
    return answer;
}