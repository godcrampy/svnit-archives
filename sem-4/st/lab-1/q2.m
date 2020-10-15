clc
clear all;

% question 11 to 17

a = rand(5, 6)
b = 'I am an Indian'

type_of_a = typeinfo(a)
type_of_b = typeinfo(b)

submatrix = a(3:4, 2:5)

does_a_exist = exist("a")
does_z_exist = exist("z")