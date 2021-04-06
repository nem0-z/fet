package pred3;

public class Main {

    public static void main(String[] args) {
        Manager boss = new Manager("Meskica", 1000);
        boss.setBonus(500);
        //System.out.println(boss.getWage());
        Manager sameBoss = new Manager("Meskica", 1000);
        if (boss.equals(sameBoss))
            System.out.println("Same people");
        else
            System.out.println("Different people");

        Employee e;
        e = boss; //Svaki boss je ujedno i radnik tako da ovo moze
        System.out.println(e.getWage()); //Ovo ce biti getWage iz employee a ne managera
                                         //Hoce k, compiler skonta, pa je ovo pozvao preko reference na Manager!!!!! ZAPAMTI

        //Employee e = new Employee("Ciro", 1);
        //boss = e; //Svi employees nisu i manageri tako da ovo ne moze

        Employee[] employees = new Employee[3];
        employees[0] = boss;
        employees[1] = new Manager("Dario", 1300);
        employees[2] = new Employee("Sinisa", 3);
        for (Employee emp : employees) {
            System.out.println(emp.getWage());
        }

        //"final" uz klasu onemogucava da kreiras izvedenu klasu koja ce naslijedjivati tu final

        //"final" uz metode onemogucava redefenisanje javnog metoda oznacenog kao final u izvedenim klasama
        //ne dozvoljava dynamic linking (kao sto smo gore imali kad je referenca na Employee pozvala metod iz Manager

        //"final" uz clanove je kao const

        Manager m1 = (Manager) employees[1]; //Ne bi moglo bez casta (bez obzira sto je to Manager) jer je to za sad Employee iz niza
        //Manager m2 = (Manager) employees[2]; //Hop, exception

        Manager[] managers = new Manager[3];
        Employee[] employees1 = managers;

        //employees1[0] = new Employee("Fehim", 650);
        //managers[0].setBonus(100000); //OOOOOFFFFF, obicni Employee al ga puko ko Manager i sad moze imat bonus

        //instanceof -> operator koji provjerava da li je objekat tipa neke Klase
        //if (someObject instanceof someClass) {...}
    }
}
