package com.example.advroulettegamelab7;

import android.os.Bundle;
import android.os.SystemClock;
import android.view.View;
import android.view.animation.Animation;
import android.view.animation.DecelerateInterpolator;
import android.view.animation.RotateAnimation;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import java.util.Random;

import butterknife.BindView;
import butterknife.ButterKnife;
import butterknife.OnClick;

public class MainActivity extends AppCompatActivity {

    // sectors of wheel
    private static final String[] sectors = {"32 red", "15 black",
            "19 red", "4 black", "21 red", "2 black", "25 red", "17 black", "34 red",
            "6 black", "27 red", "13 black", "36 red", "11 black", "30 red", "8 black",
            "23 red", "10 black", "5 red", "24 black", "16 red", "33 black",
            "1 red", "20 black", "14 red", "31 black", "9 red", "22 black",
            "18 red", "29 black", "7 red", "28 black", "12 red", "35 black",
            "3 red", "26 black", "zero"
    };
    // Random instance to make our wheel spin randomly
    private static final Random RANDOM = new Random();
    // 37 sectors on the wheel, divide 360 by this value to have angle for each sector
    // divide by 2 to have a half sector
    private static final float HALF_SECTOR = 360f / 37f / 2f;
    private final int ANIMATION_DURATION = 3600;
    @BindView(R.id.spinEvenBtn)
    Button spinEvenBtn;
    @BindView(R.id.spinOddBtn)
    Button spinOddBtn;
    @BindView(R.id.spinPrimeBtn)
    Button spinPrimeButton;
    @BindView(R.id.spinNumberBtn)
    Button spinNumberBtn;
    @BindView(R.id.startBtn)
    Button startBtn;
    @BindView(R.id.finBtn)
    Button finishBtn;
    @BindView(R.id.chooseInput)
    EditText chooseInput;
    @BindView(R.id.investInput)
    EditText investInput;
    @BindView(R.id.resultTv)
    TextView resultTv;
    @BindView(R.id.moneyLeftTv)
    TextView moneyLeftTv;
    @BindView(R.id.earnedTv)
    TextView earnedTv;
    @BindView(R.id.trialNumberTv)
    TextView trialNumberTv;
    @BindView(R.id.trialLeftTv)
    TextView trialLeftTv;
    @BindView(R.id.bottomRow)
    LinearLayout bottomRow;
    @BindView(R.id.buttonUpRow)
    LinearLayout buttonUpRow;
    @BindView(R.id.topRow)
    LinearLayout topRow;
    @BindView(R.id.startRow)
    LinearLayout startRow;
    @BindView(R.id.wheel)
    ImageView wheel;
    private int degree = 0, degreeOld = 0;
    private int moneyLeft = 0;
    private int moneyInvested = 0;
    private int moneyEarned = 0;
    private int trialLeft = 0;
    private int trialNum = 0;
    private GameState gameState = GameState.START;

    private void updateTopRow() {
        trialLeft = moneyLeft / 100;
        moneyLeftTv.setText("Money Left: " + moneyLeft);
        earnedTv.setText("Earned: " + moneyEarned);
        trialLeftTv.setText("Left: " + trialLeft);
        trialNumberTv.setText("Trial: " + trialNum);
    }

    private void updateUIByState() {
        if (gameState == GameState.START) {
            buttonUpRow.setVisibility(View.INVISIBLE);
            bottomRow.setVisibility(View.INVISIBLE);
            startRow.setVisibility(View.VISIBLE);
            topRow.setVisibility(View.INVISIBLE);
            finishBtn.setVisibility(View.INVISIBLE);
        } else {
            if (moneyLeft >= 100) {
                buttonUpRow.setVisibility(View.VISIBLE);
                bottomRow.setVisibility(View.VISIBLE);
                finishBtn.setVisibility(View.INVISIBLE);
            } else {
                buttonUpRow.setVisibility(View.INVISIBLE);
                bottomRow.setVisibility(View.INVISIBLE);
                finishBtn.setVisibility(View.VISIBLE);
            }
            startRow.setVisibility(View.INVISIBLE);
            topRow.setVisibility(View.VISIBLE);
//            finishBtn.setVisibility(View.VISIBLE);
        }
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        ButterKnife.bind(this);
        updateUIByState();
    }

    @OnClick(R.id.spinEvenBtn)
    public void spinEven(View v) {
        int n = spinWheel();
        new Thread(() -> {
            SystemClock.sleep(ANIMATION_DURATION);
            moneyLeft -= 100;
            if (n % 2 == 0) {
                // even
                moneyEarned += 100;
            }
            runOnUiThread(() -> {

                updateUIByState();
                updateTopRow();
            });
        }).start();
    }

    @OnClick(R.id.spinOddBtn)
    public void spinOdd(View v) {
        int n = spinWheel();
        new Thread(() -> {
            SystemClock.sleep(ANIMATION_DURATION);
            moneyLeft -= 100;
            if (n % 2 != 0) {
                // even
                moneyEarned += 100;
            }
            runOnUiThread(() -> {

                updateUIByState();
                updateTopRow();
            });
        }).start();
    }


    //checks whether an int is prime or not.
    private boolean isPrime(int n) {
        for (int i = 2; i < n; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }


    @OnClick(R.id.spinPrimeBtn)
    public void spinPrime(View v) {
        int n = spinWheel();
        new Thread(() -> {
            SystemClock.sleep(ANIMATION_DURATION);
            moneyLeft -= 100;
            if (isPrime(n)) {
                // even
                moneyEarned += 500;
            }
            runOnUiThread(() -> {

                updateUIByState();
                updateTopRow();
            });
        }).start();
    }

    @OnClick(R.id.spinNumberBtn)
    public void spinNumber(View v) {
        int n = spinWheel();
        int chosen = 0;
        if (chooseInput.getText().toString().length() > 0) {
            chosen = Integer.parseInt(chooseInput.getText().toString());
        }
        int finalChosen = chosen;
        new Thread(() -> {
            SystemClock.sleep(ANIMATION_DURATION);
            moneyLeft -= 100;
            if (n == finalChosen) {
                // even
                moneyEarned += 5000;
            }
            runOnUiThread(() -> {

                updateUIByState();
                updateTopRow();
            });
        }).start();
    }

    @OnClick(R.id.finBtn)
    public void finish() {
        new AlertDialog.Builder(this)
//set icon
                .setIcon(android.R.drawable.checkbox_on_background)
//set title
                .setTitle("Here's you summary")
//set message
                .setMessage("Invested: " + moneyInvested + "\nRewards Earned: " + moneyEarned + "\nRevenue: " + (moneyEarned + moneyLeft - moneyInvested))
//set positive button
                .setPositiveButton("New Game", (dialogInterface, i) -> {
                    gameState = GameState.START;
                    updateUIByState();
                })
                .show();

    }


    private int spinWheel() {
        ++trialNum;
        degreeOld = degree % 360;
        // calculate random angle for rotation of our wheel
        degree = RANDOM.nextInt(360) + 720;
        // rotation effect on the center of the wheel
        RotateAnimation rotateAnimation = new RotateAnimation(degreeOld, degree,
                RotateAnimation.RELATIVE_TO_SELF, 0.5f, RotateAnimation.RELATIVE_TO_SELF, 0.5f);
        rotateAnimation.setDuration(ANIMATION_DURATION);
        rotateAnimation.setFillAfter(true);
        rotateAnimation.setInterpolator(new DecelerateInterpolator());
        String val = getSector(360 - (degree % 360));
        int sectorNum = Integer.parseInt(val.replaceAll("[\\D]", ""));
        rotateAnimation.setAnimationListener(new Animation.AnimationListener() {
            @Override
            public void onAnimationStart(Animation animation) {
                // empty the result text view when the animation start
                resultTv.setText("");
            }

            @Override
            public void onAnimationEnd(Animation animation) {
                // display the correct sector pointed by the triangle at the end of the rotate animation
                resultTv.setText(val);
            }

            @Override
            public void onAnimationRepeat(Animation animation) {

            }
        });

        // start the animation
        wheel.startAnimation(rotateAnimation);
        return sectorNum;
    }

    @OnClick(R.id.startBtn)
    public void startGame(View v) {
        moneyLeft = 1500;
        if (investInput.getText().toString().length() > 0) {
            moneyLeft = Integer.parseInt(investInput.getText().toString());
        }
        moneyInvested = moneyLeft;
        moneyEarned = 0;
        gameState = GameState.RUNNING;
        updateUIByState();
        updateTopRow();
    }

    private String getSector(int degrees) {
        int i = 0;
        String text = null;

        do {
            // start and end of each sector on the wheel
            float start = HALF_SECTOR * (i * 2 + 1);
            float end = HALF_SECTOR * (i * 2 + 3);

            if (degrees >= start && degrees < end) {
                // degrees is in [start;end[
                // so text is equals to sectors[i];
                text = sectors[i];
            }

            i++;

        } while (text == null && i < sectors.length);

        return text;
    }
}
