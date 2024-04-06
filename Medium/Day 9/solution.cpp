// Write your code here
#include <bits/stdc++.h>

using namespace std;

const int MAX_NODES = 200 * 1000 + 11;

int parent[MAX_NODES];
int depth[MAX_NODES];
vector<int> adjacency[MAX_NODES];

// Depth-first search to compute depths and parent nodes
void dfs(int node, int parent_node = -1, int current_depth = 0) {
    depth[node] = current_depth;
    parent[node] = parent_node;
    
    for (auto adjacent_node : adjacency[node]) {
        if (adjacent_node != parent_node) {
            dfs(adjacent_node, node, current_depth + 1);
        }
    }
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin); // Input redirection for debugging purposes
#endif

    int num_nodes;
    scanf("%d", &num_nodes);

    // Reading edges and constructing the graph
    for (int i = 0; i < num_nodes - 1; ++i) {
        int node_x, node_y;
        scanf("%d %d", &node_x, &node_y);
        --node_x, --node_y; // 0-based indexing
        adjacency[node_x].push_back(node_y);
        adjacency[node_y].push_back(node_x); // Undirected graph
    }
    
    // Perform depth-first search to compute depths and parent nodes
    dfs(0);
    
    // Using a set to maintain nodes with depth greater than 2
    set<pair<int, int>> nodes_with_depth_gt_2;
    for (int i = 0; i < num_nodes; ++i) {
        if (depth[i] > 2) {
            nodes_with_depth_gt_2.insert(make_pair(-depth[i], i)); // Using negative depth for proper ordering
        }
    }
    
    // Counting the number of branches in the tree
    int branches_count = 0;
    while (!nodes_with_depth_gt_2.empty()) {
        int current_node = nodes_with_depth_gt_2.begin()->second;
        current_node = parent[current_node]; // Moving to parent node
        ++branches_count; // Incrementing the count of branches
        
        auto it = nodes_with_depth_gt_2.find(make_pair(-depth[current_node], current_node));
        if (it != nodes_with_depth_gt_2.end()) {
            nodes_with_depth_gt_2.erase(it);
        }
        
        // Removing nodes in the subtree rooted at current_node
        for (auto adjacent_node : adjacency[current_node]) {
            auto it = nodes_with_depth_gt_2.find(make_pair(-depth[adjacent_node], adjacent_node));
            if (it != nodes_with_depth_gt_2.end()) {
                nodes_with_depth_gt_2.erase(it);
            }
        }
    }
    
    printf("%d\n", branches_count); // Outputting the number of branches
}
