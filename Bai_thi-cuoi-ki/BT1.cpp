#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <stack>
using namespace std;

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};
void importMN(const string& filePath, int& M, int& N, vector<vector<char> >& matrix) {
    ifstream file(filePath);
    file >> M >> N;
    matrix.resize(M, vector<char>(N));

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            file >> matrix[i][j];
        }
    }
    file.close();
}
int find(int x, int y, int M, int N, vector<vector<char> >& matrix) {
    stack<Point> s;
    s.push(Point(x, y));
    int area = 0;

    while (!s.empty()) {
        Point current = s.top();
        s.pop();
        x = current.x;
        y = current.y;

        if (x >= 0 && y >= 0 && x < M && y < N && matrix[x][y] == 'O') {
            matrix[x][y] = 'X';  // Mark the cell as visited
            area++;
            // Push neighboring cells to the stack
            s.push(Point(x + 1, y));
            s.push(Point(x - 1, y));
            s.push(Point(x, y + 1));
            s.push(Point(x, y - 1));
        }
    }

    return area;
}
void findLargestCleanableArea(int M, int N, vector<vector<char> >& matrix, vector<int> &startX, vector<int> &startY, int& maxArea) {
    maxArea = 0;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (matrix[i][j] == 'O') {
                int area = find(i, j, M, N, matrix);
                if (area > maxArea) {
                    startX.clear();
                    startY.clear();
                    maxArea = area;
                    startX.push_back(i);
                    startY.push_back(j);
                }else {if(area == maxArea){
                        startX.push_back(i);
                        startY.push_back(j);
                    }
                }
            }
        }
    }
}

void writeResultToFile(const string& filePath, int startX, int startY, int maxArea) {
    ofstream file(filePath);
    file << startX << " " << startY << " " << maxArea;
    file.close();
}
int main() {
    clock_t begin = clock();
    string inputFilePath = "/Users/thanhhuong/Desktop/CTDL/inpHB.txt";
    string outputFilePath = "outHB.txt";
    int M, N, maxArea, n;
    vector<vector<char> > matrix;
    importMN(inputFilePath, M, N, matrix);
    vector<int> startX, startY;
    findLargestCleanableArea(M, N, matrix, startX, startY, maxArea);
    if(maxArea > 0){
        int a = startX.size();
        srand(time(NULL));
        n = rand()%(a);
        }
    else {
        n=0;startX.push_back(0);startY.push_back(0);
        }
    writeResultToFile(outputFilePath, startX[n], startY[n], maxArea);
    clock_t end = clock(); //ghi lại thời gian lúc sau
    cout<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;
}