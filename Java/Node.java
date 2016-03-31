public class Node{
	private int data;
	private Node next;
	public Node(){}
	public Node(int data){
		this.data=data;
	}
	public void setData(int data){
		this.data=data;
	}
	public int getData(){
		return data;
	}
	public void setNext(Node next){
		this.next=next;
	}
	public Node getNext(){
		return this.next;
	}
	public int getLength(){
		Node currentNode=this;
		int length=0;
		while(currentNode!=null){
			length++;
			currentNode=currentNode.getNext();
		}
		return length;
	}
	public Node insertNode(Node headNode, Node nodeToInsert, int position){
		if(headNode==null)
			return nodeToInsert;
		int size=headNode.getLength();
		if(position>(size+1) || position<1){
			System.out.println("Invalid Position");
			return headNode;
		}
		if(position==1){
			nodeToInsert.setNext(headNode);
			return nodeToInsert;
		}
		else{
			int count=0;
			Node temp=headNode;
			while(count<(position-1)){
				count++;
				temp=temp.getNext();
			}
			nodeToInsert.setNext(temp.getNext());
			temp.setNext(nodeToInsert);
		}
		return headNode;
	}
	public Node deleteNode(Node headNode, int position){
		if(headNode==null)
			return headNode;
		else if(position>(headNode.getLength()) || position<1){
			System.out.println("Invalid Position");
		}
		else if(position==1){
			headNode=headNode.getNext();
		}
		else{
			Node temp=headNode;
			int count=0;
			while(count<position-1){
				count++;
				temp=temp.getNext();
			}
			Node toBeDeleted=temp.getNext();
			temp.setNext(toBeDeleted.getNext());
			toBeDeleted=null;
		}
		return headNode;
	}
}
