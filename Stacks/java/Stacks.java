import java.util.Scanner;

public class Stacks {
  private int a[];
  private int top;
  Stacks(){
    a = new int[5];
    top = -1;
  }
  public void push(int n){
    if(top<5-1) a[++top]=n;
    else System.out.println("Stack Overflow");
  }

  public void pop(){
    if(top!=-1) System.out.println(a[top--]);
  }

  public void display(){
    for(int i=top;i>=0;i--) System.out.println(a[i]);
  }

  public static void main(String args[]){
    Stacks s = new Stacks();
    s.push(6);
    s.push(9);
    s.push(69);
    s.push(69);
    s.push(69);
    s.display();
    s.pop();
    s.pop();
    s.push(100);
    s.push(1);
    s.push(0);
    s.push(55);
    s.display();
  }
}