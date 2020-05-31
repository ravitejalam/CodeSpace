struct Trie
{
    struct Trie *children[26];
    bool isEnd;
    int childNodes;
    Trie()
    {
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
        isEnd = false;
        childNodes = 0;
    }
};

void insert(Trie *root, string word)
{
    for (int i = 0; i < word.size(); i++)
    {
        if (root->children[word[i] - 'a'] == NULL)
        {
            root->children[word[i] - 'a'] = new Trie;
        }
        root->childNodes++;
        root = root->children[word[i] - 'a'];
    }
    root->isEnd = true;
}

char search(Trie *root, string word, int index, int swapsLeft)
{
    if (swapsLeft < 0)
        return '0';
    if (root->isEnd && swapsLeft == 0 && index == word.size())
    {
        return '1';
    }
    for (int j = 0; j < 26; j++)
    {
        if (root->children[j] != NULL)
        {
            if (word[index] - 'a' == j)
            {
                if (search(root->children[j], word, index + 1, swapsLeft) == '1')
                {
                    return '1';
                }
            }
            else
            {
                if (search(root->children[j], word, index + 1, swapsLeft - 1) == '1')
                {
                    return '1';
                }
            }
        }
    }
    return '0';
}

string Solution::solve(vector<string> &A, vector<string> &B)
{
    Trie *root = new Trie();
    for (int i = 0; i < A.size(); i++)
        insert(root, A[i]);
    string ans = "";
    for (int i = 0; i < B.size(); i++)
        ans += search(root, B[i], 0, 1);
    return ans;
}