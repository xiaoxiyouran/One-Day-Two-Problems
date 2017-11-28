//
//  main.cpp
//  20171128tmp
//
//  Created by Cookie on 2017/11/28.
//  Copyright © 2017年 Cookie. All rights reserved.
//

#include<iostream>
#include <vector>
#include <cmath>
using namespace std;

void print_vec(vector<int>& nums){
    for( auto each : nums )
        cout <<each << " ";
    cout << endl;
}

void print_(const int num){
    for(int i=0; i< num;i++ )
        cout << "\t";
    for(int i=0; i< num;i++ )
        cout << "-";
}
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        permute(nums, 0, ret);
        return ret;
    }

    void permute(vector<int>& nums, int idx, vector<vector<int>>& ret) {
        static int loop = 0;            // loop variable to see the loop hierarchy
        print_(loop);
        cout << ":"<<loop <<" idx: " <<idx << endl;
        if (idx == nums.size() - 1) {
            print_(loop);
            cout << "程序的结果: " <<endl;
            print_(loop);
            print_vec(nums);

            ret.push_back(nums);
            return;
        }

        for (int i = idx; i < nums.size(); ++i) {
            if(!loop)           // loop is 0，最上层的递归，输出空行，好分析
                cout << endl;
            print_(loop);
            cout <<"迭代前 i:" << i <<" idx: " <<idx << endl;
            swap(nums[idx], nums[i]);
            print_(loop);
            cout << "swap(nums[" << idx<<"],nums[" << i <<"]);" <<" ";
            print_vec(nums);

            loop++;
            permute(nums, idx + 1, ret);
            loop--;

            print_(loop);
            cout <<"迭代后 i:" << i <<" idx: " <<idx << endl;

            swap(nums[i], nums[idx]);
            print_(loop);
            cout << "swap(nums[" << idx<<"],nums[" << i <<"]);" <<" ";
            print_vec(nums);
        }
    }
};

int main(int argc,char * argv[]){
    vector<int> vec{1,2,3};
    auto res = Solution().permute(vec);
    for(auto one:res ){
        for(auto o :one)
            cout << o << " ";
        cout << endl;
    }
}