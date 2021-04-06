package lv3;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

public class GeoObject {
    private String color = "white";
    private boolean isColored;
    private LocalDate createdAt;

    public GeoObject() {
        this.createdAt = LocalDate.now();
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public boolean isColored() {
        return isColored;
    }

    public void setColored(boolean colored) {
        isColored = colored;
    }

    public LocalDate getCreatedAt() {
        return createdAt;
    }

    public void setCreatedAt(LocalDate createdAt) {
        this.createdAt = createdAt;
    }

    @Override
    public String toString() {
        String coloredWith = this.isColored ? "Colored with" + color + "\n" : "Not colored\n";
        return coloredWith + "Date of creation: " + getCreatedAt().format(DateTimeFormatter.ofPattern("dd/MM/yyyy"));
    }
}
