/*
 * ListNode sortSLL.mergesort(ListNode)
 *
 * listNode sortSLL.insertionsort(ListNode)
 *
 * */

import org.junit.*;
import org.junit.Assert;

public class sortSLLUnitTest{
    private sortSLL game;

    @Before
    public void setUp(){
        game = new sortSLL();
    }

    @Test
    public void merge_positiveTest_1(){
        int[] arr = new int[]{10, 1, 3, 9, 7, 8, 4, 5, 2, 6};
        sortSLL.ListNode head = createSLL(arr);

        int[] expectedArr = new int[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        sortSLL.ListNode expected = createSLL(expectedArr);

        sortSLL.ListNode result_m = game.mergesort(head);
        assertSLL(expected, result_m);
    }

    @Test
    public void merge_positiveTest_2(){
        int[] arr = new int[]{10, 1, 3, 9, 7, 8, 4, 5, 2, 6, 11};
        sortSLL.ListNode head = createSLL(arr);

        int[] expectedArr = new int[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
        sortSLL.ListNode expected = createSLL(expectedArr);

        sortSLL.ListNode result_m = game.mergesort(head);
        assertSLL(expected, result_m);
    }

    @Test
    public void merge_negativeTest(){
        sortSLL.ListNode head = null;
        sortSLL.ListNode result_m = game.mergesort(head);

        Assert.assertNull(result_m);
    }

    @Test
    public void insertion_positiveTest_1(){
        int[] arr = new int[]{10, 1, 3, 9, 7, 8, 4, 5, 2, 6};
        sortSLL.ListNode head = createSLL(arr);

        int[] expectedArr = new int[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        sortSLL.ListNode expected = createSLL(expectedArr);

        sortSLL.ListNode result_i = game.insertionsort(head);
        assertSLL(expected, result_i);
    }

    @Test
    public void insertion_positiveTest_2(){
        int[] arr = new int[]{10, 1, 3, 9, 7, 8, 4, 5, 2, 6, 11};
        sortSLL.ListNode head = createSLL(arr);

        int[] expectedArr = new int[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
        sortSLL.ListNode expected = createSLL(expectedArr);

        sortSLL.ListNode result_i = game.insertionsort(head);
        assertSLL(expected, result_i);
    }

    @Test
    public void insertion_negativeTest(){
        sortSLL.ListNode head = null;
        sortSLL.ListNode result_i = game.insertionsort(head);

        Assert.assertNull(result_i);
    }

    private sortSLL.ListNode createSLL(int[] arr){
        sortSLL.ListNode head = null, h = null;
        for(int v : arr){
            if(head == null){
                head = game.new ListNode(v);
                h = head;
            }else{
                h.next = game.new ListNode(v);
                h = h.next;
            }
        }
        return head;
    }

    /*
     * to assert two SLL equals or not
     * */
    private boolean assertSLL(sortSLL.ListNode expected, sortSLL.ListNode result){
        sortSLL.ListNode h1 = expected, h2 = result;
        while(h1 != null || h2 != null){
            Assert.assertNotNull(h1);
            Assert.assertNotNull(h2);
            Assert.assertEquals(h1.val, h2.val);
            h1 = h1.next;
            h2 = h2.next;
        }
        return true;
    }

    @After
    public void settleDown(){
        game = null;
    }
}
