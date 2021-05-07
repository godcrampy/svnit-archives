package com.example.contactsmessagelab9;

import androidx.room.Database;
import androidx.room.RoomDatabase;

import com.example.contactsmessagelab9.models.Contact;
import com.example.contactsmessagelab9.models.Message;
import com.example.contactsmessagelab9.services.ContactDao;
import com.example.contactsmessagelab9.services.MessageDao;


@Database(entities = {Contact.class, Message.class}, version = 1, exportSchema = false)
public abstract class AppDatabase extends RoomDatabase {
    public abstract ContactDao contactDao();

    public abstract MessageDao messageDao();
}
