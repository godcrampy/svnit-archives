clc;
clear all;

x = [9 3 6 12 30];
labels = {'Walk', 'Bike' 'Car', 'Bus', 'Total'};
subplot(1, 2, 1);
pie(x);
legend(labels);

subplot(1, 2, 2);
bar(x);
set(gca, 'XTickLabel', labels);