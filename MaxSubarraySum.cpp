  
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
int main() {

	int n;
	cin>>n;
	int arr[n];

	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	MaxSubarraySum(n,arr);

	return 0;
}