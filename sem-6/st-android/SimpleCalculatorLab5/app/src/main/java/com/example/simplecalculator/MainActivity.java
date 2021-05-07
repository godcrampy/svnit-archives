package com.example.simplecalculator;

import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

import java.math.BigDecimal;
import java.math.RoundingMode;

public class MainActivity extends AppCompatActivity {

    Button button0, button1, button2, button3, button4, button5, button6,
            button7, button8, button9, buttonAdd, buttonSub, buttonDivision,
            buttonMul, button10, buttonC, buttonEqual;
    EditText editText;

    private static double round(double value) {

        BigDecimal bd = BigDecimal.valueOf(value);
        bd = bd.setScale(4, RoundingMode.HALF_UP);
        return bd.doubleValue();
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        button0 = (Button) findViewById(R.id.button0);
        button1 = (Button) findViewById(R.id.button1);
        button2 = (Button) findViewById(R.id.button2);
        button3 = (Button) findViewById(R.id.button3);
        button4 = (Button) findViewById(R.id.button4);
        button5 = (Button) findViewById(R.id.button5);
        button6 = (Button) findViewById(R.id.button6);
        button7 = (Button) findViewById(R.id.button7);
        button8 = (Button) findViewById(R.id.button8);
        button9 = (Button) findViewById(R.id.button9);
        button10 = (Button) findViewById(R.id.button10);
        buttonAdd = (Button) findViewById(R.id.buttonadd);
        buttonSub = (Button) findViewById(R.id.buttonsub);
        buttonMul = (Button) findViewById(R.id.buttonmul);
        buttonDivision = (Button) findViewById(R.id.buttondiv);
        buttonC = (Button) findViewById(R.id.buttonC);
        buttonEqual = (Button) findViewById(R.id.buttoneql);
        editText = (EditText) findViewById(R.id.edt1);


        button1.setOnClickListener(v -> editText.setText(editText.getText() + "1"));

        button2.setOnClickListener(v -> editText.setText(editText.getText() + "2"));

        button3.setOnClickListener(v -> editText.setText(editText.getText() + "3"));

        button4.setOnClickListener(v -> editText.setText(editText.getText() + "4"));

        button5.setOnClickListener(v -> editText.setText(editText.getText() + "5"));

        button6.setOnClickListener(v -> editText.setText(editText.getText() + "6"));

        button7.setOnClickListener(v -> editText.setText(editText.getText() + "7"));

        button8.setOnClickListener(v -> editText.setText(editText.getText() + "8"));

        button9.setOnClickListener(v -> editText.setText(editText.getText() + "9"));

        button0.setOnClickListener(v -> editText.setText(editText.getText() + "0"));
        buttonAdd.setOnClickListener(v -> editText.setText(editText.getText() + "+"));
        buttonSub.setOnClickListener(v -> editText.setText(editText.getText() + "-"));
        buttonMul.setOnClickListener(v -> editText.setText(editText.getText() + "*"));
        buttonDivision.setOnClickListener(v -> editText.setText(editText.getText() + "/"));


        buttonEqual.setOnClickListener(v -> {
            try {

                double res = Evaluator.eval(editText.getText().toString());
                res = round(res);
                editText.setText(Double.toString(res));
            } catch (Exception e) {
                Toast.makeText(this, "Error: " + e.getMessage(), Toast.LENGTH_SHORT).show();
            }

        });

        buttonC.setOnClickListener(v -> editText.setText(""));

        button10.setOnClickListener(v -> editText.setText(editText.getText() + "."));
    }
}