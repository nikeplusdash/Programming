package Company;

import java.util.Scanner;

interface Sales {
    void sales(int a);
}

class Software implements Sales {
    Scanner in = new Scanner(System.in);
    private final String software;
    private final String os;
    Software(){
        software = in.nextLine();
        os = in.nextLine();
    }
    @Override
    public void sales(int a){
        System.out.println("Total Sales: "+a*90);
    }
}

class Hardware implements Sales {
    Scanner in = new Scanner(System.in);
    private final String item;
    private final String category;
    Hardware(){
        item = in.nextLine();
        category = in.nextLine();
    }
    @Override
    public void sales(int a){
        System.out.println("Total Sales: "+a*90);
    }
}

public class Company {
    public static void main(){
        Scanner in = new Scanner(System.in);
        Software s = new Software();
        Hardware h = new Hardware();
        Integer a;
        a = in.nextInt();
        s.sales(a);
        h.sales(a);
    }
}
