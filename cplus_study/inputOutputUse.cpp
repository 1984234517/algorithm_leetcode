#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int m,n;
    vector<vector<int>> nums;
    while(cin.get()!='\n'){
        cin>>m>>n;
        nums.push_back({m,n});
    }
    return 0;
}
