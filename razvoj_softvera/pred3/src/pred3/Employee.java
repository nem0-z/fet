package pred3;

public class Employee {
    private double wage;
    private String name;

    public Employee(String name, double wage) {
        this.name = name;
        this.wage = wage;
    }

//    public Employee() {
//        this("Radnik",1000);
//    }

    public double getWage() {
        return wage;
    }

    public void setWage(double wage) {
        this.wage = wage;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void increaseWage(double percentage) {
        final double scale = (1 + percentage/100.0);
        this.wage *= scale;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) //Ako su reference iste, ako sam pozvao na sebi i proslijedio sebe
            return true;
        if (o == null || getClass() != o.getClass()) //Ako je null ili nisu iste klase jer inace ce nas cast zeznut
            return false;
        Employee other = (Employee) o;
        return wage == other.wage && name.equals(other.name); //Poredili smo stringove pa nam treba String.equals
    }
}
