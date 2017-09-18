//Jieyi Hu CS153 A1
//Aug 26 2013 Assignment01
//fishbomb

#include<iostream>

using namespace std;

int main()
{
	int pause;
	int times;
	cin>>times;
	/*cout<<"times are input"<<endl;*/
	int ***p;
	p=new int**[times];
	int *max;//max fish
	max=new int[times];
	int *y;//y coordinate for fish grid when max fish
	y=new int[times];
	int *x;//x coordinate for fish grid when max fish
	x=new int[times];
	for(int i=0;i<times;i++)
	{
		int width, height, power;
		cin>>width>>height>>power;
		//for coordinate(x,y,z)->(times,height,width)
		//i for loop of times , j for loop of height, k for loop for width
		/*cout<<"the "<<i<<" set of data of width, height and power, are input."<<endl;*/
		p[i]=new int*[height];
		for(int j=0;j<height;j++)
		{
			p[i][j]=new int[width];
			for(int k=0;k<width;k++)
			{
				cin>>p[i][j][k];
				/*cout<<"the value of ("<<i<<","<<j<<","<<k<<") is input"<<endl;*/
			}
			
		}
		//height-power+1 for possibilities on width
		//width-power+1 for possibilities on height
		//int(power/2) for the distance between the edge of the bombing area and the bombing center

		//setup pointer for sum of fish
		int **f;
		f=new int*[height-power+1];
		for(int l=0;l<height-power+1;l++)
		{
			f[l]=new int[width-power+1];
		}
		
		
		//calculate sum of fish
		for(int m=0;m<height-power+1;m++)
		{
			for(int n=0;n<width-power+1;n++)
			{
				f[m][n]=0;
				for(int r=0;r<power;r++)
				{
					for(int s=0;s<power;s++)
					{
						f[m][n]=f[m][n]+p[i][m+r][n+s];
					}
				}
				/*cout<<"("<<n+int(power/2)<<","<<m+int(power/2)<<")="<<f[m][n]<<endl;*/
				if(f[m][n]>=max[i]){max[i]=f[m][n];y[i]=m+int(power/2);x[i]=n+int(power/2);}
				else{}
			}
		}
	}
	for(int i=0;i<times;i++)
	{
		cout<<"#"<<i<<": ("<<x[i]<<", "<<y[i]<<") "<<max[i]<<endl;
	}
	cin>>pause;
	return 0;
	

}