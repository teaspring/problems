/*
 * void flattenBT2LL.flatten(TreeNode root)
 * */

import java.util.ArrayList;
import java.util.Arrays;
import org.junit.*;
import org.junit.Assert;

public class flattenBT2LLUnitTest{
    private flattenBT2LL game;

    @Before
    public void setUp(){
        game = new flattenBT2LL();
    }

    @Test
    public void positiveTest_01(){
        flattenBT2LL.TreeNode root = constructBT();
        flattenBT2LL.TreeNode expected = constructFlattenLL();
        game.flatten(root);

        Assert.assertTrue(assertLL(expected, root));
    }

    private flattenBT2LL.TreeNode constructBT(){
        flattenBT2LL.TreeNode root = game.new TreeNode(1);

        root.left = game.new TreeNode(2);
        root.right = game.new TreeNode(3);

        root.left.left = game.new TreeNode(4);
        root.left.right = game.new TreeNode(5);
        root.right.right = game.new TreeNode(6);

        return root;
    }

    private flattenBT2LL.TreeNode constructFlattenLL(){
        int[] arr = new int[]{1, 2, 4, 5, 3, 6};
        flattenBT2LL.TreeNode head = null, p = null;
        for(int v : arr){
            if(p == null){
                head = game.new TreeNode(v);
                p = head;
            }else{
                p.right = game.new TreeNode(v);
                p = p.right;
            }
        }
        return head;
    }

    private boolean assertLL(flattenBT2LL.TreeNode head1, flattenBT2LL.TreeNode head2){
        if(head1 == null){
            Assert.assertNull(head2);
            return true;
        }

        flattenBT2LL.TreeNode p1 = head1, p2 = head2;
        do{
            Assert.assertEquals(p1.val, p2.val);
            Assert.assertNull(p1.left);
            Assert.assertNull(p2.left);

            p1 = p1.right;
            p2 = p2.right;
        }while(p1 != null && p2 != null);

        Assert.assertNull(p1);
        Assert.assertNull(p2);
        return true;
    }

    @After
    public void settleDown(){
        game = null;
    }
}
