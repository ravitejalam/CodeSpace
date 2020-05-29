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

void percolateDown(int heap[], int index,int size)
{
    if(index>size)
        return;
    bool left = (2*index <= size && heap[index] > heap[2 * index]);
    bool right = (2 * index + 1 <= size && heap[index] > heap[2 * index + 1]);
	if (left || right)
	{
        if(left && right){
            if (heap[2 * index] <= heap[2 * index + 1])
            {
                swap(heap[index], heap[2 * index]);
                percolateDown(heap, 2 * index,size);
            }
            else
            {
                swap(heap[index], heap[2 * index + 1]);
                percolateDown(heap, 2 * index + 1,size);
            }
        }
        else if(left)
        {
            swap(heap[index], heap[2 * index]);
            percolateDown(heap, 2 * index,size);
        }
        else
        {
            swap(heap[index], heap[2 * index + 1]);
            percolateDown(heap, 2 * index + 1,size);
        }
        
        
	}
}

void insert(int heap[], int num, int &size)
{
	heap[size+1] = num;
    size++;
	percolateUp(heap, size);

}

void removeMin(int heap[],int &size)
{
	swap(heap[1], heap[size]);
	heap[size] = -1;
    size--;
	percolateDown(heap, 1,size);
}

int getMin(int heap[]){
    return heap[1];
}


int Solution::solve(vector<int> &A) {
    int heap[A.size()+1];
    int size = 0;
    for (int i = 0; i < A.size(); i++)
        insert(heap,A[i],size);
    int cost = 0;
    while (size>1)
    {
        int a = getMin(heap);
        removeMin(heap,size);
        int b = getMin(heap);
        removeMin(heap,size);
        cost += (a+b);
        insert(heap,a+b,size);
    }
    return cost;
}