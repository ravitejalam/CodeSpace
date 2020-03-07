#include <bits/stdc++.h>

using namespace std;

int maximumGap(const vector<int> &A)
{
    int s = A.size();
    int maxi = *max_element(A.begin(),A.end());
    int mini = *min_element(A.begin(),A.end());
    
    vector<int> num_line(maxi, 0);
    vector<vector<int>> min_max;
    for (int i = 0; i < s; i++)
        num_line[A[i]] = 1;
    int x = (maxi - mini) / (s - 1);
    for (int i = 0; i < s - 1; i++)
    {
        int max_t, min_t;
        bool flag = false;
        for (int j = x * i; j < x * (i + 1); j++)
        {
            if (num_line[j] == 1)
            {
                min_t = num_line[j];
                flag = true;
            }
        }
        for (int j = x * (i + 1) >= s ? s : x * (i + 1); j >= x * i; j--)
        {
            if (num_line[j] == 1)
            {
                max_t = num_line[j];
                flag = true;
            }
        }
        if (flag){
            vector<int> tmp {min_t, max_t};
            cout<< tmp[0]<<tmp[1]<<endl;
            min_max.push_back(tmp);
        }
    }
    int max_diff = INT_MIN;

    for(int i =1; i<min_max.size();i++){
        max_diff = max(min_max[i][0] - min_max[i-1][1],max_diff);
    }
    return max_diff;
}

int main()
{
    vector<int> A = {1, 4, 7, 10, 3, 5};
    cout << maximumGap(A);
    return 0;
}
