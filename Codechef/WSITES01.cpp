#include <bits/stdc++.h>
using namespace std;


#define ALPHABET_SIZE (26)

#define C2I(c) ((int)c - (int)'a')
string s[200000];
int cnt=0;
typedef struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    bool isLeaf;
}TRIE;
TRIE *getNode(void) {
    TRIE *cnode = NULL;

    cnode = (TRIE *)malloc(sizeof(TRIE));
    if (cnode) {
        int i;
        cnode->isLeaf = false;
        //printf("YesNo\n");
        for (i = 0; i < ALPHABET_SIZE; i++)
            cnode->children[i] = NULL;
    }
    return cnode;
}
void insert(TRIE *root, string key) {
    int level, index, len;
    len = key.length();
    TRIE *cnode = root; 
    for (level = 0; level < len; level++) {
        index = C2I(key[level]);
         if (!cnode->children[index])
        {
            cnode->children[index] = getNode();
        }
        cnode = cnode->children[index];
    }
    
    cnode->isLeaf = true;
}

void traverse(TRIE *rootm, TRIE *rootp, string &prefix) {
 
  for (int index = 0; index < ALPHABET_SIZE; ++index) {
    
    TRIE *pChild = rootm->children[index];
    if (pChild) {
        prefix+=(char)('a'+index);
        if (rootp->children[index]){
            if (pChild->isLeaf)
            {
                cout<<-1<<endl;
                exit(0);
            }
            traverse(pChild,rootp->children[index],prefix);
        }
        else{
            s[cnt++]=prefix;
        }
        prefix.pop_back();
      
    }
  }
}

int main()
{
    int t;
    char c;
    string str,prefix="";
    cin>>t;
    TRIE *rootm=getNode();
    TRIE *rootp=getNode();
    while(t--){
        cin>>c>>str;
        if (c=='+')
            insert(rootp,str);
        else
            insert(rootm,str);

    }
    traverse(rootm,rootp,prefix);
    cout<<cnt<<endl;
    for (int i = 0; i < cnt; ++i)
    {
        cout<<s[i]<<endl;
    }
    return 0;
}