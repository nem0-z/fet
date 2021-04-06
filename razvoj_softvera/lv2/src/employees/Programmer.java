package employees;

import java.util.Date;
import java.util.GregorianCalendar;

public class Programmer extends Employee {
    private int numberOfProjects;

    public Programmer(String name, double salary, int day, int month, int year) {
        super(name, salary, day, month, year);
        this.numberOfProjects = 0;
    }

    public void setNumberOfProjects(int num) {
        this.numberOfProjects = num;
    }

    public double getSalary() {
        return super.getSalary() + super.getSalary() * 0.05 * numberOfProjects;
    }
}
