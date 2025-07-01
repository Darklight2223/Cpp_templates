
struct trieNode {
    trieNode *children[26];
    bool isend;
    int pref=0;
    trieNode() {
        isend = false;
        pref=0;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
    private :
        trieNode *root;
    public :
        Trie() {
            root = new trieNode();
        }

        void insert(string word) {
            trieNode *curr = root;
            for (char c : word) {
                int index = c - 'a';
                if (curr->children[index] == nullptr) {
                    curr->children[index] = new trieNode();
                }
                curr = curr->children[index];
                curr->pref++;
            }
            curr->isend = true;
        }

        bool search(string word) {
            trieNode *curr = root;
            for (char c : word) {
                int index = c - 'a';
                if (curr->children[index] == nullptr) {
                    return false;
                }
                curr = curr->children[index];
            }
            return curr->isend;
        }

        int startsWith(string prefix) {
            trieNode *curr = root;
            for (char c : prefix) {
                int index = c - 'a';
                if (curr->children[index] == nullptr) {
                    return 0; 
                }
                curr = curr->children[index];
            }
            return curr->pref; 
        }
};

