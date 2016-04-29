import java.util.ArrayList;

public class knowledgeBase
{
    private ArrayList<Klause> kb;
    public knowledgeBase()
    {
        kb = new ArrayList<Klause>();
        System.out.println("create knowledge base!");
    }

    public void addKnowledge(Klause k) {
        kb.add(k);
    }

    public void printKnowledgeBase()
    {
        //System.out.println("The knowledge base!");
        for (int i = 0; i < kb.size(); i++) {
            kb.get(i).print();
        }

    }

    public void solve() {

        Klause tempKlause;
        for (int j = 0; j < kb.size(); j++) {
            for (int i = j+1; i < kb.size(); i++) {

                kb.get(j).compare(kb.get(i));

               
            }
        }
    }

    public boolean KlauseExists(Klause k) {

        boolean isFound = false;
        for ( int i = 0; i < kb.size(); i++) {
            if (kb.get(i).compare(k))
                isFound = true;
        }

        return isFound;
    }
    
    
}
