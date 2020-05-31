#define M 1000000007
const int maxN = 1e6+1;
int prime[maxN];
bool flag = true;

void SieveOfEratosthenes()
{
	prime[0] = 0;
	prime[1] = 0;
	int count = 0;
	for (int p = 2; p <= maxN; p++)
	{
		if (prime[p] == 0)
		{
			count++;
			prime[p] = count;
			for (int i = 2*p; i <= maxN; i += p)
				prime[i] = -1;
		}
		else{
			prime[p] = count;
		}
	}
	flag = false;
}

int power(int base, int exp)
{
	if (exp == 0)
		return 1;
	long long int ans = 1;
	while (exp > 1)
	{
		if (exp & 1)
		{
			exp--;
			ans = (ans * base) % M;
		}
		else
		{
			base = (base * base) % M;
			exp /= 2;
		}
	}
	ans = (ans * base) % M;
	return ans;
}

int Solution::solve(vector<int> &A)
{
	long long int ans = 0;
	if(flag)
		SieveOfEratosthenes();
	unordered_map<int, int> counts;
	for (int i = 0; i < A.size(); i++){
		if(A[i]!=0 && A[i]!=1)
			counts[prime[A[i]]]++;
	}
	long long int t;
	for (auto i : counts)
	{
	   // cout << ans << endl;
		t = (M + power(2, i.second) - 1) % M;
		ans = (ans + t) % M;
	}
	return ans;
}