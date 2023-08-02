//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    // Initialize a queue to perform BFS
    queue<pair<int, int>> q;

    // Create a matrix to store the minimum distance from (0, 0) to each cell
    vector<vector<int>> distance(N, vector<int>(M, INT_MAX));

    // Enqueue the starting cell (0, 0) into the queue and set its distance to 0
    q.push({0, 0});
    distance[0][0] = 0;

    // Perform BFS to find the shortest path
    while (!q.empty()) {
        // Get the current cell from the front of the queue
        pair<int, int> current = q.front();
        q.pop();

        // Check neighboring cells in all possible directions
        for (const vector<int>& dir : directions) {
            int nx = current.first + dir[0];
            int ny = current.second + dir[1];

            // If the neighboring cell is within the matrix bounds and contains a 1
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && A[nx][ny] == 1) {
                // If the new distance is smaller than the previously recorded distance
                if (distance[nx][ny] > distance[current.first][current.second] + 1) {
                    // Update the minimum distance and enqueue the neighboring cell
                    distance[nx][ny] = distance[current.first][current.second] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    // Return the minimum distance to the target cell (X, Y) if reachable, otherwise return -1
    return distance[X][Y] == INT_MAX ? -1 : distance[X][Y];
}
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends