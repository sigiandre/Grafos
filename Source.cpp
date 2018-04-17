#include<iostream>
#include<list>

using namespace std;

class Graph {
private:
	int n; //número de vértice en el gráfico
	list<int>* listAd; //Puntero a una lista que contiene listas de adyacencia
	void DFSUtil(int u, bool visited[]);
public:
	Graph(int n = 10);
	void addEdge(int v, int w); //función para agregar un borde a Grafico
	void DFS(int s); //Obtener los vértices accesibles dada una fuente de nodo
};

Graph::Graph(int n) {
	this->n = n;
	listAd = new list<int>[n];
}

void Graph::addEdge(int u, int v) {
	listAd[u].push_back(v);
}

void Graph::DFSUtil(int v, bool visited[]) {
	visited[v] = true;
	cout << v << " ";

	list<int>::iterator i;
	for (i = listAd[v].begin(); i != listAd[v].end(); ++i) 
		if (!visited[*i])
			DFSUtil(*i, visited);
}

void Graph::DFS(int v) {
	bool *visited = new bool[n];
	for (int i = 0; i < n; i++)
		visited[i] = false;

	DFSUtil(v, visited);
}

//---
int main() {
	
	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "Transversal DFS: vértice inicial 2 " << endl;
	g.DFS(2);

	system("pause");
	return 0;

}
