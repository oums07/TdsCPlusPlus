#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSumBruteForce(const vector<int>& nums,int target){
for(int i=0;i<nums.size();i++){
    for(int j=i+1;j<nums.size();j++){
        if(nums[i]+nums[j]==target){
            return {i,j};
        }
    }
}
return {};
}
vector<int> twoSumOptimal(const vector<int>& nums, int target){
    unordered_map<int,int> Map;
    for(int i=0;i<nums.size();i++){
        int complement= target- nums[i];
        if(Map.find(complement)!=Map.end()){
            return {Map[complement],i};
        }
        Map[nums[i]] = i;
    }
 return {};
}

int main(){
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> indiceBruteForce = twoSumBruteForce(nums, target);
    cout<<"Brute Force Solution : ["<<indiceBruteForce[0]<<","<<indiceBruteForce[1]<<"]"<<endl;
    vector<int> indiceOptimal = twoSumOptimal(nums, target);
    cout<<"Optimal Solution : ["<<indiceOptimal[0]<<","<<indiceOptimal[1]<<"]"<<endl;
    return 0;
}