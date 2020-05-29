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

void percolateDown(int heap[], int index)
{
	if (index > 1)
		return;
	if (heap[index] > heap[2 * index] || heap[index] > heap[2 * index + 1])
	{
		if (heap[2 * index] <= heap[2 * index + 1])
		{
			swap(heap[index], heap[2 * index]);
			percolateDown(heap, 2 * index);
		}
		else
		{
			swap(heap[index], heap[2 * index + 1]);
			percolateDown(heap, 2 * index + 1);
		}
	}
}

void insert(int heap[], int num, int size)
{
	heap[size+1] = num;
	percolateUp(heap, size+1);
}

int product(int heap[])
{
	return heap[1] * heap[2] * heap[3];
}

void removeMin(int heap[])
{
	swap(heap[1], heap[4]);
	heap[4] = -1;
	percolateDown(heap, 1);
}

vector<int> Solution::solve(vector<int> &A)
{
	vector<int> ans(A.size(), -1);
	int heap[5];
	for (int i = 0; i < 5; i++)
	{
		heap[i] = INT_MAX;
	}
	if (A.size() < 3)
		return ans;
	insert(heap, A[0] ,0);
	insert(heap, A[1] ,1);
	insert(heap, A[2] ,2);
	ans[2] = product(heap);
	for (int i = 3; i < A.size(); i++)
	{
		if (A[i] > heap[1])
		{
			insert(heap, A[i], 3);
			removeMin(heap);
		}
		ans[i] = product(heap);
	}
	return ans;
}