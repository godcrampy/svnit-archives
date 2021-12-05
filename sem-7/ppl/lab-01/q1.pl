say_hi() :- 
  write('Please enter your name: '),
  nl,
  read(Name),
  atom_concat('Hello, ', Name, Greeting),
  write(Greeting).

animal(elephant).
animal(dog).
animal(cat).

count_animals(Count) :- aggregate_all(count, animal(_), Count).
