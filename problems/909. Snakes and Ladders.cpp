class Board {
public:
    virtual void buildBoard() = 0;
    virtual int solve() const = 0;

protected:
    Board(const std::vector<std::vector<int>> &v) :
        board(v)
    {}

    const std::vector<std::vector<int>> board;
};

class SnakesAndLadders : public Board {
public:
    SnakesAndLadders(const std::vector<std::vector<int>> &v) :
        Board(v),
        board_size(v.size()),
        start(1),
        finish(board_size * board_size)
    {}

    void buildBoard() {
        int idx = 1;
        for (int i = board_size - 1, side = 1; i >= 0; i -= 1, side = !side) {
            if (side & 1) {
                for (int j = 0; j < board_size; j += 1, idx += 1) {
                    addEdge(idx, board[i][j]);
                }
            } else {
                for (int j = board_size - 1; j >= 0; j -= 1, idx += 1) {
                    addEdge(idx, board[i][j]);
                }
            }
        }
    }

    int solve() const {
        std::unordered_map<int, int> dist;
        std::queue<int> q;

        dist[start] = 0;
        q.push(start);

        while (!q.empty()) {
            const int i = q.front();
            q.pop();

            if (i == finish) {
                return dist[finish];
            }

            const int nxt_dist = dist[i] + 1;

            for (int j = i + 1; j <= std::min(finish, i + 6); j += 1) {
                const int nxt = getEdge(j);
                if (dist.count(nxt)) {
                    continue;
                }
                dist[nxt] = nxt_dist;
                q.push(nxt);
            }
        }

        return -1;
    }

private:
    void addEdge(const int source, const int destination) {
        assert(source > 0 and source <= board_size * board_size);
        if (destination == -1) {
            edges[source] = source;
        } else {
            edges[source] = destination;
        }
    }

    int getEdge(const int source) const {
        const auto i = edges.find(source);
        assert(i != edges.end());
        return i->second;
    }

    const int board_size;
    const int start;
    const int finish;

    std::unordered_map<int, int> edges;
};

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        Board* b = new SnakesAndLadders(board);
        b->buildBoard();
        return b->solve();
    }
};