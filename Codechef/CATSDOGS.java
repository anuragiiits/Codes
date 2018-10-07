import java.util.*;
import java.io.*;
class problem {
	public static void main(String args[])throws IOException
	{
		Scanner sc=new Scanner(System.in);
		int test=sc.nextInt();
		long num1,num2,sum,total;
		boolean flag=true;
		while(test>0)
		{
			test--;
			num1=sc.nextLong();
			num2=sc.nextLong();
			total=sc.nextLong();
			sum=(num1+num2)*4;
			if(sum>=total)
			{
			if(total%4==0)
			{
				if(total==sum)
					System.out.println("yes");
				else if(total>=4*num2&&num1<=num2*2)
				{
					System.out.println("yes");
				}
				else if(total>=4*num2&&num1>num2*2&&(num1-num2*2)*4<=(total-(num2*4)))
					System.out.println("yes");
					
				else
					System.out.println("no");
			}
			else
				System.out.println("no");
			}
			else
				System.out.println("no");
		}
	}
}