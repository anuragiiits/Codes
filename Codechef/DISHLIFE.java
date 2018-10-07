import java.util.*;
import java.io.*;
class codechef2
{
	public static void main(String args[])throws IOException
	{
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		while(t>0)
		{
			t--;
		    int n=sc.nextInt();
		    int k=sc.nextInt();
		    HashSet<Integer> map = new HashSet<Integer>();
			int i=1;
			int flag=-1;
			String s=sc.nextLine();
			int c=0;
			while(i<=n)
			{
				//String ch=sc.next();
				
				s=sc.nextLine();
				String s1[]=s.split("\\s+");
				//System.out.println(s1.length);
				int l=s1.length;
				
				if (flag==-1)
				{
					for (int j=0;j<l ;j++ ) 
					{
						int num=Integer.parseInt(s1[j]);
						if (map.contains(num)==false)
						{
							
							if(num>=1&&num<=k)
							{	
								c++;
								map.add(num);
							}
						}
						else
							continue;
						if (c==k)
						{
							
							flag=i<n?1:0;
							break;
						}
						
					}
				}
				i++;
			}
			if (flag==1)
				System.out.println("some");
			else if (flag==0) 
				System.out.println("all");
			else
				System.out.println("sad");

		}
	}
}