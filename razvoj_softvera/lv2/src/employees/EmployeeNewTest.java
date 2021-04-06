package employees;

public class EmployeeNewTest {
    public static void main(String[] args) {
        Employee e1 = new Employee("Ciro", 2000, 31, 1, 2013);
        Employee e2 = new Employee("Amila", 3000, 31, 1, 2010);

        Employee[] employees = new Employee[4];

        employees[0] = e1;
        employees[1] = e2;

        Manager m1 = new Manager("Boris", 50000, 31, 3, 1982);
        m1.setBonus(4000);
        Programmer p1 = new Programmer("Eminagic", 2, 25, 1, 1921);
        p1.setNumberOfProjects(-1000);

        employees[2] = m1;
        employees[3] = p1;

        for (Employee e: employees) {
            System.out.println("______________________");
            System.out.println(e);
        }
        //employees[3].setNumberOfProjects(-22222); //Ne moze zato jer je ovo referenca na employee bez obzira sto je on programer
        ((Programmer)employees[3]).setNumberOfProjects(-20502);

        if (employees[2] instanceof Programmer) {
            ((Programmer)employees[2]).setNumberOfProjects(2000);
        }
    }
}
