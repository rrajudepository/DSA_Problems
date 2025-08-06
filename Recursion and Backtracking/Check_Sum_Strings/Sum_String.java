import java.util.*;
class Sum_String{
	public static boolean check(String num , int l1, int l2, int l3)
	{
		String s1 = num.substring( l1, l1+l2 );
		String s2 = num.substring( l1+l2, l1+l2+l3 );
		int j = Integer.parseInt(s1)+ Integer.parseInt(s2);
		String s3 = "" + j;
		//String s3 = "" + Integer.parseInt(s1)+ Integer.parseInt(s2);
		int s3_len = s3.length();
		//System.out.println(s1+" "+s2+" "+s3+" "+l1+ " "+l2+" "+l3);
		if(s3_len>num.length()-l1-l2-l3)
		{
		//	System.out.println("H1");
			return false;
		}
		for(int i=0;i<4;i++)
		{
			if(num.length()>=(l1+l2+l3+s3_len) && s3.equals(num.substring(l1+l2+l3,l1+l2+l3+s3_len)))
		  {
		//	System.out.println("H2");
			if(l1+l2+l3+s3_len == num.length())
			{
		//		System.out.println("H3");
				return true;
			}
			return check(num, l1+l2, l3, s3_len );
		  }
		  else
		  {
		  	s3 = "0"+s3;
		  	s3_len++;
		  }
		}
		/*if(s3.equals(num.substring(l1+l2+l3,l1+l2+l3+s3_len)))
		{
		//	System.out.println("H2");
			if(l1+l2+l3+s3_len == num.length())
			{
		//		System.out.println("H3");
				return true;
			}
			return check(num, l1+l2, l3, s3_len );
		}*/
		//System.out.println("H4");
		return false;
	}
	public static boolean is_sum_string(String num)
	{
		int n = num.length();
		for(int i=1;i<n;i++)
			for(int j=1;i+j<n;j++)
				if(check(num,0, i,j))
				{
					return true;
				}

		return false;		

	}
	public static void main(String args[])
	{
		Scanner input = new Scanner(System.in);
		int t = input.nextInt();
		for(int i=0;i<t;i++)
		{
			String num = input.next();
			System.out.println(is_sum_string(num));
		}
	}
}