import java.util.*;


interface base
{
    void add();
    void subtract();
}

interface base2
{
    void multi();
    void div();
}

class new1
{
    void disp()
    {
        System.out.println("This is New Class");
    }
}

class deriv extends new1 implements base,base2
{
    int a,b;
    Scanner sc=new Scanner(System.in);
    void input()
    {
    System.out.println("Enter The Values Of A & B:");
    a=sc.nextInt();
    b=sc.nextInt();
    }
    public void add()
    {
        int c=a+b;
        System.out.println("Addtion:"+c);
    }
    public void subtract()
    {
        int c=a-b;
        System.out.println("Subtraction:"+c);
    }
    public void div()
    {
        int c=a/b;
        System.out.println("Division:"+c);
    
    }
    public void multi()
    {
        int c=a*b;
        System.out.println("Multiplication:"+c);
    }
}
public class Main
{
	public static void main(String[] args) {
	    deriv d=new deriv();
	    d.input();
	    d.add();
	    d.subtract();
	    d.div();
	    d.multi();
	    d.disp();
	}
}