import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import java.util.List;
import java.util.ArrayList;

import org.junit.jupiter.api.Assertions;

class OrganicCompoundsTest {
    private OrganicCompounds game;

    @BeforeEach
    public void setUp(){
        game = new OrganicCompounds();
    }

    @Test
    @DisplayName("checkCompoundsValid() valid case")
    void checkCompoundsValid_valid() {
        // arrange
        List<String> compounds = new ArrayList<>();
        compounds.add("CH2(1)CH2(1)CH1(1)CH2");
        compounds.add("(1)         (1)   (1)");
        compounds.add("CH2         CH2   CH2");
        compounds.add("(1)         (1)   (1)");
        compounds.add("CH2(1)CH2(1)CH1(1)CH2");
        // act & assert
        Assertions.assertTrue(game.checkCompoundsValid(compounds));
    }

    @Test
    @DisplayName("checkCompoundsValid() invalid case")
    void checkCompoundsValid_invalid() {
        // arrange
        List<String> compounds = new ArrayList<>();
        compounds.add("CH3(1)CH1(1)CH2(1)CH1(1)CH3");
        compounds.add("(1)         (1)");
        compounds.add("CH3         CH1(1)CH1(1)CH3");
        compounds.add("            (1)");
        compounds.add("            CH3");
        // act & assert
        Assertions.assertFalse(game.checkCompoundsValid(compounds));
    }
}