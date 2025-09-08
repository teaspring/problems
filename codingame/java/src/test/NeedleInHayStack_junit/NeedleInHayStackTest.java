import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import java.util.List;
import java.util.ArrayList;

import org.junit.jupiter.api.Assertions;

class NeedleInHayStackTest {
    private NeedleInHayStack game;

    @BeforeEach
    public void setUp(){
        game = new NeedleInHayStack();
    }

    @Test
    @DisplayName("findNeedleInHayStack(), Short stack")
    void findNeedleInHayStack_short() {
        // arrange
        String msg = "aaaaddaaabbbbbc";
        // act & assert
        Assertions.assertEquals("8 14", game.findNeedleInHayStack(msg, "a-c"));
        Assertions.assertEquals("8 14", game.findNeedleInHayStack(msg, "c, a,b "));
        Assertions.assertEquals("3 4", game.findNeedleInHayStack(msg, "d, a"));
        Assertions.assertEquals("5 14", game.findNeedleInHayStack(msg, "d, b-c, a"));
        Assertions.assertEquals("5 14", game.findNeedleInHayStack(msg, "a-d"));
    }
}