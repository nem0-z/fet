package pred3;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.Random;

public class CollectionsAndRandomNumbers {
    public static void main(String[] args) {
        ArrayList<Integer> arr = new ArrayList<Integer>();

        arr.add(5); //push back
        arr.add(7); //push back
        arr.add(3); //push back
        arr.add(1, 4); //Ispred indeksa 1 ubacuje element 5
        //arr.clear(); //brise sve
        //arr.indexOf(4); //Logy

        Iterator<Integer> it = arr.iterator();
        while (it.hasNext()){
            System.out.println(it.next());
        } //A imaju i hasPrevious i previous metodi

        System.out.println(arr.indexOf(4)); //On radi na osnovu equals metoda logy tako da treba to paziti da je implementirano

        Double rez = 18.85; //Auto boxing
        double r = rez; //Auto unboxing

        int a = rez.intValue(); //int vrijednost od Double klase npr ako nam treba?

        String s = "3";
        Integer x = Integer.parseInt(s);
        System.out.println(x);


        //Random brojevi
        //Moze math.Random() ali bolje je koristiti klasu Random jer math.Random() ti vraca samo double izmedju 0,1 i tjt
        System.out.println();
        Random rnumbers = new Random();
        System.out.println(rnumbers.nextInt(5));
    }
}
