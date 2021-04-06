package employees;

import java.util.Date;
import java.util.GregorianCalendar;

public class Manager extends Employee {
    private int bonus;

    public Manager(String name, double salary, int day, int month, int year) {
        super(name, salary, day, month, year);
        this.bonus = 0;
    }

    public void setBonus(int bonus) {
        this.bonus = bonus;
    }

    public double getSalary() {
        return super.getSalary() + this.bonus;
        //Dynamic binding po defaultu, u runtime ce odredjivati na osnovu instanceof objekta koji ce metod pozvati
        //Pri pozivu svakog metoda ce gledat imal tog metoda u klasi ciji je tip taj objekat
        //Eh pa ako nema onda trazi u baznim klasama
    }
}
