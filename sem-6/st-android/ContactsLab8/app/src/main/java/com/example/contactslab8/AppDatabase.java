package com.example.contactslab8;

import androidx.room.Database;
import androidx.room.RoomDatabase;

import com.example.contactslab8.models.Contact;
import com.example.contactslab8.models.ContactDao;

@Database(entities = {Contact.class}, version = 1)
public abstract class AppDatabase extends RoomDatabase {
    public abstract ContactDao contactDao();
}
