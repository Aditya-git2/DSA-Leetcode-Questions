class Node {
public:
    char data;
    bool terminal;
    unordered_map<char, Node*> children;
    // constructor
    Node(char data) {
        this->data = data;
        this->terminal = false;   
    }
    void makeTerminal() { this->terminal = true; }
    bool isTerminal() { return this->terminal == true; }
};

class Trie {
public:
    Node* root; // create root node
    Trie() {
        root = new Node('\0'); // as root Node is always NULL
    }

    void insert(string word) {
        Node* curr = root;
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i]; // curr char to be checked
            if (curr->children.count(ch)) {
                curr = curr->children[ch];
            } else {
                Node* child = new Node(ch);
                curr->children[ch] = child;
                curr = child;
            }

        } // as curr is now pointing to last char of word
        curr->makeTerminal();
    }

    bool search(string word) {
        Node* curr = root;
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            if (curr->children.count(ch)) {
                curr = curr->children[ch];
            } else {
                // we don't have a char
                return false;
            }
        }
        // now curr will be at end of word check it is a terminal node or not
        return curr->isTerminal();
    }

    bool startsWith(string prefix) {
        Node* curr = root;
        for (int i = 0; i < prefix.size(); i++) {
            char ch = prefix[i];
            if (curr->children.count(ch)) {
                curr = curr->children[ch];
            } else {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */