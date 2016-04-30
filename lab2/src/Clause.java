import java.util.ArrayList;

public class Clause
{
    private ArrayList<Literal> literals;

    // Constructor
    public Clause(String k) {
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

    // return list of literals
    public ArrayList<Literal> getLiterals() {
        return literals;
    }

    // solve if resolution is posssible for clause
    public Clause solveClause(Clause c) {

        char toRemove = '-';
        boolean foundToRemove = false;

        if (checkSame(c)) return null;

        for (int i = 0; i < literals.size(); i++) {
            for (int j = 0; j < c.literals.size(); j++) {
                if (literals.get(i).isComplement(c.getLiterals().get(j))) {
                        toRemove = literals.get(i).getValue();
                        foundToRemove = true;
                    }
            }
        }

        String res = "";
        if (foundToRemove) {
            for (int i = 0; i < literals.size(); i++) {
                if (literals.get(i).getValue() != toRemove) {
                    if (literals.get(i).getIsTrue())
                        res += "+" + literals.get(i).getValue();
                    else
                        res += "-" + literals.get(i).getValue();
                }
            }
            for (int i = 0; i < c.getLiterals().size(); i++) {
                if ((c.getLiterals().get(i).getValue() != toRemove) &&
                        ((res.equals("")) || (c.getLiterals().get(i).getValue() !=res.charAt(1)))) {
                    if (c.getLiterals().get(i).getIsTrue())
                        res += "+" + c.getLiterals().get(i).getValue();
                    else
                        res += "-" + c.getLiterals().get(i).getValue();
                }
            }
            return new Clause(res);
        }
        return null;
    }

    // check if two clauses has same values
    public boolean checkSame(Clause c) {

        if (literals.size() != c.getLiterals().size()) return false;

        int nrOfComp = 0;
        for (int i = 0; i < literals.size(); i++) {
            for (int j = 0; j < c.getLiterals().size(); j++) {

                if (literals.get(i).isComplement(c.getLiterals().get(j))) {
                    nrOfComp++;
                }
            }
        }
        //System.out.println("size = " + literals.size() + " , nrOfComp = " + nrOfComp);

        if (nrOfComp == literals.size()) return true;
        else return false;
    }

    // compare two clauses and return if the same
    public boolean compare( Clause c) {

        for (int i = 0; i < literals.size(); i++) {
            boolean found = false;
            for (int j = 0; j < c.literals.size(); j++) {

                if ((literals.get(i).getValue() == c.getLiterals().get(j).getValue())
                    && (literals.get(i).getIsTrue() == c.getLiterals().get(j).getIsTrue())){
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

    // print the clause
    public void print() {
        String clause = "[";
        for (int i = 0; i < literals.size(); i++) {

            if(literals.get(i).getIsTrue())
                clause += "+" + literals.get(i).getValue();
            else
                clause += "-" + literals.get(i).getValue();

            if (i != literals.size() -1)
                clause += ", ";
        }
        clause += "]";
        System.out.println(clause);

    }
}
