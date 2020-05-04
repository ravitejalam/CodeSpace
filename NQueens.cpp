void NQueens(vector<string> &Matrix, int row,vector<vector<string> > &ans,vector<bool> &COL,vector<bool> &DownDIAG,vector<bool> &UpDIAG){
    if(row == Matrix.size()){
        ans.push_back(Matrix);
        return;
    }
    for (int i = 0; i < Matrix.size(); i++)
    {
        if(!COL[i] and !DownDIAG[i-row+Matrix.size()] and !UpDIAG[i+row]){
            Matrix[row][i] = 'Q';
            COL[i] = true;
            DownDIAG[i-row+Matrix.size()] = true;
            UpDIAG[i+row] = true;
            NQueens(Matrix,row+1,ans,COL,DownDIAG,UpDIAG);
            UpDIAG[i+row] = false;
            DownDIAG[i-row+Matrix.size()] = false;
            COL[i] = false;
            Matrix[row][i] = '.';
        }
    }
    
}

vector<vector<string> > Solution::solveNQueens(int A) {
    vector<vector<string>> ans = {};
    vector<string> Matrix;
    string s(A, '.');
    vector<bool> COL(A,false),DownDIAG(2*A,false),UpDIAG(2*A,false);
    for (int i = 0; i < A; i++)
        Matrix.push_back(s);
    NQueens(Matrix,0,ans,COL,DownDIAG,UpDIAG);
    return ans;
}