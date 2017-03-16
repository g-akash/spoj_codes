import java.util.*;
import java.lang.*;
import java.math.BigInteger;


class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
		BigInteger bi=new BigInteger("0");
		BigInteger b1=new BigInteger("1");
		int i=new Integer(0);
		for(i=0;i<1024;i++){
		bi = sc.nextBigInteger();
		if(bi.equals(b1))System.out.println("1");
		else{
		BigInteger b2=new BigInteger("2");
		bi=bi.multiply(b2);
		bi=bi.subtract(b2);

		System.out.println(bi);}
	}

		
	}
}