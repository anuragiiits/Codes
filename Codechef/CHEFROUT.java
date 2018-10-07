import java.util.*;
class code
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner (System.in);
        int n=sc.nextInt();
        while((n--)>0){
            String s=sc.next();
            int l=s.length();
            int i=0;
            for(;i<l;i++){
                if(s.charAt(i)!='C')
                break;
            }
            for(;i<l;i++){
                if(s.charAt(i)!='E')
                break;
            }
            for(;i<l;i++){
                if(s.charAt(i)!='S')
                break;
            }
            if(i==l)
                System.out.println("yes");
            else
                System.out.println("no");
        }
    }
} 