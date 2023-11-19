#include <bits/stdc++.h>
using namespace std;


int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
bool visited[9][6];
int64_t n, ans = 0;

void dfs(int x, int y, int step = 0) {
  if (step == n) {
    ans++;
    return;
  }
  visited[x][y] = true;
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx >= 0 && nx < 9 && ny >= 0 && ny < 6 && !visited[nx][ny]) {
      dfs(nx, ny, step + 1);
    }
  }
  visited[x][y] = false;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  for (int i = 1; i <= 53; i++) {
    n = i;
    ans = 0;
    dfs(0, 0);
    cout << ans << endl;
  }
}
