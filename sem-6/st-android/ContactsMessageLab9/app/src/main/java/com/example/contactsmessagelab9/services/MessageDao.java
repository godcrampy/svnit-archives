package com.example.contactsmessagelab9.services;

import androidx.room.Dao;
import androidx.room.Delete;
import androidx.room.Insert;
import androidx.room.OnConflictStrategy;
import androidx.room.Query;
import androidx.room.Update;

import com.example.contactsmessagelab9.models.Message;

import java.util.List;

@Dao
public interface MessageDao {
    @Insert(onConflict = OnConflictStrategy.REPLACE)
    void insertMessages(Message... messages);

    @Update
    void updateMessages(Message... messages);

    @Delete
    void deleteMessage(Message messages);

    @Query("SELECT * FROM Message")
    List<Message> getAll();
}