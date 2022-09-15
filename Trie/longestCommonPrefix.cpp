

class TrieNode{
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    int childCount;

    TrieNode(char ch){
        data = ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal = false;
        childCount = 0;

    }
};


class Trie{
public:

    TrieNode * root;
    Trie(char ch){
        root = new TrieNode(ch);
    }

    void insertUtil(TrieNode*root,string word){
        if(word.length()==0){
            root->isTerminal = true;
            return;
        }

        int index = word[0]-'a';
        TrieNode* child;
        if(root->children[index]!=NULL){
            child = root->children[index];
        }else{
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;

        }
        insertUtil(child,word.substr(1));
    }

    void insert(string word){
        insertUtil(root,word);
    }


    void lcp(string str,string &ans){

        for(int i=0;i<str.length();i++){

            char ch = str[i];

            if(root->childCount==1){
                ans.push_back(ch);
                int index = ch-'a';
                root = root->children[index];

            }else{
                break;
            }

            if(root->isTerminal){
                break;
            }
        }

    }




};


string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    //insert all string into trie;

    Trie *t=new Trie('\0');
    for(int i=0;i<n;i++){
        t->insert(arr[i]);
    }
    string ans = "";
    string first= arr[0];
    t->lcp(first,ans);
    return ans;



}
