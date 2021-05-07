package com.example.contactsmessagelab9.views;

import android.os.Bundle;
import android.telephony.PhoneNumberUtils;
import android.text.InputType;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ListView;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;
import androidx.room.Room;

import com.example.contactsmessagelab9.AppDatabase;
import com.example.contactsmessagelab9.R;
import com.example.contactsmessagelab9.models.Contact;
import com.example.contactsmessagelab9.models.ContactWithMessages;
import com.example.contactsmessagelab9.models.Message;
import com.example.contactsmessagelab9.services.ContactDao;
import com.example.contactsmessagelab9.services.MessageDao;
import com.google.android.material.floatingactionbutton.FloatingActionButton;

import java.util.Collections;
import java.util.Date;
import java.util.List;
import java.util.Vector;


public class ViewContactActivity extends AppCompatActivity {
    private EditText emailEditText;
    private EditText nameEditText;
    private EditText phoneEditText;
    private EditText addressEditText;
    private ListView messageListView;
    private Button saveButton;
    private Button deleteButton;
    private String name;
    private String phone;
    private String address;
    private String email;
    private AppDatabase db;
    private ContactDao contactDao;
    private MessageDao messageDao;
    private Contact contact;
    private ContactWithMessages contactWithMessages;
    private List<String> messageNames;
    private List<Message> messages;
    private ArrayAdapter<String> arrayAdapter;
    private FloatingActionButton fab;


    private boolean isValidEmail(CharSequence target) {
        if (target == null)
            return false;

        return android.util.Patterns.EMAIL_ADDRESS.matcher(target).matches();
    }

    private void showErrorDialog(String message) {
        new AlertDialog.Builder(this)
                .setIcon(android.R.drawable.stat_notify_error)
                .setTitle("Error")
                .setMessage(message)
                .setNegativeButton("OK", (dialogInterface, i) -> {
                    //set what would happen when positive button is clicked
                })
                .show();
    }

    private void showAddDialogue() {
        new AlertDialog.Builder(this)
                .setIcon(android.R.drawable.ic_menu_save)
                .setTitle("Save")
                .setMessage("Are you sure you want to save contact?")
                .setPositiveButton("Yes", (dialogInterface, i) -> {
                    new Thread(() -> {
                        contactDao.update(new Contact(contact.uid, name, email, phone, address));
                        runOnUiThread(() -> {
                            setResult(1);
                            finish();
                        });
                    }).start();
                    //set what would happen when positive button is clicked
                }).setNegativeButton("No", (dialogInterface, i) -> {

        }).show();
    }

    private void initialiseUI() {
        emailEditText = findViewById(R.id.email_edit_text);
        nameEditText = findViewById(R.id.name_edit_text);
        phoneEditText = findViewById(R.id.phone_edit_text);
        addressEditText = findViewById(R.id.address_edit_text);
        saveButton = findViewById(R.id.save_button);
        deleteButton = findViewById(R.id.delete_button);
        fab = findViewById(R.id.fab);

        messageListView = findViewById(R.id.messages_list_view);

        emailEditText.setText(contact.email);
        nameEditText.setText(contact.name);
        phoneEditText.setText(contact.mobile);
        addressEditText.setText(contact.address);

        fab.setOnClickListener(v -> {
            AlertDialog.Builder builder = new AlertDialog.Builder(this);
            builder.setTitle("New Message for " + contact.name);

            final EditText input = new EditText(this);
            input.setInputType(InputType.TYPE_CLASS_TEXT);
            builder.setView(input);

            builder.setPositiveButton("OK", (dialog, which) -> new Thread(() -> {
                if (input.getText().length() != 0) {
                    messageDao.insertMessages(new Message(System.currentTimeMillis(), contact.uid, input.getText().toString(), new Date()));
                    initialiseMessages();
                }
            }).start());
            builder.setNegativeButton("Cancel", (dialog, which) -> dialog.cancel());
            builder.show();
        });

        messageListView.setOnItemClickListener((parent, view, position, id) -> {
            Message message = messages.get(position);

            AlertDialog.Builder builder = new AlertDialog.Builder(this);
            builder.setTitle(message.date.toString());

            final EditText input = new EditText(this);
            input.setInputType(InputType.TYPE_CLASS_TEXT);
            input.setText(message.message);
            builder.setView(input);

            builder.setPositiveButton("OK", (dialog, which) -> new Thread(() -> {
                if (input.getText().length() != 0) {
                    messageDao.updateMessages(new Message(message.messageId, contact.uid, input.getText().toString(), new Date()));
                    initialiseMessages();
                }
            }).start());
            builder.setNegativeButton("Cancel", (dialog, which) -> dialog.cancel());
            builder.setNeutralButton("Delete", (dialog, which) -> new Thread(() -> {
                messageDao.deleteMessage(message);
                initialiseMessages();
            }).start());
            builder.show();
        });

        saveButton.setOnClickListener(v -> {
            name = nameEditText.getText().toString();
            email = emailEditText.getText().toString();
            phone = phoneEditText.getText().toString();
            address = addressEditText.getText().toString();

            if (name.length() == 0) {
                showErrorDialog("Name cannot be empty");
                return;
            }

            if (email.length() != 0 && !isValidEmail(email)) {
                showErrorDialog("Invalid email");
                return;
            }

            if (!PhoneNumberUtils.isGlobalPhoneNumber(phone)) {
                showErrorDialog("Invalid Phone");
                return;
            }

            showAddDialogue();
        });

        deleteButton.setOnClickListener(v -> showDeleteDialogue());
    }

    private void showDeleteDialogue() {
        new AlertDialog.Builder(this)
                .setIcon(android.R.drawable.ic_delete)
                .setTitle("Delete")
                .setMessage("Are you sure you want to delete this contact?")
                .setPositiveButton("Yes", (dialogInterface, i) -> {
                    new Thread(() -> {
                        contactDao.delete(contact);
                        runOnUiThread(() -> {
                            setResult(1);
                            finish();
                        });
                    }).start();
                    //set what would happen when positive button is clicked
                }).setNegativeButton("No", (dialogInterface, i) -> {

        }).show();
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_view_contact);
        contact = (Contact) getIntent().getSerializableExtra("contact");

        db = Room.databaseBuilder(this, AppDatabase.class, "contacts").build();
        contactDao = db.contactDao();
        messageDao = db.messageDao();
        initialiseUI();
        new Thread(this::initialiseMessages).start();
    }

    private void updateMessageList() {
        arrayAdapter = new ArrayAdapter<>(this, R.layout.activity_listview, R.id.contact_text_view, messageNames);
        messageListView.setAdapter(arrayAdapter);
    }

    private void initialiseMessages() {
        contactWithMessages = contactDao.contactsWithMessagesOfId(contact.uid);
        messages = contactWithMessages.messages;
        Collections.reverse(messages);
        messageNames = new Vector<>(messages.size());


        for (Message message : messages) {
            messageNames.add(message.message);
        }
        runOnUiThread(this::updateMessageList);
    }
}
