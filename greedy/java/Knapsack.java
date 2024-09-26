import java.util.Scanner;

public class Knapsack {
	public void solve(int[] wt,int[] val,int W,int N) {
		int NEGATIVE_INFINITY=Integer.MIN_VALUE;
		int[][] m=new int[N+1][W+1];
		int[][] sol=new int[N+1][W+1];
		for (int i = 1; i < N; i++) {
			for (int j = 0; j < W; j++) {
				int m1=m[i-1][j];
				int m2=NEGATIVE_INFINITY;
				if(j>=wt[i]) 
					m2=m[i-1][j-wt[i]]+val[i];
				m[i][j]=Math.max(m1, m2);
				sol[i][j]=m2>m1?1:0;
				
		
		}
	}
int[]selected=new int[N+1];
for (int n = N, w =W;n>0;n--) {
	if (sol[n][w]!=0) {
		selected[n]=1;
		w=w-wt[n];
		
	}
	else {
		selected[n]=0;
		
	}}
	System.out.println("\nItems Selected: ");
	
for (int i = 1; i<N+1; i++) {
	if (selected[i]==1) 
		System.out.println(i+" ");
	System.out.println();
	
}
	
}
	public static void main(String[] args) {
		Scanner obj=new Scanner(System.in);
		System.out.println("knapsack Algorithm Qustion\n");
		Knapsack ks=new Knapsack();
		System.out.println("Enter number of element");
		int n=obj.nextInt();
		int[]wt=new int[n+1];
		int[] val=new int [n+1];
		System.out.println("\nEnter weight for "+n+" Elements");
		for (int i = 1; i <=n; i++) 
			val[i]=obj.nextInt();
		System.out.println("Enter kanapsack weight ");
		int W=obj.nextInt();
		ks.solve(wt, val, W, n);
		System.out.println("=======================================");
		System.out.println(" bhushan misal");
		
	}
}
