//
// Created by amir on 9/4/22.
//
//Trie Implement


#include "iostream"

using namespace std;

class TrieNode{
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

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
    TrieNode* root;
    Trie(){
        root = new TrieNode('\0');
    }
    void insertUtil(TrieNode* root,string word){
        //base case
        if(word.length()==0){
            root->isTerminal = true;
            return;
        }

        int index = word[0]-'A';

        TrieNode* child;

        //present case
        if(root->children[index]!=NULL){
            child = root->children[index];
        } else{
            //absent case;
            child = new  TrieNode(word[0]);
            root->children[index]=child;
        }
        //call recursion

        insertUtil(child,word.substr(1));
    }

    void insertion(string word){
        insertUtil(root,word);
    }

    bool searchUtil(TrieNode* root,string word){
        //base case
        if(word.length()==0){
            return root->isTerminal;
        }

        TrieNode*child;
        int index = word[0]-'A';
        if(root->children[index]!=NULL){
            //present case;
            child = root->children[index];
        }else{
            return false;
        }

        return searchUtil(child,word.substr(1));


    }

    bool search(string word){
        return searchUtil(root,word);
    }
    void removeUtil(TrieNode*root,string word){
        if(word.length()==0){
            root->isTerminal= false;
            return;
        }

        TrieNode* child;
        int index= word[0]-'A';
        if(root->children[index]!=NULL){
            child  = root->children[index];
        }else{
            return;
        }

        removeUtil(child,word.substr(1));



    }

    void remove(string word){
       removeUtil(root,word);
    }


};

int main(){

    Trie t;
    t.insertion("abcd");
    t.insertion("amir");
    cout<<t.search("abc");
    cout<<endl<<t.search("amir");
    t.remove("amir");
    cout<<endl<<t.search("amir");




    return 0;
}