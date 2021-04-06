package employees;

import java.util.Date;
import java.util.GregorianCalendar;

public class Employee {
	private String ime_;
	private double plata_; //Double - Wrapper klasa za "double" (isto kao i Integer)
						   //Koristi se u slucaju da moze poprimiti null value
	private Date datumZaposlenja_;
	
	public Employee() {} //Isto kao i default konstruktor - inic. na default values
	
	public Employee(String ime, double plata, int dan, int mjesec, int godina) {
		ime_ = ime;
		plata_ = plata;
		datumZaposlenja_ = new GregorianCalendar(godina, mjesec - 1, dan).getTime();
	}

	public double getSalary() {
		return plata_;
	}
	
	public void setIme(String ime) {
		ime_ = ime;
	}
	public void povecajPlatu(int percentage) {
		plata_ *= (1 + percentage/100.0);
	}

	@Override
	public String toString() {
		return "Employee [ime_=" + ime_ + ", plata_=" + getSalary() + ", datumZaposlenja_=" + datumZaposlenja_ + "]";
	}
	
}
