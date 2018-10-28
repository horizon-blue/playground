// Xiaoyan Wang 09/28/2018
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Farm {
    int id;    // number of the farm
    int dist;  // distance to the farm

    Farm(int id, int dist) : id(id), dist(dist) {}
};

int max_dist = 0;
int bfs(int root, const vector<vector<Farm>> &farm_map);

int main() {
    int n, m;
    cin >> n >> m;

    // create a vector to stores the distance to the farm
    vector<vector<Farm>> farm_map(n);

    // read the farm informations
    int from, to, dist;
    char orientation;  // doesn't matter
    while(cin >> from >> to >> dist >> orientation) {
        farm_map[from - 1].push_back(Farm(to - 1, dist));
        farm_map[to - 1].push_back(Farm(from - 1, dist));
    }

    // start with an arbitrary node, do bfs
    int furest = bfs(0, farm_map);
    // start with furest, do bfs agai
    bfs(furest, farm_map);

    // output result
    cout << max_dist << endl;

    return 0;
}

// return the node with maximum depth and update max_dist at the same time
int bfs(int root, const vector<vector<Farm>> &farm_map) {
    max_dist        = 0;
    int farest_farm = root;
    vector<bool> visited(farm_map.size(), false);
    queue<Farm> to_visit;
    // first entry is the node to visit, second is the distance to root
    to_visit.push(Farm(root, 0));
    while(!to_visit.empty()) {
        Farm curr        = to_visit.front();
        visited[curr.id] = true;
        to_visit.pop();
        // go over its neighbour
        for(int i = 0; i < farm_map[curr.id].size(); ++i) {
            const Farm &other = farm_map[curr.id][i];
            if(!visited[other.id]) {
                int dist_to_root = curr.dist + other.dist;
                if(dist_to_root > max_dist) {
                    max_dist    = dist_to_root;
                    farest_farm = other.id;
                }
                to_visit.push(Farm(other.id, dist_to_root));
            }
        }
    }
    return farest_farm;
}
