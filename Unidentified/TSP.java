/*Travelling Salesman Problem, Optimal Path
 * 
 * Name :- Ashish Doneriya
 * Scholar No. = 101112011
 */
import static java.lang.System.out;
import java.util.Scanner;
class Path{
	private int adj[][];
	private int optCost;
	private int optPath[];
	private int N;
	public Path(int N){
		this.N=N;
		adj=new int[N][N];
		optCost=0;
	}
	public void get(){
		Scanner kb=new Scanner(System.in);
		int i=0, j=0;
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				adj[i][j]=kb.nextInt();
			}
		}
	}
	public void showOptPath(){
		optPath=getPath();
		optCost=optPath[0];
		out.print("Path is ");
		for(int i=1;i<=N;i++)
			out.print((optPath[i]+1)+"\t");
		out.println(1);
		out.println("Optimal cost is "+optCost);
	}
	public void path(int ver[], int getPath[]){
		if(getPath[0]==0){
			getPath[0]=adj[ver[0]][0];
			return;
		}
		int split=getPath[0];
		int ver2D[][]=new int[split][split];
		int getPath2D[][]=new int[split][N+1];
		int i,j,k;
		//Copying values of ver into ver2D in all its Rows
		for(i=0; i<split;i++){
			ver2D[i][0]=ver[i+1];
			for(j=1,k=1; j<=split; j++,k++){
				if(ver2D[i][0]==ver[j]){
					k--;
					continue;
				}
				ver2D[i][k]=ver[j];
			}
		}
		//Copying values of getPath into getPath2D in all its Rows
		for(i=0;i<split;i++){
			for(j=0;j<=N;j++){
				getPath2D[i][j]=getPath[j];
			}
			getPath2D[i][0]=getPath2D[i][0]-1;
		}
		//Recursion
		for(i=0;i<split;i++){
			getPath2D[i][N-split+1]=ver[i+1];
			path(ver2D[i],getPath2D[i]);
			getPath2D[i][0] = getPath2D[i][0]+adj[ver[0]][ver2D[i][0]];
			
		}
		//Finding minimum optimal Path
		int min=getPath2D[0][0], index=0;
		
		for(i=0;i<split;i++){
			if(min>getPath2D[i][0]){
				min=getPath2D[i][0];
				index=i;
			}
		}
		for(i=0;i<=N;i++)
			getPath[i]=getPath2D[index][i];
		
	}
	public int [] getPath(){
		int ver[]=new int[N];
		int getPath[]=new int[N+1];
		for(int i=0;i<N;i++)
			ver[i]=i;
		getPath[0]=N-1;
		path(ver,getPath);
		return (getPath);
	}
}
class TSP{
	public static void main(String args[]){
		Scanner kb=new Scanner(System.in);
		out.print("Enter the number of vertices : ");
		Path tsp=new Path(kb.nextInt());
		out.println("Enter the adjacency matrix");
		tsp.get();
		tsp.showOptPath();
	}
}
