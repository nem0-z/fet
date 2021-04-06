package lv3;

public class Rectangle extends GeoObject {
    private int width;
    private int height;

    public Rectangle() {}

    public Rectangle(int width, int height) {
        this.width = width;
        this.height = height;
    }

    public int getWidth() {
        return width;
    }

    public void setWidth(int width) {
        this.width = width;
    }

    public int getHeight() {
        return height;
    }

    public void setHeight(int height) {
        this.height = height;
    }

    public double getArea() {
        return height * width;
    }

    public double getVolume() {
        return 2 * (width + height);
    }

    @Override
    public String toString() {
        return super.toString() + "\nwidth: " + this.width + "\nheight: " + this.height + "\n";
    }
}
