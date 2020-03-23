/*
Here there be Dragons
(IOI Training Camp, 2012)

The kingdom is falling into ruin. People live in fear. Dragons pillage, kill, and just generally cause as much havoc as they possibly can. The king has just sent out a royal decree:

To any man out there who is able to bring me the heads of K dragons, I shall bequeath a lordship–to him, his sons and his grandsons, till the end of time.
Having seen this royal decree, and knowing that you are capable of killing dragons thanks to your extensive medieval combat training, you set out on a quest to hunt down the evil creatures. Being a busy kind of guy, you would like to complete your quest quickly and kill K dragons through the shortest route.

The kingdom is arranged in a grid with R rows, numbered 0 to R-1, and C columns, numbered 0 to C-1 You start your quest at the top left corner of the grid, (0,0).

The total number of dragons in the kingdom is D, of which you have to kill K. Dragons are very territorial in nature, so each row of the grid contains at most one dragon. Also, since the kingdom is situated on a hill, you travel only downwards on the grid, though you may move left or right as you please.

You are told that no two dragons are on the same row of the grid. Also, no dragon is at position (0,0).

For example, suppose the grid has 5 rows and 5 columns with 3 dragons, of which you have to kill any 2. The three dragons are located at (1,4), (2,3) and (4,4), as shown below. In this case, your shortest route is to take 7 steps and kill the dragons in row 1 and row 2. Killing any other combination of 2 dragons takes 8 steps, so this is the minimum possible. Note that once you've killed K dragons, you don't incur any cost to return home. You just want to find how long it takes to do all the killing.
*/



#include <bits/stdc++.h>
using namespace std;

struct s
{
    int x,y;
};


int main() {
	// your code goes here
	int r,c,k,d;
	cin>>r>>c>>k>>d;
	s a[d];                       //to store coordinates of d dragons.
	for(int i=0;i<d;i++)
	{
	    int x1,y1;
	    cin>>x1>>y1;
	    a[i].x=x1;
	    a[i].y=y1;
	}
	
	for(int i=0;i<d-1;i++)
	{
	    for(int j=0;j<d-i-1;j++)
	    {
	        if(a[j].x>a[j+1].x)
	        {
	            s temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
	        }
	    }
	}
	
	
	int mindist[d][k];
	for(int i=0;i<d;i++)
	{
	    for(int j=0;j<k;j++)
	    {
	        mindist[i][j]=-1;
	    }
	}
	for(int j=0;j<k;j++)
	{
	    for(int i=0-j;i<d;i++)
	    {
	        if(j==0)
	        {
	            mindist[i][j]=a[i].x+a[i].y;
	        }
	        else
	        {
	            int minn=INT_MAX;
	            for(int k=j-1;k<i;k++)
	            {
	                int diff=abs(a[i].x-a[k].x)+abs(a[i].y-a[k].y);
	                minn=min(minn,mindist[k][j-1]+diff);
	            }
	            if(minn!=INT_MAX)
	            {
	                mindist[i][j]=minn;
	            }
	        }
	    }
	}
	
	int ans=INT_MAX;
	for(int i=0;i<d;i++)
	{
	    if(mindist[i][k-1]!=-1)
	    {
	        ans=min(ans,mindist[i][k-1]);
	    }
	}
	cout<<ans<<"\n";
	return 0;
}
