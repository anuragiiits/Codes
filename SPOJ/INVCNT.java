import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
 
class Main
{
    static class Reader             //For faster Input
    {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;
 
        public Reader()
        {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }
 
        public int nextInt() throws IOException
        {
            int ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do
            {
                ret = ret * 10 + c - '0';
            }  while ((c = read()) >= '0' && c <= '9');
 
            if (neg)
                return -ret;
            return ret;
        }
 
        public long nextLong() throws IOException
        {
            long ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do
            {
                ret = ret * 10 + c - '0';
            }  while ((c = read()) >= '0' && c <= '9');
 
            if (neg)
                return -ret;
            return ret;
        }
 
 
        private void fillBuffer() throws IOException
        {
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }
 
        private byte read() throws IOException
        {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }
 
        public void close() throws IOException
        {
            if (din == null)
                return;
            din.close();
        }
    }
    static long merge(long arr[], int st, int end){
        int i=st, mid=(st+end)/2;
        int j=mid+1;
        int p=st;
        long temp[] = new long[end-st+1];
        long cnt=0;
        while(i<=mid & j<=end){
            if(arr[i]<=arr[j]){
                temp[p++ - st]=arr[i++];
            }
            else{
                temp[p++ - st]=arr[j++];
                cnt+=mid-i+1;
            }
        }
        while(i<=(mid)){
            temp[p++ - st]=arr[i++];
        }
        while(j<=end){
            temp[p++ - st]=arr[j++];
        }

        for(int z=0;z< (p-st); z++){
            arr[st+z]=temp[z];
        }
        return cnt;
    }
    static long mergeSort(long arr[], int st, int end){
        long cnt = 0;
        if(end > st){
            int mid = (st+end)/2;
            cnt = mergeSort(arr, st, mid);
            cnt += mergeSort(arr, mid+1, end);
            cnt += merge(arr, st, end);
        }
        return cnt;
    }
    public static void main(String[] args) throws IOException {
        Reader sc = new Reader();
        int st, end, n, t;
        long ans;
        t=sc.nextInt();
        while(t-- > 0){ 
            n=sc.nextInt();
            long arr[] = new long[n];
            for(int i=0;i<n;i++)
                arr[i] = sc.nextLong();

            st=0; end=n-1;
            ans = mergeSort(arr, st, end);
            System.out.println(ans);
        }    
    }
}
