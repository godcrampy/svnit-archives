package com.example.contactslab8.models;

import androidx.room.ColumnInfo;
import androidx.room.Entity;
import androidx.room.PrimaryKey;

import java.io.Serializable;

@Entity
public class Contact implements Serializable {
    @PrimaryKey
    public long uid;
    @ColumnInfo(name = "name")
    public String name;
    @ColumnInfo(name = "email")
    public String email;
    @ColumnInfo(name = "mobile")
    public String mobile;
    @ColumnInfo(name = "address")
    public String address;

    public Contact(long uid, String name, String email, String mobile, String address) {
        this.uid = uid;
        this.name = name;
        this.email = email;
        this.mobile = mobile;
        this.address = address;
    }

}
