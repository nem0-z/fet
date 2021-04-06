package pred3;

public class Manager extends Employee {
    private double bonus;

    public Manager(String name, double wage) {
        super(name, wage); //Konstruktor nadredjene klase, u slucaju da nemamo defaultnog koji se implicitno poziva
        bonus = 100;
    }

    public double getBonus() {
        return bonus;
    }

    public void setBonus(double bonus) {
        this.bonus = bonus;
    }

    //Override metoda iz nadredjene klase
    @Override
    public double getWage() {
        return super.getWage() + bonus;
    }

    @Override
    public boolean equals(Object o) {
        if (!super.equals(o)) return false;
        Manager other = (Manager) o;
        return bonus == other.bonus;
    }
}
