import java.util.ArrayList;

/**
 * Created by danielholst on 2016-04-29.
 */
public class Literal {

    private char value;
    private boolean isTrue;

    // Constructor
    public Literal(char v, boolean t) {
        value = v;
        isTrue = t;
    }

    // return value
    public char getValue() { return value; }

    // return if value is true
    public boolean getIsTrue() { return isTrue; }

    // check if two literals complement
    public boolean isComplement(Literal l) {

        if (value == l.getValue() && isTrue != l.getIsTrue())
            return true;
        else
            return false;
    }
}
