package com.example.contactslab8;

import android.os.Bundle;
import android.telephony.PhoneNumberUtils;
import android.widget.Button;
import android.widget.EditText;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;
import androidx.room.Room;

import com.example.contactslab8.models.Contact;
import com.example.contactslab8.models.ContactDao;

public class AddActivity extends AppCompatActivity {

    private EditText emailEditText;
    private EditText nameEditText;
    private EditText phoneEditText;
    private EditText addressEditText;
    private Button saveButton;
    private String name;
    private String phone;
    private String address;
    private String email;
    private AppDatabase db;
    private ContactDao contactDao;

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
                .setMessage("Are you sure you want to add new contact?")
                .setPositiveButton("Yes", (dialogInterface, i) -> {
                    new Thread(() -> {
                        contactDao.insertAll(new Contact(System.currentTimeMillis(), name, email, phone, address));
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
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_add);
        db = Room.databaseBuilder(this, AppDatabase.class, "contacts").build();
        contactDao = db.contactDao();
        initialiseUI();
    }
}