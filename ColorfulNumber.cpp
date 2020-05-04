int Solution::colorful(int A) {
    unordered_set<int> s;
    vector<int> B = {};
    while(A>0){
        B.push_back(A%10);
        A/=10;
    }
    for(int i = 0;i<B.size();i++){
        int product = 1;
        for(int j = i ; j<B.size();j++){
            product*=B[j];
            if(s.find(product) != s.end())
                return 0;
            s.insert(product);
        }
    }
    return 1;
}
