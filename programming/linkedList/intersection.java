class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class intersection {

    public static Node intersect(Node head1, Node head2) {
        Node p1 = head1;
        Node p2 = head2;

        Node dummy = new Node(0);
        Node tail = dummy;

        while (p1 != null && p2 != null) {

            if (p1.data == p2.data) {
                tail.next = new Node(p1.data);
                tail = tail.next;

                p1 = p1.next;
                p2 = p2.next;
            } 
            else if (p1.data < p2.data) {
                p1 = p1.next;
            } 
            else {
                p2 = p2.next;
            }
        }

        return dummy.next;
    }

    public static void printList(Node head) {
        Node temp = head;

        while (temp != null) {
            System.out.print(temp.data);

            if (temp.next != null) {
                System.out.print(" -> ");
            }

            temp = temp.next;
        }

        System.out.println();
    }

    public static void main(String[] args) {

        Node head1 = new Node(1);
        head1.next = new Node(2);
        head1.next.next = new Node(2);
        head1.next.next.next = new Node(3);
        head1.next.next.next.next = new Node(4);

        Node head2 = new Node(2);
        head2.next = new Node(2);
        head2.next.next = new Node(2);
        head2.next.next.next = new Node(4);

        Node result = intersect(head1, head2);

        printList(result);
    }
}