#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class Graph {
public:
    map<string, vector<string>> adjList;

    // Menambahkan edge antara dua kota
    void addEdge(string City1, string City2) {
        adjList[City1].push_back(City2);
        adjList[City2].push_back(City1); // Graph tidak berarah
    }

    // BFS untuk mencari rute perjalanan dari start ke destination
    void findRouteBFS(string Start, string End) {
        queue<vector<string>> queueRoutes; // Queue untuk menyimpan jalur perjalanan
        set<string> visited; // Menyimpan kota yang sudah dikunjungi

        // Masukkan jalur awal (hanya berisi kota start)
        queueRoutes.push({Start});
        visited.insert(Start);

        while (!queueRoutes.empty()) {
            vector<string> path = queueRoutes.front();
            queueRoutes.pop();
            string lastCity = path.back();

            if (lastCity == End) {
                cout << "Rute perjalanan dari " << Start << " ke " << End << ":\n";
                for (const string &City : path) {
                    cout << City;
                    if (City != End) cout << " -> ";
                }
                cout << endl;
                return;
            }

            // Tambahkan kota tetangga yang belum dikunjungi ke antrian
            for (const string &neighbor : adjList[lastCity]) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    vector<string> newPath = path;
                    newPath.push_back(neighbor);
                    queueRoutes.push(newPath);
                }
            }
        }

        cout << "Tidak ada rute dari " << Start << " ke " << End << "!\n";
    }
};

int main() {
    Graph g;

    g.addEdge("Arad", "Zerind");
    g.addEdge("Zerind", "Oradea");
    g.addEdge("Oradea", "Sibiu");
    g.addEdge("Arad", "Sibiu");
    g.addEdge("Sibiu", "Fagaras");
    g.addEdge("Fagaras", "Bucharest");
    g.addEdge("Sibiu", "Rimnicu Vilcea");
    g.addEdge("Rimnicu Vilcea", "Craiova");
    g.addEdge("Rimnicu Vilcea", "Pitesti");
    g.addEdge("Craiova", "Pitesti");
    g.addEdge("Pitesti", "Bucharest");
    g.addEdge("Arad", "Timisoara");
    g.addEdge("Timisoara", "Lugoj");
    g.addEdge("Lugoj", "Mehadia");
    g.addEdge("Mehadia", "Dobreta");
    g.addEdge("Dobreta", "Craiova");
    g.addEdge("Bucharest", "Giurgiu");
    g.addEdge("Bucharest", "Urziceni");
    g.addEdge("Urziceni", "Hirsova");
    g.addEdge("Hirsova", "Eforie");
    g.addEdge("Urziceni", "Vaslui");
    g.addEdge("Vaslui", "Iasi");
    g.addEdge("Iasi", "Neamt");

    string StartC, EndC;
    cout << "Masukkan kota asal: ";
    cin >> StartC;
    cout << "Masukkan kota tujuan: ";
    cin >> EndC;

    g.findRouteBFS(StartC, EndC);

    return 0;
}
