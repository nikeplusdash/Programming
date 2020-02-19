class A {
    private int h;
    int i=3;
    int j;

    A() {
        h = 30;
        j = 20;
    }

    void showij() {
        System.out.println("i & j & h: " + i + " " + j + " " + h);
    }
}

class B extends A {
    static int i=60;
    int k;
    int j=5;

    B() {
        k = 30;
    }

    void showk() {
        System.out.println("k: " + k);
    }

    void sum() {
        System.out.println("i + j + k : " + (i + j + k ));
    }
}

class inheritance {
    public static void main(String args[]) {
        A superobj = new A();
        B obj = new B();
        A ref;
        ref = obj;
        ref.showij();
        superobj.showij();
        obj.showij();
        obj.showk();
        obj.sum();
        // System.out.println(A.i);
    }
}