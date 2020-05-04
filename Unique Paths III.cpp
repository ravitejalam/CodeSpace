void findPath(vector<vector<int> > &A,int &countOfZeros,int visitedSquares,int &ans,int x,int y){
    
    if(A[x][y]==2){
        if(countOfZeros+1==visitedSquares)
            ans++;
        return;
    }
    A[x][y]= -1;
    if(x-1>=0 and A[x-1][y]!=-1){
        visitedSquares++;
        findPath(A,countOfZeros,visitedSquares,ans,x-1,y);
        visitedSquares--;
    }
    if(x+1<A.size() and A[x+1][y]!=-1){
        visitedSquares++;
        findPath(A,countOfZeros,visitedSquares,ans,x+1,y);
        visitedSquares--;
    }
    if(y-1>=0 and A[x][y-1]!=-1){
        visitedSquares++;
        findPath(A,countOfZeros,visitedSquares,ans,x,y-1);
        visitedSquares--;
    }
    if(y+1<A[x].size() and A[x][y+1]!=-1){
        visitedSquares++;
        findPath(A,countOfZeros,visitedSquares,ans,x,y+1);
        visitedSquares--;
    }
    A[x][y]= 0;
}

int Solution::solve(vector<vector<int> > &A) {
    int countOfZeros = 0,visitedSquares = 0,ans = 0,x,y;
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A[i].size(); j++)
        {
            if(A[i][j] == 0)
                countOfZeros++;
            else if (A[i][j] == 1)
            {
                x=i;
                y=j;
            }
            
        }
        
    }
    findPath(A,countOfZeros,visitedSquares,ans,x,y);
    return ans;
}