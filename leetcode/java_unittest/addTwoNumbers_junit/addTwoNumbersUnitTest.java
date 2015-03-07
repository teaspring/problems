/*
 * ListNode addTwoNumbers.addTwo(ListNode head1, ListNode head2)
 * */

import org.junit.*;
import org.junit.Assert;


public class addTwoNumbersUnitTest{
    private addTwoNumbers game;

    @Before
    public void setUp(){
        game = new addTwoNumbers();
    }

    @Test
    public void positiveTest(){
        addTwoNumbers.ListNode p1 = game.new ListNode(8);
        p1.next = game.new ListNode(9);

        addTwoNumbers.ListNode p2 = game.new ListNode(2);
        p2.next = game.new ListNode(3);
        p2.next.next = game.new ListNode(4);

        addTwoNumbers.ListNode p3 = game.addTwo(p1, p2);
        addTwoNumbers.ListNode h = p3;

        int[] arr = new int[]{0, 3, 5};
        for(int i = 0; h != null && i < arr.length; i++){
            Assert.assertEquals(arr[i], h.val);
            h = h.next;
        }
    }

    @Test
    public void edgeTest(){
    }

    @After
    public void settleDown(){
        game = null;
    }
}
