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
			if(compare(arr[i-1],arr[i]))
			{
				swap(arr[i],arr[i-1]);
			}else{
				break;
			}
		}
		divider++;
	}
}

void SelectionSort(int n,int arr[])
{
	int firstPos=0;

	while(firstPos<n-1)
	{
		for(int i=firstPos+1;i<n;i++)
		{
			if(arr[firstPos]>arr[i])
			{
				swap(arr[firstPos],arr[i]);
			}
		}
		firstPos++;
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
	cout<<endl;

	InsertionSort(n,arr);
	cout<<"InsertionSort...."<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	SelectionSort(n,arr);
	cout<<"SelectionSort...."<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	return 0;
}