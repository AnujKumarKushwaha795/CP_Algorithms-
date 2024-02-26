#include<bits/stdc++.h>
using namespace std;

struct Node {
    Node* link[52]; 
    bool flag = false;

    Node() {
        for (int i = 0; i < 52; ++i) {
            link[i] = nullptr;
        }
    }

    bool isLink(char ch) {
        return link[ch - 'A'] != nullptr || link[ch - 'a' + 26] != nullptr;
    }

    Node* getLink(char ch) {
        if (isupper(ch)) {
            return link[ch - 'A'];
        } else {
            return link[ch - 'a' + 26];
        }
    }
};

class Trie {
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    Node* getRoot() {
        return root;
    }

    void insert(string w) {
        Node* node = root;
        int N = w.size();
        for (int i = 0; i < N; i++) {
            char ch = w[i];
            int index = isupper(ch) ? (ch - 'A') : (ch - 'a' + 26); 
            
            if (!node->link[index]) {
                node->link[index] = new Node();
            }
            node = node->link[index];
        }
        node->flag = true;
    }

    void remove(string key) {
        if(!search(key))
        return;
        Node* node = root;
        int n = key.size();

        // Traverse to the node corresponding to the key
        for (int i = 0; i < n; i++) {
            char ch = key[i];
            int index = isupper(ch) ? (ch - 'A') : (ch - 'a' + 26);
            node = node->link[index];
        }
        // Mark the last node as not a word
        node->flag = false;
    }

    bool search(string key) {
        int n = key.size();
        Node* rootNode = root;

        for (int i = 0; i < n; i++) {
            char ch = key[i];
            int index = isupper(ch) ? (ch - 'A') : (ch - 'a' + 26); 
            
            if (!rootNode || !rootNode->link[index]) {
                return false;
            }
            rootNode = rootNode->link[index];
        }
        if (rootNode->flag)
        return true;
        return false;
    }
    // print all node  in trie tree
     void show(struct Node *rootNode,string s)
    {
        if(!rootNode)return;
        if(rootNode->flag)
        {
            cout<<s<<" ";
        }
        for(int i=0;i<52;i++)
        {
             if(rootNode->link[i])
            {
                char ch;
                i<26?ch='A':ch='a';
                ch=(char)(i%26+ch);
                show(rootNode->link[i],s+ch);                
            }
            
        }
    }
};



int main() {
vector<string> words = {"aba", "ababa", "abc", "abcd"};
Trie *t=new Trie();
Node *rootNode=t->getRoot();

for(auto i:words)
{
 t->insert(i);
}
t->remove("abc");
t->show(rootNode,"");
 
 
 

return 0;
}

