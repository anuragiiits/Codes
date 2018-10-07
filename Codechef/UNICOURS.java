/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args)
	{
	    Scanner sc=new Scanner (System.in);
	    
		int n=sc.nextInt();
		while(n-- > 0)
		{
		    int l=sc.nextInt();
		    int arr[]=new int[l];
		    arr[0]=sc.nextInt();
		    int max=arr[0];
		    for(int i=1;i<l;i++)
		    {
		        arr[i]=sc.nextInt();
		        if(arr[i]>max)
		        max=arr[i];
		    }
		    System.out.println(l-max);
		}
	}
}
