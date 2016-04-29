import java.util.ArrayList;

public class knowledgeBase
{
    private ArrayList<Clause> kb;

    // Constructor
    public knowledgeBase()
    {
        kb = new ArrayList<Clause>();
        System.out.println("create knowledge base!");
    }

    // Add fact to knowledge base
    public void addKnowledge(Clause k) {
        kb.add(k);
    }

    // print the entire knowledge base
    public void printKnowledgeBase()
    {
        //System.out.println("The knowledge base!");
        for (int i = 0; i < kb.size(); i++) {
            kb.get(i).print();
        }

    }

    // solve the resolution if possible
    public void solve() {

        Clause tempClause;
        int j = 0;
        while (j != kb.size()) {
            for (int i = j+1; i < kb.size(); i++) {

                tempClause = kb.get(j).solveClause(kb.get(i));
                System.out.println("solving");
                kb.get(i).print();
                kb.get(j).print();
                if (tempClause != null && !ClauseExists(tempClause)) {

                    addKnowledge(tempClause);

                    System.out.println("add new clause");
                    tempClause.print();
                    j = -1;
                    break;
                }

            }

            j++;
        }
    }

    // check if Clause already exists in knowledge base
    public boolean ClauseExists(Clause k) {


        for ( int i = 0; i < kb.size(); i++) {
            if (kb.get(i).compare(k))
                return true;
        }

        return false;
    }
}
