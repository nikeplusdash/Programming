import java.util.*;
class Type<T> {
    T obj;
    Type(T obj){this.obj=obj;}
    public void type(){
        System.out.println("Type: " + obj.getClass().getName());
    }   
}
public class Collections {
    public static void main(){
        ArrayList<Integer> x = new ArrayList<>();
        x.add(1);x.add(2);x.add(3);x.add(4);x.add(5);
        Integer i[] = new Integer[x.size()];
        x.toArray(i);
        for(int j:i){
            System.out.println(j+" ");    
        }
        Type<Integer> t1 = new Type<>(10);
        Type<String> t2 = new Type<>("10");
        System.out.println(t1.getClass().getName());
        t1.type();t2.type();
    }    
}