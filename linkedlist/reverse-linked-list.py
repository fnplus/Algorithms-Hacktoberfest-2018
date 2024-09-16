class Node:
	def __init__(self,data):
		self.data=data
		self.next=None

def reverse(head):
	prev=None
	curr=head

	while(curr is not None):
		temp=curr.next
		curr.next=prev
		prev=curr
		curr=temp
	return(prev)


def printNode(head):
	temp=head

	while(temp):
		print(temp.data,end=" ")
		temp=temp.next
	print("")

root=Node(1)
root.next=Node(2)
root.next.next=Node(3)
root.next.next.next=Node(4)
root.next.next.next.next=Node(5)

printNode(reverse(root))



