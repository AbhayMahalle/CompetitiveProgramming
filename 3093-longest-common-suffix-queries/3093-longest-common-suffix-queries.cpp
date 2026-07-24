class TrieNode{
public:
    int children[26];
    int isEnd;
    TrieNode(){
        isEnd = -1;
        for(int i = 0; i < 26; i++)
            children[i] = -1;
    }
};
class Trie{
private:
    vector<TrieNode> trie;
public:
    Trie(){
        trie.push_back(TrieNode()); 
    }
    void insert(string word, int i, vector<string>& wc){
        int current = 0;

        if(trie[current].isEnd == -1)
            trie[current].isEnd = i;
        else{
            int old = trie[current].isEnd;
            if(wc[old].size() > wc[i].size() || (wc[old].size() == wc[i].size() && old > i))
                trie[current].isEnd = i;
        }

        for(char ch : word){

            int index = ch - 'a';

            if(trie[current].children[index] == -1){
                trie[current].children[index] = trie.size();
                trie.push_back(TrieNode());
                trie.back().isEnd = i;
            }

            current = trie[current].children[index];

            if(trie[current].isEnd == -1)
                trie[current].isEnd = i;
            else{
                int old = trie[current].isEnd;
                if(wc[old].size() > wc[i].size() || (wc[old].size() == wc[i].size() && old > i))
                    trie[current].isEnd = i;
            }
        }
    }

    int prefixx(string word){
        int current = 0;
        int ans = trie[0].isEnd;
        for(char ch : word){
            int index = ch - 'a';
            if(trie[current].children[index] == -1)
                return ans;
            current = trie[current].children[index];
            ans = trie[current].isEnd;
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer,vector<string>& wordsQuery) {
        for(auto &s : wordsContainer)
            reverse(s.begin(), s.end());

        for(auto &s : wordsQuery)
            reverse(s.begin(), s.end());

        Trie trie;
        for(int i = 0; i < wordsContainer.size(); i++)
            trie.insert(wordsContainer[i], i, wordsContainer);
        vector<int> res;
        for(auto &s : wordsQuery)
            res.push_back(trie.prefixx(s));
        return res;
    }
};