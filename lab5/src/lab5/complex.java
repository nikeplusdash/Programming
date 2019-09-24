package lab5;

class complex {
    private int real;
    private int imag;
    
    complex(){real=0;imag=0;}
    complex(int r,int i){real=r;imag=i;}
    void display(){System.out.printf("%d + %di\n",real,imag);}
    void add(int x,complex c){System.out.printf("%d + %di\n",c.real+x,c.imag);}
    void add(complex x,complex c){System.out.printf("%d + %di\n",c.real+x.real,c.imag+x.imag);}
}
