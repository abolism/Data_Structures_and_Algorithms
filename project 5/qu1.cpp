#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Graph {


    bool* visited;

public:
    unordered_map<int, vector<int>> adjLists;
    int numVertices;
    int componentsNumVerticles =0;
    int numEdges =0;
//    Graph(int vertices);
//    list<Graph> components;
//    Graph thisComponent();
    void addEdge(int src, int dest){
        adjLists[src].push_back(dest);
        adjLists[dest].push_back(src);
        numEdges++;
    };
    int largest =0 , secondLargest=0;
    void store(int a){
        if (a > largest) {
            secondLargest = largest;
            largest = a;
        } else if (a > secondLargest && a != largest)
            secondLargest = a;
        componentsNumVerticles ++;
    };
    int solve(){
        if (numEdges > adjLists.size())
            return -1;
        unordered_map<int, int> indexReserve;
        indexReserve.reserve(adjLists.size());
        vector<pair<int,vector<int>>> adjBasedOnIndex(adjLists.size());

        int i = 0;
        for (auto &adjList : adjLists) {
            indexReserve[adjList.first] = i;
            adjBasedOnIndex[i].first = adjList.first;
            adjBasedOnIndex[i].second = adjList.second;
            i++;
        }

        int result =0;
        vector<bool> visited(adjBasedOnIndex.size());
        for (int j = 0; j < adjLists.size(); ++j) {
            visited[j] = false ;
        }
        for (int j = 0; j < adjBasedOnIndex.size(); ++j) {
            if (visited[j])
                continue;
            visited[j]= true;
            largest = 0;
            secondLargest =0;
            componentsNumVerticles =0;
            stack<int> BFSQ;
            BFSQ.push(j);
            int componentsNumEdge = 0;
            while (!BFSQ.empty()){
                int toDoTheNextStep = BFSQ.top();
                BFSQ.pop();
                for (const auto & itr : adjBasedOnIndex[toDoTheNextStep].second) {
                    int index = indexReserve[itr];
                    if (visited[index]) continue;
                    visited[index] = true;
                    BFSQ.push(index);
                }
                store(adjBasedOnIndex[toDoTheNextStep].first);
                componentsNumEdge += adjBasedOnIndex[toDoTheNextStep].second.size();
            }
            componentsNumEdge /= 2;
//            int m;
            if (componentsNumEdge > componentsNumVerticles){
                return  -1;
            } else{
                if (componentsNumEdge == componentsNumVerticles){
                    if (largest > result) {
                        result = largest;
                    }
                } else{
                    if (secondLargest > result){
                        result = secondLargest;
                    }
                }
            }
//            result= max(m , result);

        }
        return result;


//            int counter =0;
//            for (int i = 0; i < g.numVertices; ++i) {
//                while(!visited[i]){
//                    counter++;
//                    if (i>0) {
//                        thisComponent.adjLists->clear();
//                    }
//                    BFS(i,thisComponent);
//                    if (i>0)
//                        components.push_back(thisComponent);
//                }
//            }
//            int max = 0;
//            int max2 = 0;
//            for (auto itr = components.begin();
//                 itr != components.end(); itr++) {
//                int numberOfVertics = (*itr).adjLists->size();
//                int numberOfEdges = (*itr).numEdges;
//                if (numberOfEdges>numberOfVertics){
//                    return -1;
//                } else{
//                    if (numberOfVertics= numberOfEdges){
//                        int maxOfVertics = 0;
//                        for (auto itr2 = (*itr).adjLists->begin();
//                             itr2 != (*itr).adjLists->end(); itr2++) {
//                            if (*itr2 > maxOfVertics)
//                                maxOfVertics = (*itr2);
//                        }
//                        if (maxOfVertics>max){
//                            max = maxOfVertics;
//                        }
//                    }
//                    else{
//                        auto largest = (*itr).adjLists->begin(), secondLargest = (*itr).adjLists->begin()--;
//
//                        // finding the largest element in the array
//                        for (auto itr2 = (*itr).adjLists->begin();
//                             itr2 != (*itr).adjLists->end(); itr2++) {
//                            if ((*itr2) > (*largest))
//                                largest = itr2;
//                        }
//
//                        // finding the largest element in the array excluding
//                        // the largest element calculated above
//                        for (auto itr2 = (*itr).adjLists->begin();
//                             itr2 != (*itr).adjLists->end(); itr2++) {
//                            if ((*itr2) != (*largest)) {
//                                // first change the value of second largest
//                                // as soon as the next element is found
//                                if (secondLargest == (*itr).adjLists->begin()--)
//                                    secondLargest = itr2;
//                                else if ((*itr2) > (*secondLargest))
//                                    secondLargest = itr2;
//                            }
//                        }
//                        if (*secondLargest > max2){
//                            max2 = *secondLargest;
//                        }
//                    }
//                }
//            }
//        if (max>max2) return max;
//        return max2;
    }

};

//Graph::Graph(int vertices) {}
// Create a graph with given vertices,
// and maintain an adjacency list
//Graph::Graph(int vertices) {
//    numVertices = vertices;
//    adjLists.clear();
//}

// Add edges to the graph
//void Graph::addEdge(int src, int dest) {
//    adjLists[src].push_back(dest);
//    adjLists[dest].push_back(src);
//    numEdges++;
//}

//Graph::Graph() {
//
//}

// BFS algorithm
//void Graph::BFS(int startVertex , Graph thisComponent) {
//    visited = new bool[numVertices];
//    for (int i = 0; i < numVertices; i++)
//        visited[i] = false;
//
//    list<int> queue;
//
//    visited[startVertex] = true;
//    queue.push_back(startVertex);
//
//    list<int>::iterator i;
//
//    while (!queue.empty()) {
//        int currVertex = queue.front();
////        cout << "Visited " << currVertex << " ";
//        queue.pop_front();
//
//        for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i) {
//            int adjVertex = *i;
//            if (!visited[adjVertex]) {
//                visited[adjVertex] = true;
//                thisComponent.addEdge(startVertex,adjVertex);
//                queue.push_back(adjVertex);
//            }
//        }
//    }
//}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
    int n;
    cin >> n;
    Graph g;
//    Graph thisComponent(2*n);
    for (int i = 0; i < n; ++i) {
        int a,b;
        cin >>a>>b;
        g.addEdge(a,b);
    }
//    cout << "be";
    int answer = g.solve();
//    cout << "be2";
//    list<Graph> toBePrinted = g.components;
//    for (int i = 0; i < toBePrinted.size(); ++i) {
//        cout << "\nthe component number " << i+1 <<" is :\n";
//        for (int j = 0; j < toBePrinted.begin()->numVertices; ++j) {
//            cout << "\nthis is " << j +1 << "th adjacency list :\n";
//
//            for (int k = 0; k < *toBePrinted.begin()->adjLists[j].begin(); ++k) {
//                list<int>::iterator it = toBePrinted.begin()->adjLists[j].begin();
//                cout << *it << " ";
//                toBePrinted.begin()->adjLists->pop_back();
//            }
////            cout << toBePrinted.begin()->adjLists[j];
//        }
//    }
//    cout << "be3";
//    Graph g(4);
//    g.addEdge(0, 1);
//    g.addEdge(0, 2);
//    g.addEdge(1, 2);
//    g.addEdge(2, 3);

//    g.DFS(2);
    cout << answer;
    return 0;
}