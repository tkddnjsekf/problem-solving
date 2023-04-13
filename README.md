# problem-solving
문제해결능력
#include <iostream>

#include <cstdlib>

#include <ctime>

#include <queue>

#include <utility>

using namespace std;

const int ROWS = 10; // 맵의 행 크기

const int COLS = 10; // 맵의 열 크기

class Map {

private:

    char map[ROWS][COLS];

    int start_x, start_y;

    int goal_x, goal_y;

public:

    Map() {

        srand(time(NULL));

        for (int i = 0; i < ROWS; i++) {

            for (int j = 0; j < COLS; j++) {

                map[i][j] = '.';

            }

        }

        for (int i = 0; i < 10; i++) {

            int x = rand() % ROWS;

            int y = rand() % COLS;

            map[x][y] = 'X';

        }

        do {

            start_x = rand() % ROWS;

            start_y = rand() % COLS;

        } while (map[start_x][start_y] != '.');

        map[start_x][start_y] = 'O';

        do {

            goal_x = rand() % ROWS;

            goal_y = rand() % COLS;

        } while (map[goal_x][goal_y] != '.');

        map[goal_x][goal_y] = 'P';

    }

    void print_map() {

        for (int i = 0; i < ROWS; i++) {

            for (int j = 0; j < COLS; j++) {

                cout << map[i][j] << ' ';

            }

            cout << endl;

        }

    }

    int bfs() {

        int dx[] = { -1, 0, 1, 0 };

        int dy[] = { 0, 1, 0, -1 };

        queue<pair<int, int>> q;

        int dist[ROWS][COLS] = { 0 };

        q.push({ start_x, start_y });

        dist[start_x][start_y] = 1;

        while (!q.empty()) {

            int x = q.front().first;

            int y = q.front().second;

            q.pop();

            for (int i = 0; i < 4; i++) {

                int nx = x + dx[i];

                int ny = y + dy[i];

                if (nx >= 0 && nx < ROWS && ny >= 0 && ny < COLS && map[nx][ny] != 'X' && dist[nx][ny] == 0) {

                    q.push({ nx, ny });

                    dist[nx][ny] = dist[x][y] + 1;

                    if (map[nx][ny] == 'P') {

                        int cx = nx;

                        int cy = ny;

                        while (map[cx][cy] != 'O') {

                            map[cx][cy] = '-';

                            for (int j = 0; j < 4; j++) {

                                int nx2 = cx + dx[j];

                                int ny2 = cy + dy[j];

                                if (nx2 >= 0 && nx2 < ROWS && ny2 >= 0 && ny2 < COLS && dist[nx2][ny2] == dist[cx][cy] - 1) {

                                    cx = nx2;

                                    cy = ny2;

                                    break;

                            }

                        }

                    }

                    return dist[nx][ny] - 1;

                }

            }

        }

    }

    return -1;

}

};

int main() {

Map game_map;

int shortest_path = game_map.bfs();

if (shortest_path > 0) {

    cout << "최단 거리: " << shortest_path << endl;

}

else {

    cout << "경로가 없습니다." << endl;

}

cout << "===== 맵 =====" << endl;

game_map.print_map();

return 0;

}
