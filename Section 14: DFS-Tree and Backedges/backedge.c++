#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;

vector<int> gr[N];
int vis[N];
bool cycle = false;

void dfs(int cur, int par) {
	// visited and in call stack
	vis[cur] = 1;
	for (auto x : gr[cur]) {

        if (vis[x] == 1) {
			// backedge
			cycle = true;
		}
		else if (vis[x] == 0) {
			dfs(x, cur);
		}
		
	}
	// visited and not in call stack
	vis[cur] = 2;
	return;
}

int main()
{
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		// gr[y].push_back(x);
	}

	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0) {
			dfs(i, 0);
		}
	}

	if (cycle) {
		cout << "Yes cycle found";
	}
	else {
		cout << "Not found";
	}


	return 0;
}