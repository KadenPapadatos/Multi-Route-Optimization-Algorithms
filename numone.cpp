#include <fstream>
#include <iostream>
#include <string>
#include <list>
#include <stack>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <fstream>
#include <set>
#include <algorithm>
#include <chrono>
using namespace std;
void printMST(pair<int, vector<array<int, 3>>> mst, string filename);
pair<int, vector<array<int, 3>>> read(const string& filename);
pair<int, vector<array<int, 3>>> primsAlgo(vector<array<int, 3>> adjList, int vertNum);
pair<int, vector <array<int,3>>> kruskalAlgo(vector<array<int, 3>> adjList, int vertNum);
pair<int, vector<array<int, 3>>> kruskalsAlgoPC(vector<array<int, 3>> adjList, int vertNum);

pair<int, vector<array<int, 3>>> read(const string& filename){
    ifstream graph("graphs/" + filename);
    vector <array<int, 3>> graphList;
    string line;
    string vertNum;
    int vert1, vert2, weight;
    if(graph.fail()){
        cout << "Error opening file" << endl;
        exit(1);
    }

    if (graph.is_open()) {
        getline(graph, vertNum);

        while (getline(graph, line)) {
            stringstream ss(line);
            char comma;
            ss >> vert1 >> comma >> vert2 >> comma >> weight;
            graphList.push_back({vert1, vert2, weight});
        }
    }

    graph.close();
    return {stoi(vertNum), graphList}; 
}
void printMST(pair<int, vector<array<int, 3>>> mst, string filename) {
    ofstream outfile(filename);

if (outfile.fail())
    {
        cout << "Error opening file" << endl;
        exit(1);
    }

    int numVertices = mst.first;
    vector<array<int, 3>> vert = mst.second;

    outfile << numVertices << endl;
    for (array<int, 3> edge : vert)
    {
        outfile << edge[0] << "," << edge[1] << "," << edge[2] << endl;
    }

    outfile.close();
}

int main(){
    //tests prim and kruskals on graph1.txt
    pair<int, vector<array<int, 3>>> graph = read("graph1.txt");

    auto t1 = chrono::high_resolution_clock::now();
    pair<int, vector<array<int, 3>>> mst = primsAlgo(graph.second, graph.first);
    auto t2 = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed = t2 - t1;
    cout << "Prim's Algo time: " << elapsed.count() << endl;
    printMST(mst, "graphoutput1.txt");
    t1 = chrono::high_resolution_clock::now();
    mst = kruskalAlgo(graph.second, graph.first);
    t2 = chrono::high_resolution_clock::now();
    elapsed = t2 - t1;
    cout << "Kruskal's Algo time: " << elapsed.count() << endl;
    printMST(mst, "graphoutput2.txt");

    t1 = chrono::high_resolution_clock::now();
    mst = kruskalsAlgoPC(graph.second, graph.first);
    t2 = chrono::high_resolution_clock::now();
    elapsed = t2 - t1;
    cout << "Kruskal's Algo with Path Compression time: " << elapsed.count() << endl;
    printMST(mst,"graphoutput3.txt");

    cout << endl << endl;
    //tests prim and kruskals on graph_v100_e150.txt
    graph = read("graph_v100_e150.txt");

    t1 = chrono::high_resolution_clock::now();
    mst = primsAlgo(graph.second, graph.first);
    t2 = chrono::high_resolution_clock::now();
    elapsed = t2 - t1;
    cout << "Prim's Algo time: " << elapsed.count() << endl;
    printMST(mst, "graphoutput4.txt");

    t1 = chrono::high_resolution_clock::now();
    mst = kruskalAlgo(graph.second, graph.first);
    t2 = chrono::high_resolution_clock::now();
    elapsed = t2 - t1;
    cout << "Kruskal's Algo time: " << elapsed.count() << endl;
    printMST(mst, "graphoutput5.txt");

    t1 = chrono::high_resolution_clock::now();
    mst = kruskalsAlgoPC(graph.second, graph.first);
    t2 = chrono::high_resolution_clock::now();
    elapsed = t2 - t1;
    cout << "Kruskal's Algo with Path Compression time: " << elapsed.count() << endl;
    printMST(mst,"graphoutput6.txt");

    cout << endl << endl;
    //tests prim and kruskals on graph_v200_e300.txt
    graph = read("graph_v200_e300.txt");

    t1 = chrono::high_resolution_clock::now();
    mst = primsAlgo(graph.second, graph.first);
    t2 = chrono::high_resolution_clock::now();
    elapsed = t2 - t1;
    cout << "Prim's Algo time: " << elapsed.count() << endl;
    printMST(mst, "graphoutput7.txt");

    t1 = chrono::high_resolution_clock::now();
    mst = kruskalAlgo(graph.second, graph.first);
    t2 = chrono::high_resolution_clock::now();
    elapsed = t2 - t1;
    cout << "Kruskal's Algo time: " << elapsed.count() << endl;
    printMST(mst, "graphoutput8.txt");

    t1 = chrono::high_resolution_clock::now();
    mst = kruskalsAlgoPC(graph.second, graph.first);
    t2 = chrono::high_resolution_clock::now();
    elapsed = t2 - t1;
    cout << "Kruskal's Algo with Path Compression time: " << elapsed.count() << endl;
    printMST(mst,"graphoutput9.txt");

    cout << endl << endl;
    //tests prim and kruskals on graph_v400_e1200.txt
    graph = read("graph_v400_e1200.txt");

    t1 = chrono::high_resolution_clock::now();
    mst = primsAlgo(graph.second, graph.first);
    t2 = chrono::high_resolution_clock::now();
    elapsed = t2 - t1;
    cout << "Prim's Algo time: " << elapsed.count() << endl;
    printMST(mst, "graphoutput10.txt");

    t1 = chrono::high_resolution_clock::now();
    mst = kruskalAlgo(graph.second, graph.first);
    t2 = chrono::high_resolution_clock::now();
    elapsed = t2 - t1;
    cout << "Kruskal's Algo time: " << elapsed.count() << endl;
    printMST(mst, "graphoutput11.txt");

    t1 = chrono::high_resolution_clock::now();
    mst = kruskalsAlgoPC(graph.second, graph.first);
    t2 = chrono::high_resolution_clock::now();
    elapsed = t2 - t1;
    cout << "Kruskal's Algo with Path Compression time: " << elapsed.count() << endl;
    printMST(mst,"graphoutput12.txt");

    cout << endl << endl;
    //tests prim and kruskals on graph_v800_e3200.txt
    graph = read("graph_v800_e3200.txt");

    t1 = chrono::high_resolution_clock::now();
    mst = primsAlgo(graph.second, graph.first);
    t2 = chrono::high_resolution_clock::now();
    elapsed = t2 - t1;
    cout << "Prim's Algo time: " << elapsed.count() << endl;
    printMST(mst, "graphoutput13.txt");

    t1 = chrono::high_resolution_clock::now();
    mst = kruskalAlgo(graph.second, graph.first);
    t2 = chrono::high_resolution_clock::now();
    elapsed = t2 - t1;
    cout << "Kruskal's Algo time: " << elapsed.count() << endl;
    printMST(mst, "graphoutput14.txt");

    t1 = chrono::high_resolution_clock::now();
    mst = kruskalsAlgoPC(graph.second, graph.first);
    t2 = chrono::high_resolution_clock::now();
    elapsed = t2 - t1;
    cout << "Kruskal's Algo with Path Compression time: " << elapsed.count() << endl;
    printMST(mst,"graphoutput15.txt");

    cout << endl << endl;
    //tests prim and kruskals on graph_v1600_e6400.txt
    graph = read("graph_v1600_e6400.txt");

    t1 = chrono::high_resolution_clock::now();
    mst = primsAlgo(graph.second, graph.first);
    t2 = chrono::high_resolution_clock::now();
    elapsed = t2 - t1;
    cout << "Prim's Algo time: " << elapsed.count() << endl;
    printMST(mst, "graphoutput16.txt");

    t1 = chrono::high_resolution_clock::now();
    mst = kruskalAlgo(graph.second, graph.first);
    t2 = chrono::high_resolution_clock::now();
    elapsed = t2 - t1;
    cout << "Kruskal's Algo time: " << elapsed.count() << endl;
    printMST(mst, "graphoutput17.txt");

    t1 = chrono::high_resolution_clock::now();
    mst = kruskalAlgo(graph.second, graph.first);
    t2 = chrono::high_resolution_clock::now();
    elapsed = t2 - t1;
    cout << "Kruskal's Algo with Path Compression time: " << elapsed.count() << endl;
    printMST(mst,"graphoutput18.txt");
    return 0;
}
struct Compare{
    bool operator()(const array<int, 3> &a, const array<int, 3> &b){
        return a[2] > b[2];
    }
};
pair<int, vector<array<int, 3>>> primsAlgo(vector<array<int, 3>> adjList, int vertNum) {
    priority_queue<array<int, 3>, vector<array<int, 3>>, Compare> pq; 
    int next;
    int start = adjList[0][0];
    vector<array<int, 3>> mst;
    vector<bool> visited(vertNum + 1, false);
    visited[start] = true;

    for (const array<int, 3> &edge : adjList)
    {
        if (edge[0] == start || edge[1] == start)
        {
            pq.push(edge);
        }
    }

    while (!pq.empty())
    {
        array<int, 3> current = pq.top();
        pq.pop();

        if  (visited[current[0]])
        {
            next = current[1];
        }
        else
        {
            next = current[0];
        }

        if (!visited[next])
        {
            mst.push_back(current);
            visited[next] = true;

            for (const array<int, 3> &edge : adjList)
            {
                if ((edge[0] == next && !visited[edge[1]]) ||(edge[1] == next && !visited[edge[0]]))
                {
                    pq.push(edge);
                }
            }
        }
    }

    return {vertNum ,mst};
}






pair<int, vector <array<int,3>>> kruskalAlgo(vector<array<int, 3>> adjList, int vertNum){
    vector<array<int, 3>> mst;
    vector<int> djs(vertNum + 1, -1);//DisJointSet
    sort(adjList.begin(), adjList.end(), [](const array<int, 3> &a, const array<int, 3> &b){
        return a[2] < b[2];
    });
    int edgeNum = 0;
    int i = 0;
    while(edgeNum < vertNum - 1){
        array<int, 3> current = adjList[i];
        int v1 = current[0];
        int v2 = current[1];

        int v1Root = v1;
        int v2Root = v2;
        while(djs[v1Root] >= 0){
            v1Root = djs[v1Root];
        }
        while(djs[v2Root] >= 0){
            v2Root = djs[v2Root];
        }

        if (v1Root != v2Root){
            mst.push_back(current);
            edgeNum++;
            if (djs[v1Root] < djs[v2Root]){
                djs[v1Root] += djs[v2Root];
                djs[v2Root] = v1Root;
            }
            else{
                djs[v2Root] += djs[v1Root];
                djs[v1Root] = v2Root;
            }
        }
        i++;
    }
    return {vertNum, mst};
}
int find (int x, vector<int> &djs)
{
    if (djs[x] == -1)
    {
        return x;
    }
    else
    {
        return djs[x] = find(djs[x], djs);
    }
}

pair<int, vector<array<int, 3>>> kruskalsAlgoPC(vector<array<int, 3>> adjList, int vertNum)
{
    sort(adjList.begin(), adjList.end(), [](const array<int, 3> &a, const array<int, 3> &b) {
        return a[2] < b[2];
    }); 

    vector<array<int, 3>> mst;
    vector<int> djs(vertNum + 1, -1);
    unsigned int unsignedVert = vertNum;

    for (unsigned int i  = 0; i < adjList.size(); i++)
    {
        array<int, 3> current = adjList[i];
        int v1 = current[0];
        int v2 = current[1];

        int root1 = find(v1, djs);
        int root2 = find(v2, djs);

        if (root1 != root2)
        {
            mst.push_back(current);
            djs[root1] = root2;
        }

        if (mst.size() == unsignedVert - 1)
        {
            break;
        }
    
    }
    return {vertNum, mst};
}
