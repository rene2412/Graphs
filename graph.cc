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
	if (u < 0 or u >= vertex or v < 0 or v >= vertex) {
		cout << u << ":" << v << endl;
		cout << "Invalid indices" << endl;
		return;
	}
	if (u >= adjList.size()) {
		adjList.resize(u + 1);
	}
	if (v >= adjList.size()) {
		adjList.resize(v + 1);
	}
//a node will be inserted into adjList, and will have a pair of its neighbor and its distance from it
//will add edges and its weight bidirectional
	adjList[u].push_back(make_pair(v, weight));
	adjList[v].push_back(make_pair(u, weight));
}

void dikjstras(int source) {
//the distance vector that is initalized to the size of the vertexs
vector<int> dist(vertex, INT_MAX);
vector<int> pred(vertex, -1);
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
//if the neighbors node distance is less than the current nodes distance and distance
//then update the new distance
if (dist[v] > dist[u] + weight) {
	dist[v] = dist[u] + weight;
	pred[v] = u;
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
else cout << "Distance: " << dist[i] << " | Predecessor: " << pred[i] << endl;
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
Graph g(6);
g.addEdge(1,4,5);
g.addEdge(1,2,2);
g.addEdge(2,4,5);
g.addEdge(2,3,14);
g.addEdge(2,5,4);
g.addEdge(3,5,34);
g.addEdge(4,5,58);
//g.printGraph();
g.dikjstras(1);
}
