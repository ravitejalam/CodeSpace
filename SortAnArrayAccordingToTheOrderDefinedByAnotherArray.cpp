map<long long int,int> com;

 

bool comp(int a,int b){

    return com[a] < com[b];

}

 

vector<int> Solution::solve(vector<int> &A, vector<int> &B) {

    com.clear();

    vector<int> InB ={};

    vector<int> NotB={};

    unordered_set<int> sB = {};

    for (int i = 0; i < B.size(); i++)

    {

        sB.insert(B[i]);

        com[B[i]]=i;

    }

    for (int i = 0; i < A.size(); i++)

    {

        if(sB.find(A[i]) == sB.end()){

            NotB.push_back(A[i]);

        }

        else

        {

            InB.push_back(A[i]);

        }

    }

    

    sort(NotB.begin(),NotB.end());

    sort(InB.begin(),InB.end(),comp);

    InB.insert( InB.end(), NotB.begin(), NotB.end() );

    for(int i = 0; i < A.size(); i++)

    {

        A[i]=InB[i];

    }

    return A;

}