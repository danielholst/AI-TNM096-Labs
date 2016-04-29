import java.util.ArrayList;

/**
 * Created by danielholst on 2016-04-29.
 */
public class Literal {

    private char value;
    private boolean isTrue;

    public Literal(char v, boolean t) {
        value = v;
        isTrue = t;
    }

    public String print() {
        if(isTrue)
            return ("+" + value);
        else
            return ("-" + value);
    }

    public char getValue() { return value; }

    public boolean getIsTrue() { return isTrue; }



}
