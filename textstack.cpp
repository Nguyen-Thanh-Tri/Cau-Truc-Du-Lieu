#include <iostream>
#define MAX 100
using namespace std;
struct stack {
    int top;
    int A[MAX];
};
typedef struct stack STACK;
//gán phần tử top của stack = -1 để khởi tạo
void init (STACK &s){
    s.top = -1;
}
//thêm giá trị vào ngăn xếp
void add(STACK &s, int x){
    s.top++;
    s.A[s.top] = x;
}
// lấy và xoá phần tử
int Pop(STACK &s){
    int x;
    x = s.A[s.top];
    s.top--;
    return x;
}
//nhập xuất mảng vào ngăn xếp
void input(STACK &s, int n){
    for(int i=0;i<n;i++){
        int x;
        cout<<"Nhập giá trị thứ"<<i<<endl;
        cin >>x;
        add(s,x);
    }
}
void output(STACK &s){
    for(int i=s.top;i>-1;i--){
        cout<<s.A[i];
    }
}
int main(){
    STACK s;
    int n; 
    cout<< "Nhập n;"<<endl;
    cin>>n;
    init(s);
    input(s,n);
    cout<<"Stack vừa nhập là"<<endl;
    output(s);
    cout<<"Lấy và xoá phần tử"<<endl;
    Pop(s);
    cout<<"Stack sau khi pop:"<<endl;
    output(s);
}