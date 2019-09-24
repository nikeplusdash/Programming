import java.util.Scanner;

public class Odd {
	public static void generate(){
        for(int i=1;i<101;i++){
            if(i%2!=0)
                System.out.println(i);
        }
    }
	
    public static void main(String[] args) {
        Odd.generate();
    }
    
}
