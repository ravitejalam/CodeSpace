struct Node
{
    struct Node *children[26] = {NULL};
    int childNodes = 0;
    bool isEndOfWord = false;
    Node()
    {
        for (auto i = 0; i < 26; ++i)
            children[i] = NULL;
    }
};

void insert(Node *root, string word)
{
    for (int letter = 0; letter < word.size(); letter++)
    {
        if (root->children[word[letter] - 'a'] == NULL)
        {
            root->children[word[letter] - 'a'] = new Node();
        }
        root->childNodes++;
        root = root->children[word[letter] - 'a'];
    }
    root->isEndOfWord = true;
    root->childNodes++;

}

int getCount(Node *root, string prefix)
{
    for (int i = 0; i < prefix.size(); i++)
    {
        if (root->children[prefix[i] - 'a'] != NULL)
        {
            root = root->children[prefix[i] - 'a'];
        }
        else
        {
            return 0;
        }
    }
    return root->childNodes;
}

vector<int> Solution::solve(vector<string> &A, vector<string> &B)
{
    vector<string> prePostSame = {};
    int M = B[0].size();
    for (int i = 0; i < A.size(); i++)
    {
        int W = A[i].size();
        bool flag = true;
        if (W < M)
            continue;
        for (int j = 0; j < M; j++)
        {
            if (A[i][j] != A[i][W - M + j])
            {
                flag = false;
                break;
            }
        }
        if (flag)
            prePostSame.push_back(A[i]);
    }
    Node *root = new Node();
    for (int i = 0; i < prePostSame.size(); i++)
    {
        insert(root, prePostSame[i]);
    }
    vector<int> ans = {};
    for (int i = 0; i < B.size(); i++)
    {
        ans.push_back(getCount(root, B[i]));
    }
    return ans;
}