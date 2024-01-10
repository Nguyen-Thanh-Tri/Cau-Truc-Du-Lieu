#include <iostream>
#include <fstream>
using namespace std;
int main(){
    int N, am=0, duong=0;
   ifstream importFile("/Users/thanhhuong/Desktop/EXERCISE/Cấu trúc dữ liệu/Bài tập 12:11:2023/InpMax.txt"); // dán Path của InpMã.txt vào
if (!importFile.is_open()){
    cout <<"Dán Path vào"<< endl;
    exit(0);
}

importFile >> N;
int arr[N];
while (2>N || N>1000);
for (int i=0; i<=N; i++){
    importFile >> arr[i];
}
importFile.close();
for (int i=0; i < N; i++){
    if(arr[i] < 0 && arr[i] < am)
        am = arr[i];
        else if (arr[i] > 0 && arr[i] > duong)
        duong = arr[i];
    }
ofstream exportFile("OutMax.txt"); // tự tạo trong output
exportFile << am <<" "<< duong;
exportFile.close();
cout << " da ghi ket qua vao file OutMax.txt"<< endl;
}
