#include <bits/stdc++.h>

using namespace std;

int incrementCount(vector<int> &A,int element,int start,int end){
    int mid;
    int Ostart = start;
    int ans = -1;
    while(start<=end)
    {
        mid = start + (end-start)/2;
        if (element > 2*A[mid])
        {
            ans = mid;
            start = mid+1;
        }
        else
        {
            end =mid-1;
        }
    }
    if(ans==-1)
        return 0;
    return ans-Ostart+1;
}

void mergeSort(vector<int> &A,vector<int> &tmp,int start,int end,int &count){
    if(start==end)
        return;
    int mid = start + (end-start)/2;
    mergeSort(A,tmp,start,mid,count);
    mergeSort(A,tmp,mid+1,end,count);
    int left_start = start;
    int right_start = mid+1;
    for (int i = start; i <= end; i++){
        if(left_start==mid+1){
            tmp[i]=A[right_start];
            right_start++;
        }
        else if (right_start==end+1){
            count+=incrementCount(A,A[left_start],mid+1,end);
            tmp[i]=A[left_start];
            left_start++;
        }
        else{
            if (A[left_start]>A[right_start]){
                tmp[i]=A[right_start];
                right_start++;
            }
            else{
                count+=incrementCount(A,A[left_start],mid+1,end);
                tmp[i]=A[left_start];
                left_start++;
            }
        }
    }
    for (int i = start; i <= end; i++){
        A[i]=tmp[i];
    }
}

void updateCount(vector<int> &A,vector<int> &tmp,int &count){
    mergeSort(A,tmp,0,A.size()-1,count);
}

int solve(vector<int> &A) {
    int count = 0;
    vector<int> tmp(A.size());
    for (int i = 0; i < A.size(); i++)
    {
        tmp[i]=A[i];
    }
    updateCount(A,tmp,count);
    return count;
}