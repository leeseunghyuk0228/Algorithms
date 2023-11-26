#include <iostream>
#include <vector>
#define MAX(a,b) ((a>b)?a:b)

using namespace std;
int N,ans;
vector<int> dp;


int main(){
	ios_base::sync_with_stdio(false);
	int num;
	cin>>N;
	cin>>num;
	
	dp.push_back(num);
	ans = num;

	if(N>1)
	{
		for(int i=0;i<2;i++) // 0,1,2 dp 채우기
		{
			cin>>num;
			dp.push_back(num+dp[0]);
			ans = MAX(ans,dp[1+i]);
		}
		
		int idx=3;
		int realidx=3;
		int first = 1, end = 2;
		
		
		while(idx<=N)
		{
			for(int i=0;i<idx;i++) // idx 번 째 줄이니까 idx 만큼 입력받음
			{
				cin>>num;
				// idx 번째 줄의 첫번째
				if(i==0) dp.push_back(num + dp[first]);
				else if(i==idx-1) dp.push_back(num + dp[end]);
				else dp.push_back(MAX(num + dp[first+i], num + dp[first+i-1]));
				
			    ans = MAX(ans, dp[realidx]);
				realidx++;
			}
			end = realidx - 1;
			first = end - idx + 1;
			idx++;
		}
		
	}
	cout<<ans;
	return 0;
}