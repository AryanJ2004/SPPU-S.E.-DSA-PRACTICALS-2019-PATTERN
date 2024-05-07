import java.util.Arrays;
import java.util.*;
public class Sort
{
    public static void shell(int[] a)
    {
        int increment=a.length/2;
        while(increment>0)
        {
            for(int i=increment;i<a.length;i++)
            {
                int j=i;
                int temp=a[i];
                while(j>=increment &&a[j-increment]>temp)
                {
                    a[j]=a[j-increment];
                    j=j-increment;
                }
                a[j]=temp;
            }
            if(increment==2)
                increment=1;
            else
                increment*=(5.0/11);
        }
    }


    public static void main(String[] args)
    {
        Sort ob= new Sort();
        int n[]=new int[10];
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter 10 Elements:");
        for(int i=0;i<10;i++)
        {
            n[i]=sc.nextInt();
        }
        //int nums[]= {7,-5,3,2,1,0,45};
        System.out.println("Original Array:");
        System.out.println(Arrays.toString(n));
        ob.shell(n);
        System.out.println("Sorted Array:");
        System.out.println(Arrays.toString(n));
    }
}
