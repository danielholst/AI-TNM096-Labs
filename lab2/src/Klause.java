import java.util.ArrayList;

public class Klause
{
    private ArrayList<Literal> literals;

    public Klause(String k) {
        literals = new ArrayList<Literal>();
        boolean isTrue;

        for ( int i = 0; i < k.length(); i += 2) {
            if (k.charAt(i) == '+') {
                isTrue = true;
            } else {
                isTrue = false;
            }

            literals.add(new Literal(k.charAt(i+1), isTrue));
        }
    }

    public void print() {
        for (int i = 0; i < literals.size(); i++) {
            System.out.println(literals.get(i).getLiteral());
        }
    }
}
