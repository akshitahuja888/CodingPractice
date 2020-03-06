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


bool compare(int a,int b)
{
	return a>b;
}
void BubbleSort(int n,int arr[])
{
	int counter =1;

	while(counter<n)
	{
		for(int i=0;i<n-counter;i++)
		{
			if(compare(arr[i],arr[i+1]))
			{
				swap(arr[i],arr[i+1]);
			}
		}
		counter++;
	}
}

void InsertionSort(int n,int arr[])
{
	int divider=1;

	while(divider<n)
	{
		for(int i=divider;i>0;i--)
		{
			if(compare(arr[i],arr[i-1]))
			{
				swap(arr[i],arr[i-1]);
			}else{
				break;
			}
		}
		divider++;
	}
}
int main(){

	int n;
	cin>>n;
	int arr[n];

	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	BubbleSort(n,arr);
	cout<<"BubbleSort....."<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	InsertionSort(n,arr);
	cout<<"InsertionSort...."<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}