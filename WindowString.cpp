bool compare(unordered_map<char,int> &A,unordered_map<char,int> &B){
    if(A.size()==0)
        return false;
    for (auto i : B){
        if(i.second > A[i.first])
            return false;
    }
    return true;    
}

bool compareOneChar(unordered_map<char,int> &A,unordered_map<char,int> &B,char c){
    if(B[c] > A[c])
        return false;
    return true;
}

string Solution::minWindow(string A, string B) {
    unordered_map<char,int> bCount;
    for (int i = 0; i < B.size(); i++)
    {
        bCount[B[i]]++;
    }
    unordered_map<char,int> aCount;
    int left =0;
    int right =0;
    int ansLen = INT_MAX;
    string ans = "";
    int start=-1;
    while (right<A.size())
    {
        aCount[A[right]]++;
        if(compare(aCount,bCount)){
            do
            {
                if(ansLen>right-left+1){
                    ansLen = right-left+1;
                    start=left;
                }
                aCount[A[left]]--;
                left++;
            } while (left<=right && compareOneChar(aCount,bCount,A[left-1]));
        }
        right++;
    }
    if(start==-1)
        return "";
    ans = A.substr(start,ansLen);
    return ans;
}