#include <stdbool.h>
#include <string.h>

bool dfs(char** board, int m, int n, int r, int c, char* word, int index) {
    // Found the complete word
    if (word[index] == '\0') {
        return true;
    }

    // Boundary check and letter matching check
    if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != word[index]) {
        return false;
    }

    // Temporarily mark the cell as visited
    char temp = board[r][c];
    board[r][c] = '#';

    // Explore 4 directions: down, up, right, left
    bool found = dfs(board, m, n, r + 1, c, word, index + 1) ||
                 dfs(board, m, n, r - 1, c, word, index + 1) ||
                 dfs(board, m, n, r, c + 1, word, index + 1) ||
                 dfs(board, m, n, r, c - 1, word, index + 1);

    // Backtrack (restore original character)
    board[r][c] = temp;

    return found;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    int m = boardSize;
    int n = boardColSize[0];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == word[0]) {
                if (dfs(board, m, n, i, j, word, 0)) {
                    return true;
                }
            }
        }
    }

    return false;
}