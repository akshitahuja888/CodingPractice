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

//in merge sort we divide the array into two parts and then 
//compare each values into a new temp array and then copy them back to the original array..
void merge(int arr[],int n,int start,int end)
{
	int temp[n];

	int mid=start+(end-start)/2;

	int i=start;
	int j=mid+1;

	int k=0;

	while(i<=mid and j<=end)
	{
		if(arr[i]<=arr[j])
		{
			temp[k]=arr[i];
			i++;
			k++;
		}else{
			temp[k]=arr[j];
			j++;
			k++;
		}
	}

	while(i<=mid)
	{
		temp[k]=arr[i];
		i++;
		k++;
	}
	while(j<=end)
	{
		temp[k]=arr[j];
		j++;
		k++;
	}

	// for(int i=0;i<n;i++)
	// {
	// 	arr[i]=temp[i];
	// }

	//the above statements are incorrect as in mergeSort fn. at every stage start and end will change 
	int pos = 0;
	for(int x=start;x<=end;x++){
		arr[x] = temp[pos];
		pos++;
	}
}
void mergeSort(int arr[],int n,int start,int end)
{
	if(start==end)
	{
		return;
	}

	int mid=start+(end-start)/2;

	mergeSort(arr,n,start,mid);
	mergeSort(arr,n,mid+1,end);

	merge(arr,n,start,end);
}

//in quickSort we let a pivot element and then
//place all elemets smaller than pivot element on one side and greater on the other...
//https://www.youtube.com/watch?v=SLauY6PpjW4
void quickSort(int arr[],int low,int high){
	if(low>=high){
		return;
	}

	int mid = low + (high - low)/2;
	
	int left = low;
	int right = high;

	int pivot = arr[mid];

	while(left<=right){

		if(arr[left]<pivot){
			left++;
		}

		else if(arr[right]>pivot){
			right--;
		}

		else{
			swap(arr[left],arr[right]);
			left++;
			right--;
		}
	}
	quickSort(arr,low,right);
	quickSort(arr,left,high);
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
	mergeSort(arr,n,0,n-1);
	cout<<"Merge Sort....."<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	quickSort(arr,0,n-1);
	cout<<"Quick Sort....."<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	return 0;
}