package com.example.contactsmessagelab9.models;

import androidx.room.Embedded;
import androidx.room.Relation;

import java.util.List;

public class ContactWithMessages {
    @Embedded
    public Contact contact;
    @Relation(
            parentColumn = "uid",
            entityColumn = "user_id"
    )
    public List<Message> messages;
}
