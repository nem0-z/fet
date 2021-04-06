package lv3;

public class Main {
    public static void main(String[] args) {
        Circle krug = new Circle(5);
        krug.setColored(true);
        Rectangle pravougaonik = new Rectangle(5, 3);

        System.out.println(krug);
        System.out.println(pravougaonik);

        //System.out.println(krug.getArea());
        //System.out.println(pravougaonik.getArea());

        GeoObject g = new GeoObject();
        System.out.println(g); //Nema logike imati geo objekat fizicki, to je samo apstrakcija -> iduce vjezbe
    }
}
