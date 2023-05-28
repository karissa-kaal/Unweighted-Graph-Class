#include <iostream>
#include <list>
using namespace std;

class unweightedGraph {
private:
    int vertices;
    list<char>* graph;
public:
    unweightedGraph(int count) {
        vertices = count;
        graph = new list<char>[vertices + 1];
    }

    //Q1
    bool DFSHelperFunc(int i, int j, bool checked[]) {
        //helper func
        checked[i] = true;

        //in case they are equal return true
        if (char(i + 97) == char(j + 97))
            return true;

        list<char>::iterator x;
        for (x = graph[i].begin(); x != graph[i].end(); ++x) {
            //making all the same ones true
            if (!checked[*x - 97])
                DFSHelperFunc(*x - 97, j, checked);
        }
    }

    bool DFS(int l, int m) {
        bool* checked = new bool[vertices];

        //initializing all as false
        for (int i = 0; i < vertices; i++)
            checked[i] = false;

        return DFSHelperFunc(l, m, checked);
    }

    bool checkConnectionbyDFS(char l, char m) {
        //check if two given nodes are connected using DFS
        if (l == m)
            return true;
        else
            return DFS(l - 97, m - 97);//sending as integers
    }

    void BFS(int temp) {
        //using BFS
        bool* checked = new bool[vertices];

        //initialising as false
        for (int i = 0; i < vertices; i++)
            checked[i] = false;

        list<char> List2;
        checked[temp] = true;
        List2.push_back(temp);

        list<char>::iterator i;
        while (!List2.empty()) {
            temp = List2.front();
            cout << char(temp + 97) << " ";
            List2.pop_front();

            for (i = graph[temp].begin(); i != graph[temp].end(); ++i) {
                //in case checked is false
                if (!checked[*i - 97]) {
                    checked[*i - 97] = true;
                    //make it true and add to list
                    List2.push_back(*i - 97);
                }
            }
        }
    } 

    //Q2
    void DFSYes(int v, bool* checked) {
        // Mark the current node as visited and print it
        checked[v] = true;

        // Recur for all the vertices adjacent to this vertex
        list<char>::iterator i;
        for (i = graph[v].begin(); i != graph[v].end(); ++i)
            if (!checked[*i])
                DFSYes(*i, checked);
    }

    // Function that returns reverse of this graph
    unweightedGraph getReverse() {
        unweightedGraph g(vertices);

        // Recur for all the vertices adjacent to this vertex
        for (int v = 0; v < vertices; v++)
            for (auto i = graph[v].begin(); i != graph[v].end(); ++i)
                g.graph[*i].push_back(v);
   
        return g;
    }

    bool isConnectedStrongly() {
        //checking if connected
        //Marking all the vertices as false
        bool* checked = new bool[vertices];
        for (int i = 0; i < vertices; i++)
            checked[i] = false;

        //DFS traversal
        DFSYes(0, checked);

        //if any value is false return false.
        for (int i = 0; i < vertices; i++)
            if (checked[i] == false)
                return false;

        //creating reversed graph and initializing to false
        unweightedGraph revGraph = getReverse();
        for (int i = 0; i < vertices; i++)
            checked[i] = false;

        //DFS for reversed graph
        revGraph.DFSYes(0, checked);

        //if any value is false return false
        for (int i = 0; i < vertices; i++)
            if (checked[i] == false)
                return false;

        return true;
    }

    //Q3
    bool isCyclic(int j, bool checked[], int parent) {
        //helper
        //current node as visited
        checked[j] = true;
       
        auto i = graph[j].begin();
        for (; i != graph[j].end(); ++i) {
            if (!checked[*i]) {
                if (isCyclic(*i, checked, j))
                    return true;
            }
            else if (*i != parent)
                return true;
        }
        return false;
    }

    bool isCyclic() {
        //initialize array as false
        bool* checked = new bool[vertices + 1];
        for (int i = 0; i < vertices + 1; i++)
            checked[i] = false;

        //using DFS
        for (int i = 0; i < vertices + 1; i++)
            if (!checked[i])
                if (isCyclic(i, checked, -1))
                    return true;

        return false;
    }
};
