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

int jump(vector<int>& nums) {
    
    int start = 0;
    int end = 0;
    
    int cnt = 0;
    
    int nextEnd = 0;
    
    for (int i = 0 ; i < nums.size()-1; i++) {
        cout << "----------------------------" << endl;
        
        cout << "i:" << i << " start:"<< start << " end:" << end << " cnt:" << cnt << " nextEnd:" << nextEnd << endl;
        
        if (i > end) {  // 如果没有覆盖到终点元素，会返回错误码
            return -1;
        }
        
        nextEnd = max(nextEnd, i + nums[i]);  // 取[start,,end] 区间能跳到最远的位置
        if (i == end) {
            start = (i==0)?i:i+1 ;  // 不是在开头，就应该是从它的下一个开始
            end = nextEnd;
            cnt++;
        }
        cout << "i:" << i << " start:"<< start << " end:" << end << " cnt:" << cnt << " nextEnd:" << nextEnd << endl;
    }
    
    return cnt;
}

int main(int argc,char * argv[]){
    vector<int> vec{0};
    cout << jump(vec);
}