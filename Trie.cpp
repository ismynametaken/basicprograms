#include <iostream>
#include <map>
using namespace std;

#define NUMBEROFALPHA 26
typedef struct TrieNode TrieNode;
 
struct TrieNode
{
    bool isEndOfWord;
    map<char, TrieNode*> tree;
    TrieNode(void) {isEndOfWord = false;}
};


class Trie
{
    public:
        Trie();
        void insert(string word);
        bool remove(string word);
        bool find(string word, bool isWholeWord);

    private:
        TrieNode* root; 
        bool remove_helper(TrieNode*, string, int, bool*);
};

Trie::Trie(void)
{
    root = new TrieNode;
}

void Trie::insert(string word)
{
    TrieNode* current = root;

    for(char ch: word)
    {
        if(current->tree[ch]==NULL)
        {
            TrieNode *newnode = new TrieNode;
            current->tree[ch] = newnode;   
        }
        current = current->tree[ch];
    }
    current->isEndOfWord = true;
    return;
}

 
bool Trie::find(string word, bool isendofword)
{
    TrieNode* current = root;

    for(char ch: word)
    {
        if(!current->tree.count(ch))
        {
            return(false); 
        }
        current = current->tree[ch];
    }
    if(isendofword)
        return(current->isEndOfWord == true);
    return true;
}

bool Trie::remove(string word)
{
    bool found =true;
    remove_helper(root, word, 0, &found);
    return (found);
}

bool Trie::remove_helper(TrieNode* current, string word, int index, bool *found)
{
    if(index == (word.length()))
    {
        if(current->isEndOfWord)
        {
            current->isEndOfWord = false;
            if(current->tree.size()==0) //Link can be deleted in the parent
                return(true);
        }
        else
        {
            *found = false; //Word found, but its a prefix, not a whole word
        }
        
        return(false);
    }

    if(!current->tree.count(word[index]))
    {
        *found = false;
        return false;
    }
    bool canNodebedeleted = remove_helper(current->tree[word[index]], word, index+1, found);

    if(*found == false) //
    {
        return false;
    }

    if(canNodebedeleted)
    {
        delete current->tree[word[index]];
        current->tree.erase(word[index]);
        if(current->tree.size() ==0)
            return true;
    }

    return false;

}
int main(void)
{
    Trie trie;
    trie.insert("a");
    trie.insert("abc");
    trie.insert("hello");
    trie.insert("hell");
    cout << "There-prefix: " << boolalpha << trie.find("there", false) << endl;
    cout << "hel-full: " << trie.find("hel", true) << endl;
    cout << "hel-prefix: " << trie.find("hel", false) << endl;
    cout << "abc-full: " << trie.find("abc", true) << endl;
    cout << "a: " << trie.remove("a") << endl ;
    cout << "ab: " << trie.remove("ab") << endl ;
    cout << "abc: " << trie.remove("abc") << endl ;
    cout << "hell: " << trie.remove("hell") << endl ;
    cout << "hello: " << trie.remove("hello") << endl ;
    exit(0);
}
