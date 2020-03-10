#include<iostream>
#include<vector>
#define size 1
#define vv vector<vector<int>>
#define iter for(int i=0;i<n;i++) for(int j=0;j<n;j++)

using namespace std;

void multiply(vv &A,vv &B,vv &C,int n)
{
    iter for(int k=0;k<n;k++) C[i][j]+=A[i][k]*B[k][j];
}

void sum(vv &A,vv &B,vv &C,int n)
{
    iter C[i][j]=A[i][j]+B[i][j];
}

void sub(vv &A,vv &B,vv &C,int n)
{
    iter C[i][j]=A[i][j]-B[i][j];
}

void Strassen(vv &A,vv &B,vv &C,int n)
{
    if(n<=size)
    {
        multiply(A,B,C,n);
        return;
    }
    else
    {
        int nN = n/2;
        vector<int> r(nN,0);
        vv a11(nN,r),a12(nN,r),a21(nN,r),a22(nN,r);
        vv b11(nN,r),b12(nN,r),b21(nN,r),b22(nN,r);
        vv c11(nN,r),c12(nN,r),c21(nN,r),c22(nN,r);
        vv p1(nN,r),p2(nN,r),p3(nN,r),p4(nN,r),p5(nN,r),p6(nN,r),p7(nN,r);
        vv r1(nN,r),r2(nN,r);
        for(int i=0;i<nN;i++)
        {
            for(int j=0;j<nN;j++)
                {
                    a11[i][j] = A[i][j];
                    a12[i][j] = A[i][j+nN];
                    a21[i][j] = A[i+nN][j];
                    a22[i][j] = A[i+nN][j+nN];
                    b11[i][j] = B[i][j];
                    b12[i][j] = B[i][j+nN];
                    b21[i][j] = B[i+nN][j];
                    b22[i][j] = B[i+nN][j+nN];
                }
        }
        //p1 = a11 * (b12 - b22)
        sub(b12,b22,r2,nN);
        Strassen(a11,r2,p1,nN);

        //p2 = a22 * (b21 - b11)
        sub(b21,b11,r2,nN);
        Strassen(a22,r2,p2,nN);

        //p3 = (a21 + a22) * b11
        sum(a21,a22,r1,nN);
        Strassen(r1,b11,p3,nN);

        //p4 = (a11 + a12) * b22
        sum(a11,a12,r1,nN);
        Strassen(r1,b22,p4,nN);

        //p5 = (a21 - a11) * (b11 + b12)
        sub(a21,a11,r1,nN);
        sum(b11,b12,r2,nN);
        Strassen(r1,r2,p5,nN);

        //p6 = (a12 - a22) * (b21 + b22)
        sub(a12,a22,r1,nN);
        sum(b21,b22,r2,nN);
        Strassen(r1,r2,p6,nN);

        //p7 = (a11 + a22) * (b11 + b22)
        sum(a11,a22,r1,nN);
        sum(b11,b22,r2,nN);
        Strassen(r1,r2,p7,nN);

        //c1
        sum(p6,p7,r1,nN);
        sum(r1,p2,r2,nN);
        sub(r2,p4,c11,nN);

        //c2
        sum(p1,p4,c12,nN);
        
        //c3
        sum(p2,p3,c21,nN);

        //c4
        sum(p5,p7,r1,nN);
        sum(r1,p1,r2,nN);
        sub(r2,p3,c22,nN);

        for(int i=0;i<nN;i++) for(int j=0;j<nN;j++)
        {
            C[i][j] = c11[i][j];
            C[i][j+nN] = c12[i][j];
            C[i+nN][j] = c21[i][j];
            C[i+nN][j+nN] = c22[i][j];
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> r(n,0);
    vv a(n,r),b(n,r),c(n,r);
    iter  cin >> a[i][j];
    iter  cin >> b[i][j];
    Strassen(a,b,c,n);
    for(int i=0;i<n;i++) 
    {
        for(int j=0;j<n;j++) cout << c[i][j] << " ";
        cout << endl;
    }
}