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

public class Stack{
	public Node top;
	
	public Stack(){
		top=null;
	}
	
	public void push(int info){
		Node node =new Node(info,top);
		top=node;
	}
	
	public int pop(){
		if(top==null)
			return -1;
		int delNode=top.info;
		top=top.next;
		return delNode;
	}
	
	public boolean isEmpty(){
		if(top==null)
			return true;
		return false;
	}
}
