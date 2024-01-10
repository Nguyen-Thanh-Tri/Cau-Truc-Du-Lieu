#include <iostream>
#include <fstream>
using namespace std;
int main(){
    int M, N;
   ifstream importFile("/Users/thanhhuong/Desktop/EXERCISE/Cấu trúc dữ liệu/Bài tập 12:11:2023/InpSortRow.txt"); // dán Path của InpMã.txt vào
if (!importFile.is_open()){
    cout <<"Dán Path vào"<< endl;
    exit(0);
}
importFile >> M >> N;
int arr[M][N];
for (int i = 0; i < M; i++){
    for(int j = 0; j < N; j++){
        importFile >> arr[i][j];
    }
}
importFile.close();
for (int k = 0; k < M; k++){
    for (int i = 0; i < N-1; i++){
        for(int j = i+1; j < N; j++)
            if(arr[k][i] < arr[k][j]){
                swap(arr[k][i],arr[k][j]);
            }
        }
    }
ofstream exportFile("OutSortRow.txt"); // tự tạo trong output
for (int i = 0; i < M; i ++) {
    for(int j = 0; j < N; j++){
            exportFile << arr[i][j] <<" ";
        }
    exportFile << endl;
    }
exportFile.close();
cout << " da ghi ket qua vao file OutSortRow.txt"<< endl;
}
