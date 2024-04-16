package sample;
import java.util.*;
class new1
{
	int []a=new int [10];
	Scanner s=new Scanner(System.in);
	public void get()
	{
		System.out.println("Enter The Numbers:");
		for(int  i=0;i<a.length;i++)
			a[i]=s.nextInt();
	}
	public void disp()
	{
		for(int num:a)
			System.out.println(num);
	}
}

public class sample {

	public static void main(String[] args) {
		new1 p=new new1();
		p.get();
		p.disp();
		
		
		
	}

}