#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

void printMatrix(const vector<vector<char> >& matrix,int M, int N) {
    ofstream file("inpHB.txt");// co the dan PATH vao, Neu muon luu file tại vi tri cu the
    file << M <<" "<< N <<endl;
    for (const auto& row : matrix) {
        for (char cell : row) {
            file << cell << " ";
        }
        file << endl;
    }
}

void generateRandomMatrix(int M, int N, vector<vector<char> >& matrix) {
    // Khởi tạo seed cho hàm rand() dựa trên thời gian hiện tại
    srand(time(0));

    // Tạo ma trận với ký tự 'X' và 'O' ngẫu nhiên
    for (int i = 0; i < M; ++i) {
        vector<char> row;
        for (int j = 0; j < N; ++j) {
            char cell = (rand() % 2 == 0) ? 'X' : 'O';
            row.push_back(cell);
        }
        matrix.push_back(row);
    }
}

int main() {
    int M = 5000; // Số hàng
    int N = 4000; // Số cột

    vector<vector<char> > randomMatrix;
    generateRandomMatrix(M, N, randomMatrix);
    printMatrix(randomMatrix, M, N);
    cout<< endl<< "end";
    return 0;
}
