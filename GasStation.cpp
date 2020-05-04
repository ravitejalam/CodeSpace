int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B)
{
    int start = 0;  
    int end = 1;  
  
    int curr_petrol = A[start] - B[start];
    while (end != start || curr_petrol < 0)  
    {
        while (curr_petrol < 0 && start != end)  
        {
            curr_petrol -= A[start] - B[start];  
            start = (start + 1) % A.size();
            if (start == 0)  
                return -1;  
        }
        curr_petrol += A[end] - B[end];  
  
        end = (end + 1) % A.size();  
    }  
    return start; 
}