#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Graph {
private:
int vertex;
vector<vector<pair<int, int>>> adjList;
public:
Graph(int v) : vertex(v) {
	adjList.resize(vertex);
}

void addEdge(int u, int v, int weight) {
	adjList[u].push_back(make_pair(v, weight));
	adjList[v].push_back(make_pair(u, weight));
}

void removeEdge(int u, int v) {
for (auto iter = adjList[u].begin(); iter != adjList[u].end(); iter++) {
	if (iter->first == v) {
		adjList[u].erase(iter);
		break;
	}
	if (iter == adjList[u].end()) {
	cout << "Connection Not Valid" << endl; break;
	}
}

for (auto iter = adjList[v].begin(); iter != adjList[v].end(); iter++) {
	if (iter->first == u) {
		adjList[v].erase(iter);
		break;
	}
	if (iter == adjList[v].end()) {
	cout << "Connection Not Valid" << endl; break;
	}
   }
}

void retrieveEdge(int u, int v) {
for (auto iter = adjList[u].begin(); iter != adjList[u].end(); iter++) {
	if (iter->first == v) {
		//todo
		cout << "Weight of edge: "
		break;
	}
	if (iter == adjList[u].end()) {
	cout << "Edge Not Valid" << endl; break;
	}

  }
}
void BFS(int source) {
if (source < 0 or source > vertex) {
	cout << "Error: Node not in list" << endl;
	return;
}
queue<int> q; 
vector<bool> visited(vertex, false);
visited[source] = true;
q.push(source);
while (!q.empty()) {
int process = q.front();
q.pop();
cout << "Node: " << process << endl;
   for (const auto& neighbor : adjList[process]) {
	int adj_neighbor =  neighbor.first;
	if (!visited[adj_neighbor]) {
		visited[adj_neighbor] = true;
		q.push(adj_neighbor);
	}
     }
  }
}
//for later
void dikjstras(int source) {
vector<int> dist(vertex, INT_MAX);
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//initalize the source distance to 0 
dist[source] = 0;
//push the source node
pq.push(make_pair(0, source));

while (!pq.empty()) {
int u = pq.top().second;
pq.pop();
//for every neighbor of that source node (should already be in the adjenceny list)
for (auto& neighbor : adjList[u]) {
int v = neighbor.first;
int weight = neighbor.second;
if (dist[v] > dist[u] + weight) {
	dist[v] = dist[u] + weight;
	pq.push(make_pair(dist[v], v));
	}
   }
 }

cout << "Shortest Distance from vertex " << source << " to all other vertices:" << endl;
for (int i = 0; i < vertex; i++) {
cout << "Vertex " << i << ": ";
if (dist[i] == INT_MAX) {
cout << "N/A" << endl;
   }
else cout << dist[i] << endl;
 }
}


void printGraph() {
for (int i = 0; i < vertex; i++) { 
	for (auto &neighbor : adjList[i]) {
	cout << "Vertex " << i << " is connected to: ";
	cout << " " << neighbor.first << ", Weight: " << neighbor.second << endl; 
	}
	cout << endl;
    }
 }

};

int main() {
Graph g(5);
//cout << "Before Delete: " << endl;
g.addEdge(0,1, 10);
g.addEdge(0,3, 5);
g.addEdge(1,2, 3);
g.addEdge(2,3, 8);
g.BFS(0);
g.printGraph();
//g.dikjstras(0);
//cout << "After Delete: " << endl;
//er Delete: " << endl;
//g.removeEdge(0,4);
//g.removeEdge(1,3);
//g.printGraph();
}
