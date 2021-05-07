package com.example.contactsmessagelab9.views;


import android.content.Intent;
import android.os.Bundle;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ListView;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;
import androidx.room.Room;

import com.example.contactsmessagelab9.AppDatabase;
import com.example.contactsmessagelab9.R;
import com.example.contactsmessagelab9.models.Contact;
import com.example.contactsmessagelab9.services.ContactDao;
import com.example.contactsmessagelab9.services.MessageDao;
import com.google.android.material.floatingactionbutton.FloatingActionButton;

import java.util.List;
import java.util.Vector;

public class MainActivity extends AppCompatActivity {

    private List<String> contactNames;
    private List<Contact> contacts;
    private ListView contactListView;
    private Button searchButton;
    private EditText searchEditText;
    private FloatingActionButton fab;
    private ArrayAdapter<String> arrayAdapter;
    private AppDatabase db;
    private ContactDao contactDao;
    private MessageDao messageDao;

    private void updateContactList() {
        arrayAdapter = new ArrayAdapter<>(this, R.layout.activity_listview, R.id.contact_text_view, contactNames);
        contactListView.setAdapter(arrayAdapter);
    }

    private void initialiseUI() {
        contactListView = findViewById(R.id.contacts_list_view);
        searchButton = findViewById(R.id.search_button);
        searchEditText = findViewById(R.id.search_edit_text);
        fab = findViewById(R.id.fab);

        contactListView.setOnItemClickListener((parent, view, position, id) -> {
            Intent intent = new Intent(this, ViewContactActivity.class);
            intent.putExtra("contact", contacts.get(position));
            startActivityForResult(intent, 2);
        });

        fab.setOnClickListener(v -> {
            Intent intent = new Intent(this, AddActivity.class);
            startActivityForResult(intent, 1);
        });

        searchButton.setOnClickListener(v -> {
            new Thread(() -> {
                Contact contact = contactDao.findByName(searchEditText.getText().toString());
                runOnUiThread(() -> {

                    if (contact != null) {
                        Intent intent = new Intent(this, ViewContactActivity.class);
                        intent.putExtra("contact", contact);
                        startActivityForResult(intent, 2);
                    } else {
                        new AlertDialog.Builder(this)
                                .setIcon(android.R.drawable.stat_sys_warning)
                                .setTitle("404")
                                .setMessage("Contact not found!")
                                .setNegativeButton("OK", (dialogInterface, i) -> {

                                }).show();
                    }
                });
            }).start();
        });
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        db = Room.databaseBuilder(this, AppDatabase.class, "contacts").build();
        contactDao = db.contactDao();
        messageDao = db.messageDao();
        initialiseUI();
        new Thread(this::initialiseContacts).start();
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        new Thread(this::initialiseContacts).start();
    }

    private void initialiseContacts() {
        contacts = contactDao.getAll();
        contactNames = new Vector<>(contacts.size());
        for (Contact contact : contacts) {
            contactNames.add(contact.name);
        }
        runOnUiThread(this::updateContactList);
    }
}