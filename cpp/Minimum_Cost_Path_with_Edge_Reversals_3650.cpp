class Solution {
public:

    static constexpr int unVisited = 1e8;

    int minCost(int n, vector<vector<int>>& edges) {
        vector <vector <pair <int, int>>> edgeList(n), nodeDepd(n);
        for (auto& edge: edges) {
            edgeList[edge[0]].push_back(make_pair(edge[1], edge[2]));
            nodeDepd[edge[1]].push_back(make_pair(edge[0], edge[2]));
        }
        vector <int> nodeLens(n, unVisited);
        nodeLens[0] = 0;
        priority_queue <tuple <int, int>, vector <tuple<int, int>>, greater<tuple<int, int>>> nextEle;
        nextEle.emplace(0, 0);
        while (!nextEle.empty()) {
            auto [curDist, curNode] = nextEle.top();
            nextEle.pop();
            if (nodeLens[curNode] < curDist) continue;
            for (auto&[node, edgeLen]: edgeList[curNode]) {
                if (nodeLens[node] > curDist + edgeLen) {
                    nodeLens[node] = curDist + edgeLen;
                    nextEle.emplace(nodeLens[node], node);
                }
            }
            for (auto&[node, edgeLen]: nodeDepd[curNode]) {
                if (nodeLens[node] > curDist + 2 * edgeLen) {
                    nodeLens[node] = curDist + 2 * edgeLen;
                    nextEle.emplace(nodeLens[node], node);
                }
            }
        }
        return nodeLens.back() == unVisited ? -1 : nodeLens.back();
    }
};
