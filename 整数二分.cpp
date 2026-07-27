#include<iostream>
using namespace std;
const int N=1e6+10;
int q[N];
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>q[i];
    }
    while(k--){
        int x;
        cin>>x;
        int l=0,r=n-1;
        while(l<r){
            int mid=(l+r)/2;
            if(q[mid]<x) l=mid+1;//在取左边的值的时候 q[mid]不能=x 如果等于x的左边可能还有相同的值没有取到 但是此时l=mid了
            else r=mid;
        }
        if(x!=q[l])cout<<"-1 -1"<<endl;
        else {
            cout<<l<<" ";
            int l=0,r=n-1;
            while(l<r){
                int mid=(l+r+1)/2;
                if(q[mid]>x)r=mid-1;//同理 取右边的值的时候q[mid]!=x,不用<的原因：用<则改变l，那么下一行r就会取=，如果用了<= 那就是把else和if 换了个位置
                else l=mid;
            }
            cout<<r<<endl;
    }
    }
    return 0;
}
