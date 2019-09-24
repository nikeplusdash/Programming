public class Combi {
	public static void main(String args[]){
		int a[],size=Integer.parseInt(args[0]);
		a = new int[size];
		for(int i=0;i<size;i++)	a[i]=i+1;
		/*
		for(int p:a)
			for(int q:a)
				for(int r:a)
					for(int s:a)
						System.out.println(p+""+q+""+r+""+s);
		*/			
		for(int p:a)
			for(int q:a)
				for(int r:a)
					for(int s:a)
						if(p!=q&&p!=r&&p!=s&&q!=r&&q!=s&&r!=s)
							System.out.println(p+""+q+""+r+""+s);
	}
}