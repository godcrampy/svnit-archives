package com.example.contactsmessagelab9.models;

import androidx.room.ColumnInfo;
import androidx.room.Entity;
import androidx.room.PrimaryKey;
import androidx.room.TypeConverters;

import com.example.contactsmessagelab9.util.DateConverter;

import java.util.Date;

@Entity
@TypeConverters(DateConverter.class)
public class Message {
    @PrimaryKey
    public long messageId;
    @ColumnInfo(name = "user_id")
    public long userId;
    @ColumnInfo(name = "message")
    public String message;
    @ColumnInfo(name = "date")
    public Date date;

    public Message(long messageId, long userId, String message, Date date) {
        this.messageId = messageId;
        this.userId = userId;
        this.message = message;
        this.date = date;
    }

    public Date getDate() {
        return date;
    }

    public void setDate(Date date) {
        this.date = date;
    }
}