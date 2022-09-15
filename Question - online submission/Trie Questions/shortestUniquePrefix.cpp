//
// Created by amir on 9/11/22.
//
// shortest unique prefix - code studio


class TrieNode{
public:
    char data;
    TrieNode* children[26];
    int frequency;
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        frequency=0;
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

        int index = word[0]-'a';

        TrieNode* child;

        //present case
        if(root->children[index]!=NULL){

            child = root->children[index];
        } else{
            //absent case;
            child = new  TrieNode(word[0]);
            root->children[index]=child;
        }

        root->children[index]->frequency++;
        //call recursion

        insertUtil(child,word.substr(1));
    }

    void insertion(string word){
        insertUtil(root,word);
    }




    string shortestPrefix( string str){
        TrieNode*curr = root;
        string ans = "";
        for(int i=0;i<str.length();i++){
            if(curr->frequency==1){
                break;
            }
            ans.push_back(str[i]);
            int index = str[i]-'a';
            curr = curr->children[index];
        }

        return ans;


    }
};


vector<string> shortestUniquePrefix(vector<string> s, int n) {
    // Write your code here.
    Trie t;

    vector<string> ans;
    for(int i=0;i<n;i++){
        t.insertion(s[i]);
    }

    for(int i=0;i<n;i++){
        ans.push_back(t.shortestPrefix(s[i]));
    }
    return ans;
}