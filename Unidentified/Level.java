import static java.lang.System.out;
import java.util.Scanner;
class Path{
	private int adj[][];
	private int optCost;
	private int optPath[];
	private int N;
	private int L;
	private int levels[];
	private int cost[][][];
	public Path(int L, int N){
		this.L=L;
		this.N=N;
		adj=new int[N][N];
		levels=new int[L];
		optCost=0;
	}
	public void getAdj(){
		Scanner kb=new Scanner(System.in);
		int i=0, j=0;
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				adj[i][j]=kb.nextInt();
			}
		}
	}
	public void getNodes(){
		Scanner kb=new Scanner(System.in);
		for(int i=0;i<L;i++){
			out.println("Enter the number of nodes in Level "+(i+1)+" : ");
			levels[i]=kb.nextInt();
		}
	}
	public void makecost(){
		int i,j,k;
		cost=new int[L][][];
		for(int i=0,k=0;i<L;i++){
			cost[i]=new int[levels[i]][2];
			for(j=0;j<levels[i];j++){
				cost[i][j][0]=k++;
			}
		}
	}
	public void fillcost(){
		int i,j,k;
		for(i=0;i<L;i++){
			
		}
	}
	
	public void showOptPath(){}
}
class Level{
	public static void main(String args[]){
		int l,n;
		Scanner kb=new Scanner(System.in);
		out.print("Enter the number of levels and vertices: ");
		l=kb.nextInt();
		n=kb.nextInt();
		Path level=new Path(l,n);
		out.println("Enter the adjacency matrix");
		level.getNodes();
		level.getAdj();
		level.showOptPath();
	}
}
