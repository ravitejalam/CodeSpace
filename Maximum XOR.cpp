struct Node
{
	Node *zero;
	Node *one;
	Node() : zero(NULL), one(NULL) {}
};

void insert(Node *root, int &e)
{
	for (int i = 30; i >= 0; i--)
	{
		if (e & (1 << i))
		{
			if (root->one == NULL)
				root->one = new Node();
			root = root->one;
		}
		else{
			if (root->zero == NULL)
				root->zero = new Node();
			root = root->zero;
		}
	}
	// delete root;
	// root = NULL;
}

void updateMax(Node *root, int &e, int &ans)
{
	int XOR = 0;
	for (int i = 30; i >= 0; i--)
	{
		if (e & (1 << i)){
			if(root->zero != NULL){
				root = root->zero;
				XOR |= (1 << i);
			}
			else{
				root = root->one;
			}
		}
		else{
			if(root->one != NULL){
				root = root->one;
				XOR |= (1 << i);
			}
			else{
				root=root->zero;
			}
		}
	}
	ans = max(ans,XOR);
// 	delete root;
// 	root = NULL;
}

int Solution::solve(vector<int> &A)
{
	int ans = INT_MIN;
	Node *root = new Node();
	for (int i = 0; i < A.size(); i++)
		insert(root, A[i]);
	for (int i = 0; i < A.size(); i++)
		updateMax(root, A[i], ans);
	return ans;
}