import java.util.*;
import java.util.ArrayList;

public class lab2 {

    public static void main(String args[]) {
        
        //create knowledge base
        knowledgeBase kb = new knowledgeBase();
        Scanner reader = new Scanner(System.in);
        String klause;
        Klause k;

        while (true) {
            System.out.println("enter new klause: ");
            klause = reader.nextLine();

            if(klause.equals("stop"))
                break;
            k = new Klause(klause);
            kb.addKnowledge(k);
        }

        System.out.println("knowledge base before!");
        kb.printKnowledgeBase();
        kb.solve();

        /*
        Klause klause1 = new Klause("+A+B");
        Klause klause2 = new Klause("+D-A");

        kb.addKnowledge(klause1);
        kb.addKnowledge(klause2);
*/
        System.out.println("knowledge base after!");
        kb.printKnowledgeBase();
        
        
        
    }
}
