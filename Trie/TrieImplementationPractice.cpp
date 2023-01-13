//
// Created by amir on 12/26/22.
//

#include "iostream"
using namespace std;

class TrieNode{

public:
    char data;
    TrieNode *children[26];
    bool isTerminal ;

    TrieNode(char data){
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        data = data;
        isTerminal =  false;
    }

};

class Trie{

private:
    TrieNode * rootNode= new TrieNode('\0');
    bool searchUtil(TrieNode*node,string word){
        if(word.length()==0){
            if(node->isTerminal== true){
                return true;// found
            }else{
                return false;//not found ending part;
            }

        }
        int index = word[0]-'a';
        TrieNode * temp;
        if(node->children[index]==NULL){
            return false;//not found
        }
        temp = node->children[index];
        return searchUtil(temp,word.substr(1));
    }
    void insertion(TrieNode*node,string word){
        //base case
        if(word.length()==0){
            node->isTerminal = true;
            return;
        }
        //find index of word;
        int index = word[0]-'a';
        TrieNode *temp;
        if(node->children[index]==NULL){
            node->children[index] = new TrieNode(word[0]);
            temp = node->children[index];
        }else{
            temp = node->children[index];
        }

        //now pass string without first characete

        insertion(temp,word.substr(1));


    }
public:
    void insert(string word){
        return insertion(rootNode,word);
    }



    bool search(string word){
        return searchUtil(rootNode,word);
    }

};

int main(){

    Trie trie;
    trie.insert("car");
    trie.insert("ca");

    cout<<trie.search("car")<<endl;
    cout<<trie.search("ca");


    return 0;
}