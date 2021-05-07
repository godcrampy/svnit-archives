package com.example.contactsmessagelab9.services;

import androidx.room.Dao;
import androidx.room.Delete;
import androidx.room.Insert;
import androidx.room.Query;
import androidx.room.Transaction;
import androidx.room.Update;

import com.example.contactsmessagelab9.models.Contact;
import com.example.contactsmessagelab9.models.ContactWithMessages;

import java.util.List;

@Dao
public interface ContactDao {
    @Query("SELECT * FROM contact")
    List<Contact> getAll();

    @Query("SELECT * FROM contact WHERE uid IN (:contactIds)")
    List<Contact> loadAllByIds(int[] contactIds);

    @Query("SELECT * FROM contact WHERE name LIKE :name LIMIT 1")
    Contact findByName(String name);

    @Insert
    void insertAll(Contact... contacts);

    @Delete
    void delete(Contact contact);

    @Update
    void update(Contact contact);

    @Transaction
    @Query("SELECT * FROM contact")
    List<ContactWithMessages> contactsWithMessages();

    @Transaction
    @Query("SELECT * FROM contact WHERE uid = :uid")
    ContactWithMessages contactsWithMessagesOfId(long uid);
}
