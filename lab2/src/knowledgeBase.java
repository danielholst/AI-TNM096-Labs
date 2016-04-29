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
        for (int i = 0; i < kb.size(); i++) {
            kb.get(i).print();
        }

    }
    
    
}
