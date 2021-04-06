package employees;

import java.util.Arrays;

public class EmployeeTest {

	public static void main(String[] args) {
		Employee e1 = new Employee();
		e1.setIme("Sinisa");
		Employee e2 = new Employee("Ciro", 3300, 25, 1, 1983);
		//println(e1);
		//println(e2);
		e2.povecajPlatu(10);
		//println(e2);
		Employee e3 = new Employee("Ajla", 6500, 27, 2, 2015);
		//println(e3);
		Employee[] originalEmployees = new Employee[] {e1, e2, e3};
		
		for (Employee e: originalEmployees) {
			println(e);
		}
		System.out.println("\ncopyEmployees: ");

		Employee[] copyEmployees = new Employee[originalEmployees.length];
		System.arraycopy(originalEmployees, 0, copyEmployees, 0, originalEmployees.length); //Opet pokazuju na iste employees
		
		for (Employee e: copyEmployees) {
			e.povecajPlatu(50);
			println(e);
		}
		
		System.out.println("\nNakon povecanja plate u copyEmployees: originalEmployees:");
		for (Employee e: originalEmployees) {
			println(e);
		}
		
		
	}
	
	static void println(Employee e) {
		System.out.println(e);
	}
}
