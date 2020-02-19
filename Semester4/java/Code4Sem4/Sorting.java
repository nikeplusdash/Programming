public class Sorting
{
    public Sorting()
    {
        final int array[] = { 666, 6, 9, 69, 999, 96, -69, -96 };
        System.out.print("\nBefore Sorting: ");
        for (final int i : array)
        System.out.print(i + " ");
        for (int i = array.length/2 - 1; i >= 0; i-- ) MaxHeapify(array,i );
        System.out.print("\nAfter Sorting: ");
        for (final int i : array)
            System.out.print(i + " ");
    }

    /**
     * Swapping of Array Elements
     * 
     * @param a an array parameter for a method
     * @param i one of the 2 indexes to be swapped
     * @param j other index 
     */
    public void Swap(final int a[], final int i, final int j)
    {
        final int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        return;
    }

    /**
     * Bubble Sort Algorithm
     *
     * @param a an array parameter for a method
     * @return null
     */
    public void BubbleSort(final int[] a)
    {
        final int len = a.length;
        for (int i = 0; i < len - 1; i++) {
            for (int j = 0; j < len - i - 1; j++) {
                if (a[j] > a[j + 1])
                    Swap(a, j + 1, j);
            }
        }
        return;
    }

    /**
     * Selection Sort Algorithm
     *
     * @param a an array parameter for a method
     * @return null
     */
    public void SelectionSort(final int[] a)
    {
        final int len = a.length;
        for(int i = 0;i < len-1;i++){
            int min = i;
            for(int j = i+1;j < len;j++){
                if(a[j] < a[min]) min = j;
            }
            if(i != min) Swap(a, i, min);
        }
        return;
    }

    /**
     * Insertion Sort Algorithm
     *
     * @param a an array parameter for a method
     * @return null
     */
    public void InsertionSort(final int[] a)
    {
        final int len = a.length;
        for(int i = 1;i < len;i++){
            int k = a[i],j;
            for(j = i-1;j > -1;j--){
                if(a[j] > k) a[j+1] = a[j];
            }
            a[j+1] = k;
        }
        return;
    }

    /**
     * Quick Sort Algorithm
     * 
     * @param a an array parameter for a method
     * @return null
     */
    public void QuickSort(final int[] a)
    {
        QuickSort(a,0,a.length-1);
    }

    public void QuickSort(final int[] a,int l,int r)
    {
        if(l >= r) return;
        int x = SetPivot(a,l,r);
        QuickSort(a,l,x-1);
        QuickSort(a,x+1,r);
        return;
    }

    public int SetPivot(int[] a,int l,int r)
    {
        int num = a[r],x = l;
        for (int i = l; i < r; i++) {
            if(a[i] > num) Swap(a, i, x++);
        }
        Swap(a, r, x);
        return x;
    }

    /**
     * Merge Sort Algorithm
     * 
     * @param a an array parameter for a method
     * @return null
     */
    public void MergeSort(int[] a)
    {
        MergeSort(a,0,a.length-1);
    }

    public void MergeSort(int[] a,int l,int r)
    {
        if(l >= r ) return;
        int m = (l+r)/2;
        MergeSort(a,l,m);
        MergeSort(a,m+1,r);
        Merge(a,l,m,r);
        return;
    }

    public void Merge(int[] a,int l,int m,int r)
    {
        int iL = m-l+1,iR = r-m;
        int[] aL,aR;
        aL = new int [iL];aR = new int [iR];
        for (int i = 0; i < iL; i++) {
            aL[i] = a[l+i];
        }
        for (int i = 0; i < iR; i++) {
            aR[i] = a[m+i+1];
        }
        int i=0,j=0,k=l;
        while(i<iL && j<iR)
        {
            if(aL[i] < aR[i]) a[k++] = aL[i++];
            else a[k++] = aR[j++];
        }
        while(i<iL) a[k++] = aL[i++];
        while(j<iR) a[k++] = aR[j++];
        return;
    }
    public void MaxHeapify(int[] a,int i)
    {
        int largest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;
        if(l < a.length && a[l] > a[largest])
            largest = l;
        if(r < a.length && a[r] > a[largest])
            largest = r;
        if(i != largest)
        {
            int temp = a[i];
            a[i] = a[largest];
            a[largest] = temp;
            MaxHeapify(a, largest);
        }
    }
}
