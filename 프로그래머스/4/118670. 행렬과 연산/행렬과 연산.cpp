#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
using namespace std;

deque<int> vq1,vq2;
deque<deque<int>> dqdq;
int r,c,start,last;


void Rotate()
{
    dqdq[start].push_front(vq1.front()); vq1.pop_front();
    vq2.push_front(dqdq[start].back()); dqdq[start].pop_back();
    dqdq[last].push_back(vq2.back());vq2.pop_back();
    vq1.push_back(dqdq[last].front());dqdq[last].pop_front();
}

void ShiftRow()
{
    vq1.push_front(vq1.back());vq1.pop_back();
    vq2.push_front(vq2.back());vq2.pop_back();
    start--;
    last--;
    if(start <0) start=r-1;
    if(last<0) last=r-1;
}

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations)
{
    start = 0;
    r = last = rc.size();
    c = rc[0].size();
    last--;
    
    for(int i=0;i<r;i++)
    {
        deque<int> q;
        for(int j=0;j<c;j++)
        {
            if(j==0) vq1.push_back(rc[i][j]);
            else if(j==c-1) vq2.push_back(rc[i][j]);
            else q.push_back(rc[i][j]);
        }
        dqdq.push_back(q);
    }
    
    for (auto iter = operations.begin(); iter < operations.end(); ++iter)
        {
            if(*iter=="Rotate") Rotate();
            else if(*iter=="ShiftRow") ShiftRow();
        }
    
    
    for(int i=0;i<r;i++)
    {
        if(start>=r)start=0;
        for(int j=0;j<c;j++)
        {
            if(j==0) rc[i][j] = vq1[i];
            else if(j==c-1) rc[i][j] = vq2[i];
            else rc[i][j] = dqdq[start][j-1];
        }
        start++;
    }
    
    return rc;
}
