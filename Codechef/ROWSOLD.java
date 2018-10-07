import java.util.*;
class codechef3
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		while(t>0)
		{
			t--;
			String s=sc.next();
			int i,j,l=s.length();
			long sum=0;
			for (i=0;i<l;i++ ) 
			{
				if (s.charAt(i)=='1') 
					break;
			}
			int c=1;
			for (j=i+1;j<l;j++) 
			{
				if (s.charAt(j)=='1')
					c++;
				else
					sum+=c;
				if (j>0&&s.charAt(j)=='0'&&s.charAt(j-1)=='1') 
					sum+=c;
			}
			System.out.println(sum);
		}
	}
}