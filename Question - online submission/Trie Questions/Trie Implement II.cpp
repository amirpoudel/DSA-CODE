//
// Created by amirp on 11/21/2022.
//
//Trie Implement II - code stuido taste case fall   - why fail i can't find;

#include <bits/stdc++.h>

class TrieNode{
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    int count = 0;
    int endingWord = 0;
    int countPrefix = 0;

    TrieNode(char ch){
        isTerminal = false;
        data = ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }

    }
};

class Trie{

public:
    //declare TrieNode
    TrieNode *root;

    Trie(){
        // Write your code here.
        root = new TrieNode('\0');
    }

    void insertion(TrieNode *root,string&word){
        //base case
        if(word.length()==0){
            root->isTerminal = true;
            root->endingWord++;
            return;
        }
        int index = word[0]-'a';
        TrieNode *child;
        //present case
        if(root->children[index]!=NULL){
            child = root->children[index];
        } else{
            //absent case;
            child = new  TrieNode(word[0]);
            root->children[index]=child;
        }
        //increasing counting ;
        root->count++;
        root->countPrefix++;
        //calling Recursion
        word = word.substr(1);
        insertion(child,word);
    }

    void insert(string &word){
        // Write your code here.

        insertion(root,word);
    }

    int countWords(TrieNode*root,string&word){
        if(word.length()==0){
            return root->endingWord;

        }
//         if(root->isTerminal==true){
//             return root->count;
//         }
        int index = word[0]-'a';
        //check in root node
        TrieNode *child;
        if(root->children[index]!=NULL){
            child = root->children[index];
        }else{
            return 0;
        }
        //search
        word = word.substr(1);
        int data = countWords(child,word);
        return data;
    }
    int countWordsEqualTo(string &word){
        // Write your code here.
        int val =  countWords(root,word);
        return val;
    }

    int countWordsStart(TrieNode*root,string&word){
        if(word.length()==0){
            return root->countPrefix;

        }

        int index = word[0]-'a';
        //check in root node
        TrieNode *child;
        if(root->children[index]!=NULL){
            child = root->children[index];
        }else{
            return 0;
        }
        //search
        word = word.substr(1);
        int data  = countWordsStart(child,word);
        return data;
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        int val =  countWordsStart(root,word);
        return val;
    }

    void remove(TrieNode*root,string&word){
        if(word.length()==0){
            if(root->endingWord>0){
                root->endingWord--;
            }

            root->isTerminal = false;
            return;
        }

        TrieNode * child ;
        int index = word[0]-'a';
        if(root->children[index]!=NULL){
            child = root->children[index];
        }else{
            return;
        }
        if(root->countPrefix>0){
            root->countPrefix--;
        }

        word  = word.substr(1);
        remove(child,word);


    }

    void erase(string &word){
        // Write your code here.
        remove(root,word);
    }
};
