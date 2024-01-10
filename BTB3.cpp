#include <iostream>
using namespace std;
#define H 100
#define C 100
void Nhapmang(int arr[][C], int &m,int &n);
void Xuatmang(int arr[][C], int m, int n);
void daomang(int arr[][C],int m,int n);
void Nhapmang(int arr[][C], int &m,int &n){
    for(int i=0; i<m;i++){
        for(int j=0;j<n;j++){
            cout << "hàng"<< i <<"cột"<< j<<":";
            cin >>arr[i][j];
            cout << endl;
        }
    }
}
void Xuatmang(int arr[][C], int m, int n){
    for(int i=0;i<m;i++){
        for(int j=0;i<n;j++){
            cout<<arr[i][j];
        }
    }

}
void daomang(int arr[][C],int m,int n) {
    for (int i = 0; i < m / 2; i++) {
        for (int j = 0; j < n; j++) {
            // Hoán đổi các phần tử ở hàng i và hàng ROWS - 1 - i
            int temp = arr[i][j];
            arr[i][j] = arr[m - 1 - i][j];
            arr[m - 1 - i][j] = temp;
        }
    }
}
int main(){
    int M,N;
    do {
        cout << "Nhập M:";
        cin >> M;
        cout << endl;
    }while(M<0 || M > 10);
    do {
        cout << "Nhập N:";
        cin >> N;
        cout << endl;
    }while(N<0 || N > 10);

int arr[M][N];
Nhapmang(arr,M,N);
Xuatmang(arr,M,N);
}