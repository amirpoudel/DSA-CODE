//
// Created by amirp on 11/21/2022.
//

//Word Break Problem using Trie  - cannot pass test case; //Run time error

#include <bits/stdc++.h>

class TrieNode{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    int frequency;

    TrieNode(char ch){
        data = ch;
        for(int i=0;i<26;i++){
            children[i]==NULL;
        }
        isTerminal = false;
        frequency = 0;

    }

};

class Trie{
public:
    TrieNode *root;

    Trie(){
        root = new TrieNode('\0');
    }

    void insertion(TrieNode *root,string word){
        if(word.length()==0){

            root->isTerminal = true;
            return;
        }
        int index = word[0]-'a';
        TrieNode * child;
        if(root->children[index]==NULL){
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }else{
            child = root->children[index];
        }
        word = word.substr(1);
        root->frequency++;
        insertion(child,word);
    }

    void insert(string word){
        insertion(root,word);
    }

    bool searchuntil(TrieNode*root,string&word){
        if(word.length()==0){
            return root->isTerminal;
        }
        int index = word[0]-'a';
        TrieNode* child;
        if(root->children[index]!=NULL){
            child = root->children[index];
        }else {
            return false;
        }
        word = word.substr(1);
        return searchuntil(child,word);
    }

    bool search(string&word){
        return searchuntil(root,word);
    }

    bool wordbreak(TrieNode*root,string&target){

        if(target.length()==0){
            return true;
        }

        for(int i =1;i<=target.length();i++){

            string searchKey = target.substr(0,i);
            string word  = target.substr(i,target.length()-1);
            if(search(searchKey) and wordbreak(root,word)){


                return true;

            }
        }
        return false;

    }


    bool wordBreakProblem(string &target){
        int ans = wordbreak(root,target);
        return ans;
    }


};

bool wordBreak(vector < string > & arr, int n, string & target) {
    // Write your code here.
    //inserting in a trie;
    Trie trie;
    for(int i=0;i<n;i++){
        trie.insert(arr[i]);
    }
    bool result = trie.wordBreakProblem(target);
    return result;
}












//
//
//#include <bits/stdc++.h>
//
//class TrieNode{
//public:
//    char data;
//    TrieNode*children[26];
//    int frequency;
//    bool isEnding;
//
//    TrieNode(char ch){
//        data = ch;
//        for(int i=0;i<26;i++){
//            children[i] = NULL;
//        }
//        isEnding = false;
//    }
//};
//
//class Trie{
//public:
//    TrieNode *root;
//    Trie(){
//        root = new TrieNode('\0');
//    }
//    void insertion(TrieNode*root,string&word){
//        if(word.length()==0){
//            root->isEnding = true;
//            return;
//        }
//        int index = word[0]-'a';
//        TrieNode*child ;
//        if(root->children[index]==NULL){
//            //absent case
//            child   = new TrieNode(word[0]);
//            root->children[index]= child;
//        }else{
//            //present case
//            child = root->children[index];
//        }
//        root->frequency++;
//        word = word.substr(1);
//        insertion(child,word);
//    }
//    void insert(string &word){
//        insertion(root,word);
//    }
//    bool searchRecursion(TrieNode*root,string &target){
//        if(target.length()==0){
//            return root->isEnding;
//        }
//        int index = target[0]-'a';
//        TrieNode*child;
//        if(root->children[index]!=NULL){
//            child = root->children[index];
//        }else{
//            return false;
//        }
//        target   = target.substr(1);
//        return searchRecursion(child,target);
//    }
//    bool search(string &target){
//        return searchRecursion(root,target);
//    }
//
//    bool wordbreak(string&target){
//        if(target.length()==0){
//            return true;
//        }
//
//        for(int i=1;i<=target.length();i++){
//
//            string searchString = target.substr(0,i);
//            string wordString = target.substr(i,target.length());
//
//
//            if(search(searchString)&&wordbreak(wordString)){
//                return true;
//            }
//
//        }
//        return false;
//
//    }
//};
//
//bool wordBreak(vector < string > & arr, int n, string & target) {
//    // Write your code here.
//    Trie trie;
//    for(int i=0;i<n;i++){
//        trie.insert(arr[i]);
//    }
//    bool ans =trie.wordbreak(target);
//    if(ans){
//        return true;
//    }else return false;
//}