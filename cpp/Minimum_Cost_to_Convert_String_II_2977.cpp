class Solution {
public:

    static constexpr long long inf = 1e15;

    struct Trie {

        static inline int counter = 0;

        Trie* child[26];
        int id;

        Trie() {
            for (int i = 0; i < 26; i++) child[i] = nullptr;
            id = -1;
        }

        void insert(string& curStr) {
            Trie* cur = this;
            for (auto& curChar: curStr) {
                int idx = curChar - 'a';
                if (!(cur->child)[idx]) {
                    (cur->child)[idx] = new Trie();
                }
                cur = (cur->child)[idx];
            }
            if (cur->id == -1) {
                cur->id = counter++;
            }
        }

        Trie* getNode(string& curStr) {
            Trie* cur = this;
            for (auto& curChar: curStr) {
                int idx = curChar - 'a';
                if (!(cur->child)[idx]) return nullptr;
                cur = (cur->child)[idx];
            }
            return cur;
        }

        int getId(string& curStr) {
            Trie* cur = getNode(curStr);
            return (!cur ? -1 : cur->id);
        }

        ~Trie() {
            for (int i = 0; i < 26; i++) {
                if (child[i]) {
                    delete child[i];
                    child[i] = nullptr;
                }
            }
        }

    };

    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {

        Trie::counter = 0;
        Trie* root = new Trie();

        for (auto& strNode: original) {
            root->insert(strNode);
        }
        for (auto& strNode: changed) {
            root->insert(strNode);
        }

        vector <vector <long long>> edgeMatrix(Trie::counter, vector <long long> (Trie::counter, inf));
        for (int i = 0; i < Trie::counter; i++) {
            edgeMatrix[i][i] = 0;
        }
        for (int i = 0; i < original.size(); i++) {
            int u = root->getId(original[i]), v = root->getId(changed[i]);
            edgeMatrix[u][v] = min(edgeMatrix[u][v], static_cast<long long>(cost[i]));
        }
        for (int k = 0; k < Trie::counter; k++) {
            for (int i = 0; i < Trie::counter; i++) {
                if (edgeMatrix[i][k] == inf) continue;
                for (int j = 0; j < Trie::counter; j++) {
                    if (edgeMatrix[k][j] < inf) {
                        edgeMatrix[i][j] = min(edgeMatrix[i][j], edgeMatrix[i][k] + edgeMatrix[k][j]);
                    }
                }
            }
        }

        vector <long long> memTable(source.length(), inf);
        for (int i = source.length() - 1; i >= 0; i--) {
            long long ans = inf;
            if (source[i] == target[i]) {
                ans = min(ans, (i == source.length() - 1 ? 0LL : memTable[i + 1]));
            }
            Trie *curSrc = root, *curTar = root;
            for (int j = i; j < source.length(); j++) {
                int srcId = source[j] - 'a', tarId = target[j] - 'a';
                if (!(curSrc->child)[srcId] or !(curTar->child)[tarId]) break;
                curSrc = (curSrc->child)[srcId], curTar = (curTar->child)[tarId];
                if (curSrc->id != -1 and curTar->id != -1 and edgeMatrix[curSrc->id][curTar->id] != inf) {
                    long long next = (j == source.length() - 1 ? 0LL : memTable[j + 1]);
                    if (next != inf) {
                        ans = min(ans, edgeMatrix[curSrc->id][curTar->id] + next);
                    }
                }
            }
            memTable[i] = ans;
        }
        
        delete root;

        return (memTable[0] == inf ? -1LL : memTable[0]);

    }
};
