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

    public ArrayList<Literal> getLiterals() {
        return literals;
    }

    public boolean compare( Klause k) {

        for (int i = 0; i < literals.size(); i++) {
            boolean found = false;
            for (int j = 0; j < literals.size(); j++) {

                if (literals.get(i).getValue() == k.getLiterals().get(j).getValue()) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                return false;
            }
        }
        return true;
    }

    public void print() {
        for (int i = 0; i < literals.size(); i++) {
            System.out.println(literals.get(i).print());
        }
    }
}
