#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

// 303周赛 T3
class FoodRatings {
public:
    unordered_map<string,int> mp;
    unordered_map<string,map<int,set<string>>> cnt;
    unordered_map<string,string> lei;
    FoodRatings(vector<string>& f, vector<string>& c, vector<int>& r) {
        for(int i=0;i<f.size();i++){
            mp[f[i]]=r[i];
            cnt[c[i]][r[i]].insert(f[i]);
            lei[f[i]]=c[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        string le = lei[food];
        
        auto& it = cnt[le];
        it[mp[food]].erase(food);
        it[newRating].insert(food);
        mp[food]=newRating;
    }
    
    string highestRated(string cuisine) {
        auto& it = cnt[cuisine];
        for(auto itt=it.rbegin();itt!=it.rend();itt++){
            if(itt->second.size())
                return *itt->second.begin();
        }
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */