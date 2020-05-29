void percolateUp(int heap[], int index)
{
    if (index <= 1)
        return;
    if (heap[index / 2] > heap[index])
    {
        swap(heap[index / 2], heap[index]);
        percolateUp(heap, index / 2);
    }
    return;
}

void percolateDown(int heap[], int index, int size)
{
    if (index > size)
        return;
    bool left = (2 * index <= size && heap[index] > heap[2 * index]);
    bool right = (2 * index + 1 <= size && heap[index] > heap[2 * index + 1]);
    if (left || right)
    {
        if (left && right)
        {
            if (heap[2 * index] <= heap[2 * index + 1])
            {
                swap(heap[index], heap[2 * index]);
                percolateDown(heap, 2 * index, size);
            }
            else
            {
                swap(heap[index], heap[2 * index + 1]);
                percolateDown(heap, 2 * index + 1, size);
            }
        }
        else if (left)
        {
            swap(heap[index], heap[2 * index]);
            percolateDown(heap, 2 * index, size);
        }
        else
        {
            swap(heap[index], heap[2 * index + 1]);
            percolateDown(heap, 2 * index + 1, size);
        }
    }
}

void insert(int heap[], int num, int &size)
{
    heap[size + 1] = num;
    size++;
    percolateUp(heap, size);
}

void removeMin(int heap[], int &size)
{
    swap(heap[1], heap[size]);
    heap[size] = -1;
    size--;
    percolateDown(heap, 1, size);
}

int getMin(int heap[])
{
    return heap[1];
}

int Solution::solve(vector<vector<int> > &A, int B) {
    int heap[A.size()*A[0].size()+1];
    int size = 0;
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A[0].size(); j++)
        {
            insert(heap,A[i][j],size);
        }
    }
    int ans =0;
    for (int i = 0; i < B; i++)
    {
        ans = getMin(heap);
        removeMin(heap,size);
    }
    return ans;
}