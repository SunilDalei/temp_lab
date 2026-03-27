#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cout<<"enter the value of leaky rate\n";
	cin>>n;
	int bsize;
	cout<<"enter the size of bucket"<<endl;
	cin>>bsize;
	vector<int>bucket(bsize);
	cout<<"enter the values of packets\n";
	for(int i=0; i<bsize; i++)
	{
		cin>>bucket[i];
	}
	int x = n;
	int i=0;
	while(i<bsize)
	{
		if(i<bsize && n-bucket[i]>=0)
		{
			while(i<bsize && n-bucket[i]>=0)
			{
				cout<<"frame "<<bucket[i]<<" will flow "<<endl;
				n -= bucket[i];
				i++;
			}
		}
		else
		{
			cout<<"won't flow in this iteration"<<endl;
			n = x;
		}
		
	}
	return 0;
}
