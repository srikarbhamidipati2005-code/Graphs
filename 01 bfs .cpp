#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> g;
int dis[100100];
int n,m;

 /*
	7 7
	1 2 1
	1 3 1
	1 4 1
	4 5 0
	4 6 1
	5 6 0
	6 7 1
	1
 */

void BFS01(int sc){
	for(int i=1;i<=n;i++){
		dis[i]=1e9;
	}

	dis[sc] = 0;

	deque<int> dq;
	dq.push_back(sc);

	while(!dq.empty()){
		int node = dq.front();
		dq.pop_front();
		for(auto v:g[node]){
			int neigh = v.first;
			int weigh = v.second;
			if(dis[neigh] > dis[node]+weigh){
				dis[neigh] = dis[node]+weigh;
				if(weigh == 0){
					dq.push_front(neigh);
				} else {
					dq.push_back(neigh);
				}
			}
		}
	}
}

void solve(){

	cin>>n>>m;
	g.resize(n+1);

	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		g[a].push_back({b,c});
		g[b].push_back({a,c});
	}

	int sc; // source
	cin>>sc;

	BFS01(sc);
	
	
	for(int i=1;i<=n;i++){
		cout<<"\nDistance "<<i<<" : "<<dis[i];
	}
}
	

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// int _t;cin>>_t;while(_t--)
	solve();
	
}
