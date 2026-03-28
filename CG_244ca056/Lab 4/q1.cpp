#include<bits/stdc++.h> 

using namespace std;

int r;
void display()
{   
   int x, y;
   x = 0;
   y = r;
   int p = 1 - r;
   while(x <= y)
   {
   	  cout << x << " , " << y << " | ";
   	  cout << -x << " , " << y  << " | ";
   	  cout << x << " , " << -y << " | ";
   	  cout << -x << " , " << -y  << " | ";
   	  cout << y << " , " << x << " | ";
	  cout << -y << " , " << x << " | ";
	  cout << y << " , " << -x << " | ";
	  cout << -y << " , " << -x << " | ";
	  cout << endl;
   	if(p < 0)
   	{
   		p = p + 3 + 2 * x;
   		x = x + 1;
   	}
   	else
   	{
   		p = p + 1 + 2 * (x - y);
   		x += 1;
   		y -= 1;
   	}
   }
}   

int main(int argc, char** argv) {    
    cout <<"Enter the radius of the circle :";
    cin >> r;	 	
    display();

    return 0;
}
