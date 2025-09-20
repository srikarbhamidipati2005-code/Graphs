// Write your code here
#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'


vector<vector<int>>g;
vector<int>indeg;
vector<int>topo;
void kahn(){
	queue<int>q;
	for(int i=1;i<=n;i++){
		if(indeg[i]==0)q.push(i);
	}
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		topo.push_back(cur);
		for(auto v:g[cur]){
			indeg[v]--;
			if(indeg[v]==0){
				q.push(v);
			}
		}
	}
}
signed main() {
   int n,m;
    cin >> n >> m;

    g.resize(n + 1);
    indeg.assign(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        indeg[b]++;
    }

    kahn();

    if (topo.size() != n) {
        cout << "IMPOSSIBLE";
    } else {
        for (auto v : topo) {
            cout << v << " ";
        }
    }
}
