#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<queue>
using namespace std;

class Graph
{
private:
    int numVertices;
    int** adjMatrix;
    bool isWeighted;
    bool isDirected;

public:
    // Constructor
    Graph(int vertices, bool weighted, bool directed)
    {
        numVertices = vertices;
        isWeighted = weighted;
        isDirected = directed;

        // Dynamically allocate a 2D array
        adjMatrix = new int*[numVertices];
        for (int i = 0; i < numVertices; i++) {
            adjMatrix[i] = new int[numVertices];
        }

        // Initialize adjMatrix with 0
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    // Destructor to clean up memory
    ~Graph()
    {
        for (int i = 0; i < numVertices; i++) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }

    // Add edge to the graph
    void addEdge(int u, int v, int weight)
    {
        u--;
        v--;
        adjMatrix[u][v] = weight;
        if (!isDirected) {
            adjMatrix[v][u] = weight; // For undirected graph
        }
    }

    int inDegree(int vertex)
    {
        if(vertex<1 || vertex>numVertices)
        {
            cout << "Invalid vertex" << endl;
            return -1;
        }

        int degree = 0;
        for(int i=0;i<numVertices;i++)
        {
            if(adjMatrix[i][vertex-1]!=0)
            {
                degree++;
            }
        }
        return degree;
    }

    int outDegree(int vertex)
    {
        if(vertex<1 || vertex>numVertices)
        {
            cout << "Invalid vertex" << endl;
            return -1;
        }

        int degree = 0;
        for(int j=0;j<numVertices;j++)
        {
            if(adjMatrix[vertex-1][j]!=0)
            {
                degree++;
            }
        }
        return degree;
    }

    // to dry run
    void BFS_AdjMatrix(int startVertex) {
    vector<bool> visited(numVertices, false);
    queue<int> q;

    startVertex--;  // Adjust to 0-based index
    visited[startVertex] = true;
    q.push(startVertex);

    while (!q.empty()) {
        int currentVertex = q.front();
        q.pop();

        cout << (currentVertex + 1) << " ";  // Output in 1-based indexing

        for (int i = 0; i < numVertices; i++) {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

       

    // Print the adjacency matrix
    void printMatrix()
    {
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

};

// Helper function to split strings
vector<string> split(const string &str, char delim)
{
    vector<string> tokens;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delim)) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    ifstream inputFile("graph_input.txt");

    if (!inputFile.is_open()) {
        cout << "Error opening file!" << endl;
        return 1;
    }   

    int vertices, edges;
    string weightedFlag, directedFlag;

    // Read the number of vertices and edges
    inputFile >> vertices >> edges;

    // Read whether the graph is weighted or unweighted
    inputFile >> weightedFlag;
    bool isWeighted = (weightedFlag == "weighted");

    // Read whether the graph is directed or undirected
    inputFile >> directedFlag;
    bool isDirected = (directedFlag == "directed");

    // Create the graph
    Graph graph(vertices, isWeighted, isDirected);

    // Reading the edges from the file
    string line;
    getline(inputFile, line); // Consume the remaining new line

    for (int i = 0; i < edges; i++) {
        getline(inputFile, line);
        vector<string> edgeData = split(line, ' ');

        int u = stoi(edgeData[0]);
        int v = stoi(edgeData[1]);
        int weight = isWeighted ? stoi(edgeData[2]) : 1;  // condition ? expression if true : expression if false ;

        graph.addEdge(u, v, weight);
    }

    inputFile.close();

    // Display the adjacency matrix
    cout << "Adjacency Matrix:" << endl;
    graph.printMatrix();

    // cout << "In Degree of each vertex is:" << endl;
    // cout << graph.inDegree(1) << endl;
    // cout << graph.inDegree(2) << endl;
    // cout << graph.inDegree(3) << endl;
    // cout << graph.inDegree(4) << endl;
    // cout << graph.inDegree(5) << endl;
    // cout << graph.inDegree(6) << endl;

    // cout << "Out Degree of each vertex is:" << endl;
    // cout << graph.outDegree(1) << endl;
    // cout << graph.outDegree(2) << endl;
    // cout << graph.outDegree(3) << endl;
    // cout << graph.outDegree(4) << endl;
    // cout << graph.outDegree(5) << endl;
    // cout << graph.outDegree(6) << endl;

    graph.BFS_AdjMatrix(1);

    return 0;
}