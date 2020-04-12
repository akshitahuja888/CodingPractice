  
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <stack>
#include <iomanip>
#include <set>
#include <map>

using namespace std;


template<typename T>
class Graph{

	unordered_map<T, list<T> > adjList;

public:

	void addEdge(T u,T v,bool biDirection=true)
	{
		adjList[u].push_back(v);
		if(biDirection)
		{
			adjList[v].push_back(u);
		}
	}

	void display()
	{
		for(auto node:adjList)
		{
			cout<<node.first<<" -> ";
			for(auto neighbour:node.second)
			{
				cout<<neighbour<<" , ";
			}
			cout<<endl;
		}
	}

	void bfs(T source)
	{
		queue<T> q;
		unordered_map<T,bool> visited;

		q.push(source);
		visited[source]=true;

		while(!q.empty())
		{
			T node=q.front();
			q.pop();

			cout<<node<<" ";

			for(auto neighbour:adjList[node])
			{
				if(!visited[neighbour])
				{
					q.push(neighbour);
					visited[neighbour]=true;
				}
			}
		}
			cout<<endl;
	}
	void dfsHelper(T node,unordered_map<T,bool> &visited)
	{
		cout<<node<<" ";
		visited[node]=true;

		for(auto neighbour:adjList[node])
		{
			if(!visited[neighbour])
			{
				dfsHelper(neighbour,visited);
			}
		}


	}
	void dfs(T source)
	{
		unordered_map<T,bool> visited;

		dfsHelper(source,visited);
		cout<<endl;
	}

	void Components()
	{
		unordered_map<T,bool> visited;
		int components=0;

		for(auto node: adjList)
		{
			T a=node.first;

			if(!visited[a])
			{
				dfsHelper(a,visited);
				components++;
			}
		}
		cout<<components<<endl;

	}

	bool isCyclicBFS(T source)
	{
		queue<T> q;
		unordered_map<T,bool> visited;
		unordered_map<T,T> parent;

		q.push(source);
		visited[source]=true;
		parent[source]=source;

		while(!q.empty())
		{
			T node=q.front();
			q.pop();

			for(auto neighbour:adjList[node])
			{
				if(visited[neighbour] and neighbour!=parent[node])
					return true;
				else if(!visited[neighbour])
				{
					visited[neighbour]=true;
					q.push(neighbour);
					parent[neighbour]=node;
				}
			}
		}
		return false;
	}
	//Directed Graph
	bool isCyclicDFShelper(T node,unordered_map<T,bool> &visited,unordered_map<T,bool> &inStack)
	{
		//Processing the current node-Visited and instack true..
		visited[node]=true;
		inStack[node]=true;

		//Explore its neighbours
		for(auto neighbour:adjList[node])
		{
			//Now two things can happen
			//1. the current node is not visited but its further branch leads to a cycle
			if(!visited[neighbour] and isCyclicDFShelper(neighbour,visited,inStack) or inStack[neighbour])
			{
				return true;
			}
		}
		//pop out the node from the stack
		inStack[node]=false;
		return false;
	}
	bool isCyclicDFS()
	{
		unordered_map<T,bool> visited;
		unordered_map<T,bool> inStack;

		for(auto i:adjList)
		{
			T node=i.first;

			bool cycle=isCyclicDFShelper(node,visited,inStack);
			if(cycle)
				return true;
		}
		return false;
	}
	//Undirected Graph
	bool isCyclicUDFShelper(T node,unordered_map<T,bool> &visited,parent)
	{
		visited[node]=true;

		for(auto neighbour:adjList[node])
		{
			if(neighbour!=parent)
			{
				return true;
			}else if(!visited[neighbour])
			{
				bool cycleDetected=isCyclicUDFShelper(neighbour,visited,node);
				if(cycleDetected)
					return true;
			}
		}
		return false;
	}
	bool isCyclicUDFS()
	{
		unordered_map<T,bool> visited;

		for(auto i:adjList)
		{
			T node=i.first;

			if(!visited[node])
			{
				bool ans=isCyclicUDFShelper(node,visited,node);
				if(ans)
				{
					return true;
				}
			}
		}
		return false;
	}

	
	void topologicalSort() {

		unordered_map<T, int> indegree;
		queue<T> q;

		for (auto node : adjList) {
			indegree[node.first] = 0;
		}

		for (auto node : adjList) {

			for (T neighbor : node.second) {
				indegree[neighbor]++;
			}
		}

		for (auto node : indegree) {
			T val = node.first;

			int count = node.second;

			if (count == 0) {
				q.push(val);
			}
		}

		while (!q.empty()) {

			T node = q.front();
			q.pop();

			cout << node << "->";

			for (T neighbor : adjList[node]) {
				indegree[neighbor]--;

				if (indegree[neighbor] == 0) {
					q.push(neighbor);
				}
			}
		}

		cout << endl;
	}

	void bfsShortesPath(T src) {
		queue<T> q;
		unordered_map<T, int> dist;

		for (auto node : adjList) {

			T val = node.first;

			dist[val] = INT_MAX;
		}

		dist[src] = 0;
		q.push(src);

		while (!q.empty()) {

			T node = q.front();
			q.pop();

			for (T neighbor : adjList[node]) {
				if (dist[neighbor] == INT_MAX) {
					dist[neighbor] = 1 + dist[node];
					q.push(neighbor);
				}
			}
		}

		for (auto val : dist) {
			cout << val.first << " -> " << val.second << endl;
		}
	}
};
int main() {


	return 0;
}
