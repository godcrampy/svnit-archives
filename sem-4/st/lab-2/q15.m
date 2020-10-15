clc;
clear all;

x = input("Enter a number: ")

if x == str2num(fliplr(num2str(x)))
  puts("Palindrome\n");
else
  puts("Not palindrome\n");
endif
