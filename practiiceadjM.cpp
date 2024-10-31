#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;

class Graph
{
private:
    int numVertices;
    int **adjMatrix;
    bool isDirected;
    bool isWeighted;

public:
    Graph(int vertices,bool weighted,bool directed)
    {
        numVertices = vertices;
        isWeighted = weighted;
        isDirected = directed;

        adjMatrix = new int*[numVertices];
        for(int i=0;i<numVertices;i++)
        {
            adjMatrix[i] = new int[numVertices];
        }

        for(int i=0;i<numVertices;i++)
        {
            for(int j=0;j<numVertices;j++)
            {
                adjMatrix[i][j]=0;
            }
        }
    }

    ~Graph()
    {
        for(int i=0;i<numVertices;i++)
        {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }

    void addEdge(int u,int v,int weight)
    {
        u--;
        v--;
        adjMatrix[u][v]=weight;
        if(!isDirected)
        {
            adjMatrix[v][u]=weight;
        }
    }

    void printmatrix()
    {
        for(int i=0;i<numVertices;i++)
        {
            for(int j=0;j<numVertices;j++)
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

};

vector<string> split(const string &str,char delim)
{
    vector<string> tokens;
    stringstream ss(str);
    string token;
    while(getline(ss,token,delim))
    {
        tokens.push_back(token);
    }
    return tokens;
}

int main()
{
    ifstream inputFile("graph_input.txt");

    if(!inputFile.is_open())
    {
        cout << "Error opening file" << endl;
        return 1;
    }

    int vertices,edges;
    string isWeighted,isDirected;

    inputFile >>  vertices >> edges;

    inputFile >> isWeighted;
    bool weightedFlag = (isWeighted == "weighted");

    inputFile >> isDirected;
    bool directedFlag = (isDirected == "directed");

    Graph g(vertices,weightedFlag,directedFlag);

    string line;
    getline(inputFile,line);

    for(int i=0;i<edges;i++)
    {
        getline(inputFile,line);
        vector<string> edgeData = split(line,' ');

        int u = stoi(edgeData[0]);
        int v = stoi(edgeData[1]);
        int weight = weightedFlag ? stoi(edgeData[2]):1;

        g.addEdge(u,v,weight);
    }

    inputFile.close();

    g.printmatrix();

    return 0;
}