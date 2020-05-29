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

int sum(int heap[], int size)
{
    int ans = 0;
    for (int i = 1; i < size + 1; i++)
    {
        ans += heap[i];
    }
    return ans;
}

int Solution::solve(vector<int> &A, int B) {
    int heap[A.size()+1];
    int size = 0;
    for (int i = 0; i < A.size(); i++)
    {
        insert(heap,A[i],size);
    }
    int ans = 0;
    while (size>0 && getMin(heap) <=B)
    {
        int mini = getMin(heap);
        ans += mini/2;
        removeMin(heap,size);
        if(size>0){
            int nextMini = getMin(heap);
            removeMin(heap,size);
            nextMini += mini - mini/2;
            insert(heap,nextMini,size);
        }
    }
    return ans;
}