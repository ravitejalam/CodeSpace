void getCombinations(string &A,vector<string> &ans,int index,string current){
    if(index==A.size()){
        ans.push_back(current);
        return;
    }
    switch (A[index])
    {
    case '0':
        getCombinations(A,ans,index+1,current+"0");
        break;
    case '1':
        getCombinations(A,ans,index+1,current+"1");
        break;
    case '2':
        getCombinations(A,ans,index+1,current+"a");
        getCombinations(A,ans,index+1,current+"b");
        getCombinations(A,ans,index+1,current+"c");
        break;
    case '3':
        getCombinations(A,ans,index+1,current+"d");
        getCombinations(A,ans,index+1,current+"e");
        getCombinations(A,ans,index+1,current+"f");        
        break;
    case '4':
        getCombinations(A,ans,index+1,current+"g");
        getCombinations(A,ans,index+1,current+"h");
        getCombinations(A,ans,index+1,current+"i");
        break;
    case '5':
        getCombinations(A,ans,index+1,current+"j");
        getCombinations(A,ans,index+1,current+"k");
        getCombinations(A,ans,index+1,current+"l");
        break;
    case '6':
        getCombinations(A,ans,index+1,current+"m");
        getCombinations(A,ans,index+1,current+"n");
        getCombinations(A,ans,index+1,current+"o");
        break;
    case '7':
        getCombinations(A,ans,index+1,current+"p");
        getCombinations(A,ans,index+1,current+"q");
        getCombinations(A,ans,index+1,current+"r");
        getCombinations(A,ans,index+1,current+"s");
        break;
    case '8':
        getCombinations(A,ans,index+1,current+"t");
        getCombinations(A,ans,index+1,current+"u");
        getCombinations(A,ans,index+1,current+"v");
        break;
    case '9':
        getCombinations(A,ans,index+1,current+"w");
        getCombinations(A,ans,index+1,current+"x");
        getCombinations(A,ans,index+1,current+"y");
        getCombinations(A,ans,index+1,current+"z");
        break;
    default:
        break;
    }
}


vector<string> Solution::letterCombinations(string A) {
    vector<string> ans;
    getCombinations(A,ans,0,"");
    return ans;
}