import java.util.*;
import java.util.ArrayList;

public class lab2 {

    public static void main(String args[]) {
        
        //create knowledge base
        knowledgeBase kb = new knowledgeBase();
        Scanner reader = new Scanner(System.in);

        String clause;
        Clause c;
/*
        while (true) {
            System.out.println("enter new clause: ");
            clause = reader.nextLine();

            if(clause.equals("stop"))
                break;
            c = new Clause(clause);
            kb.addKnowledge(c);
        }
*/

        Clause clause1 = new Clause("+A+B");
        Clause clause2 = new Clause("+B+C");
        Clause clause3 = new Clause("-A-B");
        Clause clause4 = new Clause("-A-C");
        Clause clause5 = new Clause("-B-C");

        kb.addKnowledge(clause1);
        kb.addKnowledge(clause2);
        kb.addKnowledge(clause3);
        kb.addKnowledge(clause4);
        kb.addKnowledge(clause5);


        System.out.println("knowledge base before!");
        kb.printKnowledgeBase();
        kb.solve();

        System.out.println("knowledge base after!");
        kb.printKnowledgeBase();
        
        
        
    }
}
