/* package codechef; // don't place package name! */

import java.util.*;

/* Name of the class has to be "Main" only if the class is public. */

class Answer {   
    
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        long a,b,m;
        while(t-- >0){
            a=sc.nextLong();
            b=sc.nextLong();
            m=sc.nextLong();
            System.out.println(b/m-(a-1)/m);    
        }
    }
}