/* The solution of "Given a number n, find the number just greater than n using same digits as that of n." */
import java.io.*;
import java.util.*;

class same_digit{
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int a[] = {0,0,0,0,0,0,0,0,0,0};
		if(n>9){
			int last = n%10;
			n/=10;
			int prev = last;
			while(n>0){
				int d=n%10;
				a[d]++;
				if(d<prev){
					if(n/10 == 0)
						n=last;
					else
						n=(n/10)*10+last;
					break;
				}
				prev = d;
				n/=10;
			}
			if(n==0){
				System.out.println("Not Possible");
			}
			else{
				for (int i=0; i<10; i++) {
					while (a[i]>0) {
						n=n*10+i;
						a[i]--;
					}
				}
				System.out.println(n);
			}
		}
		else
			System.out.println("Not possible");	
	}
}