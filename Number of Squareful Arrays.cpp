void swap(vector<int> &A,int i,int j){
    int tmp = A[i];
    A[i]=A[j];
    A[j]=tmp;
}

bool isPerfectSquare(long double x) 
{   
  // Find floating point value of  
  // square root of x. 
  long double sr = sqrt(x); 
  
  // If square root is an integer 
  return ((sr - floor(sr)) == 0); 
} 

bool check(vector<int> &A, int i, int j){
    if(isPerfectSquare(A[i]+A[j])){
        return true;
    }
    return false;
}

void allPermutations(vector<int> &A,int index,int &count){
    if(!check(A,index-1,index-2) and index>1){
        return;
    }
    if(index==A.size()){
        count++;
        return;
    }
    set<int> alreadyCovered = {};
    for (int i = index; i < A.size(); i++)
    {
        if(find(alreadyCovered.begin(), alreadyCovered.end(), A[i]) == alreadyCovered.end()){
            swap(A,i,index);
            allPermutations(A,index+1,count);
            swap(A,i,index);
            alreadyCovered.insert(A[i]);
        }
    }
    
}

int Solution::solve(vector<int> &A) {
    if(A.size()<2)
        return 0;
    int count = 0;
    allPermutations(A,0,count);
    return count;
}