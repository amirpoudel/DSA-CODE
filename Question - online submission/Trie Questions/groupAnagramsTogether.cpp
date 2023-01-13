//
// Created by amirp on 11/22/2022.
//


#include <bits/stdc++.h>

class TrieNode{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    int frequency = 0;
    vector<int>index;

    TrieNode(char ch){
        data = ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal = false;
    }
};

class Trie{
public:
    TrieNode*root;

    Trie(){
        root = new TrieNode('\0');;
    }

    void insertion(TrieNode*root,string&word,int i){
        if(word.length()==0){
            root->index.push_back(i);
            root->isTerminal=true;
            return;
        }
        int index = word[0]-'a';
        TrieNode*child;
        if(root->children[index]==NULL){
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }else{
            //present case GO ON
            child = root->children[index];
        }
        //increase frequency;
        root->frequency++;
        word = word.substr(1);
        insertion(child,word,i);
    }

    void  insert(string &word,int i){
        insertion(root,word,i);
    }

    void findIndex(TrieNode*root,vector<int>&indexs){
        if(root->isTerminal=true){
            for(int i=0;i<root->index.size();i++){
                indexs.push_back(root->index[i]);
            }
            return;
        }
        TrieNode*child;
        for(int i=0;i<26;i++){
            if(root->children[i]!=NULL){
                child = root->children[i];
                findIndex(child,indexs);
            }
        }
    }

    vector<int> findIndexToGroup(){
        vector<int>indexs;
        findIndex(root,indexs);
        return indexs;
    }

};


vector<vector<string> > groupAnagramsTogether(vector<string> &strList)
{


    Trie *root;

    vector<string>test;
    vector<string>sortedString;
    for(int i=0;i<strList.size();i++){
        string str  = strList[i];
        sort(str.begin(),str.end());
        sortedString.push_back(str);
    }
    for(int i=0;i<sortedString.size();i++){
        root->insert(sortedString[i],i);
    }
    //result store variable;
    // vector<int>index = root->findIndexToGroup();
//     for(int i=0;i<index.size();i++){

//     }



    vector<vector<string>> result;
    result.push_back(test);
    return result;

}