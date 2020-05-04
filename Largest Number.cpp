bool com(string a, string b){
    return (a+b)>(b+a);
}

string Solution::largestNumber(const vector<int> &A) {
    vector<string> B(A.size());
    for (int i = 0; i < A.size(); i++)
        B[i]=to_string(A[i]);
    sort(B.begin(),B.end(),com);
    string number = "";
    for (int i = 0; i < B.size(); i++)
        number.append(B[i]);
    if(number[0]=='0')
        return "0";
    return number;
}