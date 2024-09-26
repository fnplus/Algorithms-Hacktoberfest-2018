import java.util.*;

public class Queue {
public static void main(String[] args)
{
Queue<String> queue = new LinkedList<String>();
queue.add("A");// Insert "A" in the queue
queue.add("B");// Insert "B" in the queue
queue.add("C");// Insert "C" in the queue
queue.add("D");// Insert "D" in the queue
// Prints the front of the queue ("A")
System.out.println("Front element is: " + queue.peek());
queue.remove();// removing the front element ("A")
queue.remove();// removing the front element ("B")

// Prints the front of the queue ("C")
System.out.println("Front element is: " + queue.peek());
// Returns the number of elements present in the queue
System.out.println("Queue size is " + queue.size());
// check if queue is empty
if (queue.isEmpty())
System.out.println("Queue is Empty");
else
System.out.println("Queue is not Empty");
}
	}
