#include <bits/stdc++.h>

using namespace std;

struct TrieNode {
    map<char, TrieNode*> mp;
    bool isEnd;
};

void insert(TrieNode* node, string s) {
    
    int l = s.length();
    TrieNode* initialNode = node;
    for(int i = 0; i < l; i++) {
        map<char, TrieNode*> &mp = node->mp;
        if(mp.find(s[i]) == mp.end()) {
            TrieNode *newTrieNode = new TrieNode();
            mp[s[i]] = newTrieNode;
        }
        node = mp[s[i]];
    }
    node->isEnd = true;
}

void traverse(TrieNode *node, string s) {

    if(node->isEnd == true)
        cout << s << endl;

    if(node->mp.size() == 0) {
        return;
    }
    

    map<char, TrieNode*> &mp = node->mp;
    for(auto x: mp) {
        traverse(x.second, s+x.first);
    }
}

void delete_(TrieNode* node, string s, int index) {

    int l = s.length();
    map<char, TrieNode*> &mp = node->mp;
    if(index == l-1) {
        
        TrieNode *nextNode = mp[s[index]];
        if(nextNode->mp.size() == 0) {
            delete nextNode;    
            mp.erase(mp.find(s[index]));
        }
        else {
            nextNode->isEnd = false;
        }
    }
    else {
        
        delete_(mp[s[index]], s, index+1);
    }
}


int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    TrieNode *node = new TrieNode();
    TrieNode *initialNode = node;
    insert(node, "10001");
    insert(node, "1100");
    insert(node, "1110");
    insert(node, "010");
    insert(node, "1111");
    insert(node, "11");
    
    traverse(node, "");

    // cout << "Calling delete function" << endl;
    delete_(node, "1100", 0);
    delete_(node, "11", 0);
    cout << "After deletion " << endl;
    traverse(node, "");


    return 0;
}