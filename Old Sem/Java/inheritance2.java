class inheritance2 {
    public static void main(String args[]){
        BoxWeight n = new BoxWeight(10, 10, 10, 1);
        System.out.println(n.volume());
    }
}

class Box {
    double width;
    double height;
    double depth;
    
    //Make a clone of an object
    Box(Box ob){
        this.width = ob.width;
        this.height = ob.height;
        this.depth = ob.depth;
    }

    //Box Constructor to initialise
    Box(double width,double height,double depth){
        this.width = width;
        this.height = height;
        this.depth = depth;
    }

    //Empty Constructor
    Box(){
        this.width = -1;
        this.height = -1;
        this.depth = -1;
    }

    //Constructor for cube
    Box (double s) {
        this.width = this.height = this.depth = s;
    }

    double volume () {
        return this.width*this.height*this.depth;
    }
}

// Extension to include weight of the box
class BoxWeight extends Box {
    double weight;

    BoxWeight(double w,double h,double d,double m){
        this.width = w;
        this.height = h;
        this.depth = d;
        this.weight = m;
    }
}