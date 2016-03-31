package DataStructure;
class Node{
	
	public int info;
	public Node next;
	
	public Node(){
		info=0;
		next=null;
	}
	
	public Node(int info, Node next){
		this.info=info;
		this.next=next;
	}
	
}
public class Queue{
	
	public Node front,rear;
	
	public Queue(){
		front=rear=null;
	}
	
	public void addFront(int info){
		if (front==null&&rear==null){
			front=new Node(info,front);
			rear=front;
			return;
		}
		front=new Node(info,front);
	}
	
	public void addRear(int info){
		if (front==null&&rear==null){
			front=new Node(info,front);
			rear=front;
			return;
		}
		rear.next=new Node(info,null);
		rear=rear.next;
	}
	
	public int delFront(){
		if (front==null&&rear==null)
			return -1;
		int delInfo=front.info;
		front=front.next;
		if(front==null)
			rear=null;
		return delInfo;
	}
	
	public int delRear(){
		int temp;
		if (front==null&&rear==null)
			return -1;
		if (front==rear){
			temp=front.info;
			front=rear=null;
			return temp;
		}
		Node prev=front,delNode=front;
		while(delNode.next!=null){
			prev=delNode;
			delNode=delNode.next;
		}
		temp=delNode.info;
		prev.next=null;
		rear=prev;
		return temp;
	}
	
	public boolean isEmpty(){
		if(front==null&&rear==null)
			return true;
		return false;
	}
	
}
