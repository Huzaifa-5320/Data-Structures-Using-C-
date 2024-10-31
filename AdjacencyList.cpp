#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<queue>
using namespace std;

struct Node
{
    int vertex;
    int weight;
    Node* next;
};

class Graph{
private:
   int numVertices;
   Node** adjList;
   bool isWeighted;
   bool isDirected;

public:
    Graph(int vertices,bool weighted,bool directed)
    {
       numVertices = vertices;
       isWeighted = weighted;
       isDirected = directed;

       adjList = new Node*[numVertices];
       for(int i=0;i<numVertices;i++){
           adjList[i] = nullptr; 
       }
    }   

    ~Graph()
    {
       for(int i=0;i<numVertices;i++){
            Node* temp = adjList[i];
            while(temp!=nullptr){
               Node* toDelete = temp;
               temp = temp->next;
               delete toDelete; 
            } 
        }
        delete[] adjList;
    }

    void addEdge(int u,int v,int weight)
    {
        u--,v--;

        Node* newNode = new Node{v,weight,nullptr};

        if (adjList[u]==nullptr)
        {
            adjList[u] = newNode;
        } else {
            Node* temp = adjList[u];
            while(temp->next!=nullptr){
                temp = temp->next;
            }

            temp->next = newNode;
        }

        if(!isDirected)
        {
            Node* reverseNode = new Node{u,weight,nullptr};

            if(adjList[v]==nullptr)
            { 
                adjList[v] = reverseNode;
            } else {
                Node* temp = adjList[v];
                while(temp->next!=nullptr)
                {
                    temp = temp->next;
                } 
                temp->next = reverseNode;
            }
        }
    }

    void calculateIndegree(vector<int>& indegree)
    {
        indegree.assign(numVertices,0);

        for(int u=0;u<numVertices;u++)
        {
            Node* temp = adjList[u];
            while(temp != nullptr)
            {
                indegree[temp->vertex]++;
                temp = temp->next;
            }
        }
    }

    void calculateOutdegree(vector<int>& outdegree)
    {
        outdegree.assign(numVertices,0);

        for(int u=0;u<numVertices;u++)
        {
            Node* temp = adjList[u];
            while(temp != nullptr)
            {
                outdegree[u]++;
                temp = temp->next;
            }
        }
    }

    void printIndegreeOutdegree()
    {
        vector<int> indegree,outdegree;

        // Calculate indegree and outdegree
        calculateIndegree(indegree);
        calculateOutdegree(outdegree);


       
        cout << "Indegree and Outdegree:" << endl;
        for (int i = 0; i < numVertices; i++) {
            cout << "Vertex " << (i + 1) << ": Indegree = " << indegree[i] << ", Outdegree = " << outdegree[i] << endl;
        }

    }


    void BFS_AdjList(int startVertex) 
    {
        vector<bool> visited(numVertices, false);  // Keep track of visited vertices
        queue<int> q;  // Queue for BFS

        startVertex--;  // Adjust to 0-based index
        visited[startVertex] = true;  // Mark the start vertex as visited
        q.push(startVertex);  // Push the start vertex to the queue

        cout << "BFS traversal starting from vertex " << (startVertex + 1) << ": ";

        while (!q.empty()) {
            int currentVertex = q.front();
            q.pop();
            cout << (currentVertex + 1) << " ";  // Print the current vertex (adjust back to 1-based)
            
            Node* temp = adjList[currentVertex];
            // temp is initialized to point to the head of the linked list of neighbors for currentVertex!
            // So, if adjList[currentvertex] points to a node that has vertex set to 1, then temp now points to that node.
            while (temp != nullptr) {
                if (!visited[temp->vertex]) {
                    visited[temp->vertex] = true;
                    q.push(temp->vertex);
                } 
                temp = temp->next;
            }
        }
        cout << endl;
    }

    void topologicalSort()
    {
        vector<int> indegree;
        calculateIndegree(indegree);

        queue<int> q;
        for(int i=0;i<numVertices;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }

        vector<int> topOrder;
        while(!q.empty())
        {
            int currentVertex = q.front();
            q.pop();
            topOrder.push_back(currentVertex);

            Node* temp = adjList[currentVertex];
            while(temp != nullptr)
            {
                indegree[temp->vertex]--;
                if(indegree[temp->vertex]==0)
                {
                    q.push(temp->vertex);
                }
                temp = temp-> next;
            }
        }

        if (topOrder.size() != numVertices)
        {
            cout << "Graph has a cycle.Topological sort not possible" << endl;
            return;
        }

        cout << "Topological Sort: ";
        for(int v:topOrder)
        {
            cout << (v+1) << " ";
        } 
        cout << endl;
    }

    void printList()
    {
        for(int i=0;i<numVertices;i++)
        {
            
            if (adjList[i] == nullptr) {
            continue; // Skip vertices with no outgoing edges
         }
            cout << "Vertex " << (i+1) << ":";
            Node* temp = adjList[i];
            while(temp!=nullptr)
            {
                cout << "->" << (temp->vertex+1) << " (weight: " << temp->weight << ") ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

// helper function to split strings
vector<string> split (const string &str,char delim)
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
        cout << "Error opening file!" << endl;
        return 1;
    }

    int vertices,edges;
    string weightedFlag,directedFlag;

    inputFile >> vertices >> edges;

    inputFile >> weightedFlag;
    bool isWeighted = (weightedFlag == "weighted");

    inputFile >> directedFlag;
    bool isDirected = (directedFlag == "directed");

    Graph g(vertices,isWeighted,isDirected);

    string line;
    getline(inputFile,line);

    for(int i=0;i<edges;i++)
    {
        getline(inputFile,line);
        vector<string> edgeData = split(line,' ');

        int u = stoi(edgeData[0]);
        int v = stoi(edgeData[1]);
        int weight = isWeighted ? stoi(edgeData[2]):1;

        g.addEdge(u,v,weight);
    }
    inputFile.close();


    cout << "AdjacencyList :" << endl;
    g.printList();

    // g.printIndegreeOutdegree();

    // g.BFS_AdjList(1);

    g.topologicalSort();
    
}