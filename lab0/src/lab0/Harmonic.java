package lab0;

public class Harmonic {
    public static float sum(int n){
        float sum=0f,rec=0.0f;
        for(int i=1;i<=n;i++){
            rec = 1.0f/i;
            sum+= rec;
        }
        return sum;
    }
}
