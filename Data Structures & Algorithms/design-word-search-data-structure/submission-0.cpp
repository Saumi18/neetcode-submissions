class TrieNode{
public:
    TrieNode* children[26];
    bool endOfWord;

    TrieNode(){
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        endOfWord = false;
    }
};

class WordDictionary {
    TrieNode* root;
    bool dfs(TrieNode* cur, string& word, int index) {
        if (index == word.size()) {
            return cur->endOfWord;
        }
        char c = word[index];

        if (c == '.') {
            for (int i = 0; i < 26; i++) {
                if (cur->children[i] != NULL) {
                    if (dfs(cur->children[i], word, index + 1)) {
                        return true;
                    }
                }
            }
            return false;
        }

        int i = c - 'a';
        if (cur->children[i] == NULL) {
            return false;
        }
        return dfs(cur->children[i], word, index + 1);
    }
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for(char c : word){
            int i = c-'a';
            if(cur->children[i]==NULL){
                cur->children[i] = new TrieNode();
            }
            cur = cur->children[i];
        }
        cur->endOfWord = true;
    }
    
    bool search(string word) {
        return dfs(root,word,0);
    }
};
