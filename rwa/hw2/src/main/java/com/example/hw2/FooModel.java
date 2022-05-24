package com.example.hw2;


import jakarta.persistence.*;

@Entity
@Table(name = "foo", schema = "rwa_hw", catalog = "")
public class FooModel {
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    @Id
    @Column(name = "id")
    private int id;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        FooModel fooModel = (FooModel) o;

        if (id != fooModel.id) return false;

        return true;
    }

    @Override
    public int hashCode() {
        return id;
    }
}
