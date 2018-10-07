import java.util.*;
import java.math.*;
class chef
{
	public static void main(String args[])
	{
	Scanner sc=new Scanner(System.in);
	int t=sc.nextInt();
    while(--t >=0)
	{
		int n=sc.nextInt();
		int s=4;
		    System.out.print("1 ");
		if(n>=2)
		{
		    
		    System.out.print("2 ");
		}
		if(n>=3)
		    System.out.print("4 ");
		while(n-- >=4)
		{
            s+=3;
            
         System.out.print(s+" ");   
		}
		System.out.println();
	}
	}
}