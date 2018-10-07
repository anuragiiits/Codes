import java.util.*;
class codechef1
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		String s1[]=new String[4];
		String s2[]=new String[4];
		while (n>0) {
				n--;
				HashSet<String> map = new HashSet<String>();
		        map.add(sc.next());
		        map.add(sc.next());
		        map.add(sc.next());
		        map.add(sc.next());
		        int c=0;
		   		for (int j=0; j<4;j++ ) {
		   			if (map.contains(sc.next()))
		            c++;
		   		}
		        if (c>=2)
		        	System.out.println("similar");
		        else
		        	System.out.println("dissimilar");

		   
		}
	}
}