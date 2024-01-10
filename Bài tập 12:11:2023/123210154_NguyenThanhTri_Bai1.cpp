// Viết chương trình tính tổng các hợp số (số có ít nhất một ước khác 1 và chính nó – số
// KHÔNG phải là số nguyên tố) theo các yêu cầu sau:
// __ Thông báo nhập vào 2 số nguyên dương a và b (biết 2 ≤ a < b, nhập vào luôn đúng)
// __Xuất ra màn hình tổng các hợp số nằm trong khoảng (a,b) 
#include <iostream>
using namespace std;
int main(){
    int a,b, count = 0;
    cout <<"Nhap 2 so a và b: ";
    cin >> a >> b;
    for(int i = a;i <= b; i++){
        bool checker = false;
        for(int j = 2; j * j <= i; j++){
            if (i % j == 0){
            checker = true; break;
                }
            }
        
        if (checker){
                count += i;
        }
    }
cout <<"Tong cac hop so trong ("<< a <<","<< b <<") là: "<< count;
}