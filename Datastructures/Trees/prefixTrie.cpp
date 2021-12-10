#include<iostream>
#include<unordered_map>
#include<string>

using std::string;
using std::unordered_map;
using std::cout;
using std::endl;

class PrefixTrie{
    private:
        struct TrieNode{
            char data;
            unordered_map<char, TrieNode*> tmap;
            bool isWord;

            TrieNode(char c){
                data = c;
                isWord = false;
            }
        };
    public:
        TrieNode* root = new TrieNode(' ');

        //insert into trie
        void insert(string word){
            TrieNode* curr = root;
            for(auto &c : word){
                if(curr->tmap[c] == NULL){
                    TrieNode* next = new TrieNode(c);
                    curr->tmap[c] = next;
                }
                curr = curr->tmap[c];
            }
            curr->isWord = true;
        }

        //search in trie
        bool search(string word){
            TrieNode* curr = root;
            for(auto &c : word){
                if(curr->tmap[c] == NULL)
                    return false;
                curr = curr->tmap[c];
            }
            return curr->isWord;
        }

        //starts with
        bool startsWith(string prefix){
            TrieNode* curr = root;
            for(auto &c : prefix){
                if(curr->tmap[c] == NULL)
                    return false;
                curr = curr->tmap[c];
            }
            return true;
        }
};

int main(){
    PrefixTrie* trie = new PrefixTrie();
    trie->insert("apple");
    trie->insert("application");
    trie->insert("boggle");
    cout << trie->search("apple") << endl;
    cout << trie->startsWith("appl") << endl;
    cout << trie->search("app") << endl;
    cout << trie->startsWith("bo") << endl;
    return 0;
}
