clc;
clear all;

marks = [22, 44, 36; 52, 57, 68; 66, 53, 69;  85, 40, 86; 15, 47, 25; 79, 72, 82]
column = [36; 76; 76; 72; 28; 91];
marks = [marks column]

mechanics_scaled = marks .* [ones(6, 3) 0.5 * ones(6, 1)]

chetan = marks(3, :)
chetan_total = sum(chetan)

deepak_marks = marks(4, 1:3)
farah_marks = marks(6, 1:3)

avg_marks = mean(marks)

scaled_marks = marks ./ 10