  
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <stack>
#include <iomanip>
#include <set>
#include <map>

using namespace std;
	
void MaxSubarraySum(int n,int arr[])
{
	int MaxSum=INT_MIN;

	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			int abhiKaSum=0;
			for(int k=i;k<=j;k++)
			{
				cout<<arr[k]<<" ";
				abhiKaSum+=arr[k];
			}
			cout<<"Sum = "<<abhiKaSum;
			cout<<endl;

			if(abhiKaSum>MaxSum)
			{
				MaxSum=abhiKaSum;
			}
		}
	}
	cout<<"Maximum Sum = "<<MaxSum<<endl;

}

int KadensAlgo(int n,int arr[])
{

	int maxsum=arr[0];
	int currsum=arr[0];

	for(int i=1;i<n;i++)
	{
		currsum=max(currsum+arr[i],arr[i]);

		maxsum=max(maxsum,currsum);
	}

	return maxsum;
}

void MaxSubarraySum2(int n,int arr[])
{
	int max = INT_MIN;

	for(int i = 0;i<n;i++){

		int sum = 0;

		for(int j=i;j<n;j++){
			sum+=arr[j];

			if(max<sum){
				max = sum;
			}
		}

	}

	cout<<"Max subarray value is "<<max<<endl;
}
int main() {

	int n;
	cin>>n;
	int arr[n];

	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	MaxSubarraySum(n,arr);
	int ans=KadensAlgo(n,arr);
	cout<<ans<<endl;
	MaxSubarraySum2(n,arr);
	return 0;
}