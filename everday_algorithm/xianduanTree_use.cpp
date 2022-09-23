#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
const int N = 1000;



vector<int> a = {1, 3, 5, 7, 9, 11};
int size = 6;
vector<int> tree(N);

// 线段树
void buidTree(vector<int>& Tree,vector<int>& nums,int node,int s,int e){
    if(s==e){
        Tree[node]=nums[s];
        return ;
    }
    int m = s+(e-s)/2;
    int leftNode = 2*node;
    int rightNode = 2*node+1;
    buidTree(Tree,nums,leftNode,s,m);
    buidTree(Tree,nums,rightNode,m+1,e);
    Tree[node] = Tree[leftNode]+Tree[rightNode];
}

// 单点更新
void update(vector<int>& Tree,vector<int>& nums,int node,int s,int e,int index,int val){
    if(s==e){
        Tree[node]=val;
        nums[index]=val;
        return ;
    }
    int m = s+(e-s)/2;
    int leftNode = 2*node;
    int rightNode = 2*node+1;
    if(index>=s && index<=m){
        update(Tree,nums,leftNode,s,m,index,val);
    }else{
        update(Tree,nums,rightNode,m+1,e,index,val);
    }
    Tree[node] = Tree[leftNode]+Tree[rightNode];
}

// 区间查询
int query(vector<int>& Tree,vector<int>& nums,int node,int s,int e,int L,int R){
    if(L>e || R<s){
        return 0;
    }else if(s==e || (L<=s && e<=R)){
        return Tree[node];
    }
    int m = s+(e-s)/2;
    int leftNode = 2*node;
    int rightNode = 2*node+1;
    return query(Tree,nums,leftNode,s,m,L,R)+query(Tree,nums,rightNode,m+1,e,L,R);
}

 int main(int argc, char const *argv[])
 {
     //从根节点(即节点0)开始建树,建树范围为a[0]~a[size-1]
    buidTree(tree, a, 1, 0, size-1);

    for(int i = 0; i <= 14; i ++)
        printf("tree[%d] = %d\n", i, tree[i]);
    printf("\n");    

    //把a[x]改成6
    update(tree, a, 1, 0, size-1, 4, 6); 

    for(int i = 1; i <= 14; i ++)
        printf("tree[%d] = %d\n", i, tree[i]);
    printf("\n");

    //求区间[2,5]的和
    int ans = query(tree, a, 1, 0, size-1, 2, 5);
    printf("ans = %d", ans); 

     return 0;
 }
 