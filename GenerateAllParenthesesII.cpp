#include <bits/stdc++.h>

using namespace std;

void updateAns(int &pairs, int index, int &status, string &currentAns, vector<string> &ans)
{
    if (index == 2 * pairs)
    {
        if (status == 0)
            ans.push_back(currentAns);
        return;
    }
    status++;
    currentAns.push_back('(');
    updateAns(pairs,index+1,status,currentAns,ans);
    currentAns.pop_back();
    status--;
    if(status>0){
        status--;
        currentAns.push_back(')');
        updateAns(pairs,index+1,status,currentAns,ans);
        currentAns.pop_back();
        status++;
    }
}

vector<string> generateParenthesis(int A)
{
    vector<string> ans;
    int status = 0;
    string currentAns = "";
    updateAns(A, 0, status, currentAns, ans);
    return ans;
}