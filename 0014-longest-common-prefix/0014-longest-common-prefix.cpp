class TrieNode{
    public:
        char data;
        TrieNode * children[26];
        int childCount;
        bool isTerminal;

        TrieNode(char data){
            this -> data = data;
            this -> isTerminal = false;
            this -> childCount = 0;
            for(int i = 0; i < 26; i++){
                this -> children[i] = NULL;
            }
        }
};

class Trie{
    public:
        TrieNode * root;
    Trie(){
        this -> root = new TrieNode('\0');
    }
    void insertUtil(TrieNode * root, string word){
        if(word.size() == 0){
            root -> isTerminal = true;
            return;
        }

        int ind = word[0] - 'a';

        if(root -> children[ind] != NULL){
            insertUtil(root -> children[ind], word.substr(1));
        } else {
            root -> children[ind] = new TrieNode(word[0]);
            root -> childCount++;
            insertUtil(root -> children[ind], word.substr(1));
        }
    }

    
    void insertWord(string word){
        insertUtil(root, word);
    }
    
    void lsp(string str, string &ans){
        for(auto c : str){
            if(root -> childCount == 1){
                ans.push_back(c);
                int ind = c - 'a';
                root = root -> children[ind];
            } else break;
            
            if(root -> isTerminal) break;
            
        }
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie * t = new Trie();
        for(auto word : strs) {
            //our trie doesn't support empty string so need to handle explicitly
            if(word.empty())
                return "";
            t->insertWord(word);
        }
        
        string ans = "";
        t -> lsp(strs[0], ans);
        
        return ans;
    }
};
    /*string longestCommonPrefix(vector<string>& arr) {
        string ans="";
        //traversing char of 1st string
        for(int i=0;i<arr[0].length();i++){
            char ch = arr[0][i];
            bool match = true;
            for(int j =1;j<arr.size();j++){
                //not match
                if( arr[j].size() < i || ch !=arr[j][i]){
                    match = false;
                    break;
                }
            }
            if(match==false){
                break;
            }else{
                ans.push_back(ch);
            }
        }
        return ans;
    }*/













