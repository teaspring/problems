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

        int[] arr = new int[]{0, 3, 5};
        addTwoNumbers.ListNode h = p3;
        for(int i = 0; i < arr.length; i++){
            Assert.assertNotNull(h);
            Assert.assertEquals(arr[i], h.val);
            h = h.next;
        }
    }

    @Test
    public void edgeTest(){
        addTwoNumbers.ListNode p1 = game.new ListNode(9);
        p1.next = game.new ListNode(1);

        addTwoNumbers.ListNode p2 = game.new ListNode(7);
        p2.next = game.new ListNode(8);

        addTwoNumbers.ListNode p3 = game.addTwo(p1, p2);

        int[] arr = new int[]{6, 0, 1};
        addTwoNumbers.ListNode h = p3;
        for(int i = 0; i < arr.length; i++){
            Assert.assertNotNull(h);
            Assert.assertEquals(arr[i], h.val);
            h = h.next;
        }
    }

    @Test
    public void nullTest(){
        addTwoNumbers.ListNode p1 = game.new ListNode(9);
        p1.next = game.new ListNode(1);

        addTwoNumbers.ListNode p2 = null;

        addTwoNumbers.ListNode p3 = game.addTwo(p1, p2);

        int[] arr = new int[]{9, 1};
        addTwoNumbers.ListNode h = p3;
        for(int i = 0; i < arr.length; i++){
            Assert.assertNotNull(h);
            Assert.assertEquals(arr[i], h.val);
            h = h.next;
        }
    }

    @Test
    public void negativeTest(){
		/* now the addTwo() does not support negative valued node */
        addTwoNumbers.ListNode p1 = game.new ListNode(-5);

        addTwoNumbers.ListNode p2 = game.new ListNode(2);
        p2.next = game.new ListNode(1);

        addTwoNumbers.ListNode p3 = game.addTwo(p1, p2);

        int[] arr = new int[]{7};
        addTwoNumbers.ListNode h = p3;
        for(int i = 0; i < arr.length; i++){
            Assert.assertNotNull(h);
            Assert.assertEquals(arr[i], h.val);
            h = h.next;
        }
    }

    @After
    public void settleDown(){
        game = null;
    }
}
