package lab9;

import java.util.*;

public class Menu2
{
	public static int compare(String s1, String s2){
        return s1.compareTo(s2);
    }

     public static String toggle(String s){
        char arr[] = new char[s.length()];
        
        for(int i=0; i<s.length(); i++){
            if(Character.isUpperCase(s.charAt(i))){
                arr[i] = Character.toLowerCase(s.charAt(i));
            }
            if(Character.isLowerCase(s.charAt(i))){
                arr[i] = Character.toUpperCase(s.charAt(i));
            }
        }
        
        return new String(arr);
    }


     public static boolean subof(String s1, String s2){
        return s1.contains(s2);
    }
    
    public static String replace(String s1, String s2){
        return s1.replace(s2, "Hello");
    }
    
	public static void main(String[] args)
	{
		Scanner scan=new Scanner(System.in);
		int a;

		do
		{
			System.out.println("1.Compare\n2.Toggle\n3.Substring\n4.If substring, replace");
			a=scan.nextInt();
                        scan.nextLine();
			String str1,str2;
			switch(a)
			{
				case 1:
				System.out.println("Enter string1");
				str1=scan.nextLine();
				System.out.println("Enter string2");
				str2=scan.nextLine();
				if(compare(str1,str2)<0)
					System.out.println("lesser");
				else if(compare(str1,str2)==0)
					System.out.println("equal");
				else if(compare(str1,str2)>0)
					System.out.println("greater");

				break;

				case 2:
				System.out.println("Enter string");
				str1=scan.nextLine();
				System.out.println(toggle(str1));
				break;

				case 3:
				System.out.println("Enter string");
				str1=scan.nextLine();
				System.out.println("Enter substring");
				str2=scan.nextLine();
				if(subof(str1,str2))
					System.out.println("Is a substring");
				else
					System.out.println("not a substring");
				break;

				case 4:
				System.out.println("Enter string");
				str1=scan.nextLine();
				System.out.println("Enter substring");
				str2=scan.nextLine();
				System.out.println(replace(str1,str2));
				break;

				case 5:
				break;

				default:
				System.out.println("Error");
			}
		}
		while(a!=5);
		scan.close();
	}
}