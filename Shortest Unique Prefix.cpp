struct Node
{
    struct Node *children[26] = {NULL};
    int childNodes = 0;
    bool isEndOfWord = false;
    Node(){
        for (auto i = 0; i<26; ++i)
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
}

string getUniquePrefix(Node *root, string word){
    string prefix = "";
    for (int i = 0; i < word.size(); i++)
    {
        if(root->childNodes == 1)
            break;
            prefix += word[i];
        root = root->children[word[i]-'a'];
    }
    return prefix;
}

vector<string> Solution::prefix(vector<string> &A)
{
    Node *root = new Node();
    vector<string> ans = {};
    for (int i = 0; i < A.size(); i++)
    {
        insert(root, A[i]);
    }
    for (int i = 0; i < A.size(); i++)
    {
        ans.push_back(getUniquePrefix(root,A[i]));
    }
    return ans;
}