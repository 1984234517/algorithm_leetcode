#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//Skill用于表示技能
struct Skill {
	int damage; //技能伤害
	int mp;//耗蓝
};

int solution(int n,int MP,Skill skill[]){
  int res=0;
  vector<vector<int>> dp(n,vector<int>(MP+1));
  for(int i=0;i<n;i++){
    for(int j=0;j<=MP;j++){
      if(i==0){
        dp[i][j]=0;
        if(j>=skill[i].mp){
            dp[i][j]=skill[i].damage;
         }
      }else{
        dp[i][j]=dp[i-1][j];
        if(j>=skill[i].mp){
            dp[i][j]=max(dp[i][j],dp[i-1][j-skill[i].mp]+skill[i].damage);
         }
      }
    }
  }
  return dp[n-1][MP];
}


int main()
{
  Skill skill[21];

  skill[1].damage = 1;
  skill[1].mp = 22;

  skill[2].damage = 2;
  skill[2].mp = 43;

  skill[3].damage = 123;
  skill[3].mp = 214;

  skill[4].damage = 12;
  skill[4].mp = 2;

  skill[5].damage = 123;
  skill[5].mp = 432;

  skill[6].damage =21;
  skill[6].mp = 223;

  skill[7].damage = 22;
  skill[7].mp = 16;

  skill[8].damage = 77;
  skill[8].mp = 49;

  skill[9].damage = 34;
  skill[9].mp = 78;

  skill[10].damage = 34;
  skill[10].mp = 9;

  skill[11].damage = 43;
  skill[11].mp = 677;

  skill[12].damage = 21;
  skill[12].mp = 34;

  skill[13].damage = 23;
  skill[13].mp = 23;

  skill[14].damage = 12;
  skill[14].mp = 56;

  skill[15].damage = 332;
  skill[15].mp = 56;

  skill[16].damage = 21;
  skill[16].mp = 99;

  skill[17].damage = 123;
  skill[17].mp = 545;

  skill[18].damage = 389;
  skill[18].mp = 33;

  skill[19].damage = 12;
  skill[19].mp = 999;

  skill[20].damage = 23;
  skill[20].mp = 88;
  cout<<solution(20,1000,skill);
}