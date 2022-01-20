class Solution {
public:
  struct Node {
    vector<int> children;
  };
  
  vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
    vector<int> result(n - 1, 0); // Will store final result
    vector<Node> tree(n + 1); // Will contain the tree
    vector<bool> visited(n + 1, false); // Useful for dfs later
    
    // Build the tree
    for (auto& edge : edges) {
      tree[edge[0]].children.push_back(edge[1]);
      tree[edge[1]].children.push_back(edge[0]);
    }
    
    // Find diameters for all subtrees rooted at node 1 (arbitrary choice for root)
    computeDiameters(tree, 1, visited, result);
    return result;
  }
  
  struct SubTreeInfo {
    int depth;
    int diameter;
    SubTreeInfo(int depth, int diameter) : depth(depth), diameter(diameter) {}
  };
  
  vector<SubTreeInfo> computeDiameters(vector<Node>& tree, int nodeIdx, vector<bool>& visited,
                                       vector<int>& result) {
    auto& node = tree[nodeIdx];
    vector<SubTreeInfo> subTrees; // Will store information for subtrees rooted at node
    subTrees.push_back(SubTreeInfo(0, 0)); // First subtree just contains this node itself
    visited[nodeIdx] = true; // Mark this node as visited
    
    for (int childIdx : node.children) {
      if (visited[childIdx]) continue; // Ignore if this child is actually the parent
      int numSubTrees = subTrees.size(); // Number of subtrees built so far
      
      // Get subtrees for this child
      auto childSubTrees = computeDiameters(tree, childIdx, visited, result);
      for (auto& childSubTree : childSubTrees) {
        // Combine the child subtree with every subtree known so far
        for (int i = 0; i < numSubTrees; ++i) {
          auto& subTree = subTrees[i];
          SubTreeInfo newSubTree(-1, -1);
          
          // Compute the depth of this new subtree
          newSubTree.depth = max(subTree.depth, 1 + childSubTree.depth);
          // Compute the diameter of this new subtree (Note: child can have bigger diameter too)
          newSubTree.diameter = max(max(subTree.diameter, 1 + childSubTree.depth + 
                                        subTree.depth), childSubTree.diameter);
          
          // Populate the results array
          result[newSubTree.diameter - 1]++;
          // Record this subtree for future use by parent of the current node
          subTrees.push_back(newSubTree);
        }
      }
    }
    return subTrees;
  }
};