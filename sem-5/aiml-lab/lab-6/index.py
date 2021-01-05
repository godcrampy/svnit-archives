from city import City
from utils import connect_city_random, print_answer
from a_star import AStar
from ao_star import AOStar

cities = {
    "a": City(1, 2, "a"),
    "b": City(1, 7, "b"),
    "c": City(2, 2, "c"),
    "d": City(3, 5, "d"),
    "e": City(7, 3, "e"),
    "f": City(9, 9, "f"),
}

connect_city_random(cities["a"], cities["b"])
connect_city_random(cities["a"], cities["d"])
connect_city_random(cities["b"], cities["c"])
connect_city_random(cities["a"], cities["c"])
connect_city_random(cities["d"], cities["c"])
connect_city_random(cities["d"], cities["e"])
connect_city_random(cities["f"], cities["e"])


for k in cities:
    print(f"{k}: {cities[k].print()}")

startCity = input("Enter starting city: ")
endCity = input("Enter ending city: ")
print_answer("A*", AStar.solve(cities[startCity], cities[endCity]))
print_answer("AO*", AOStar.solve(cities, cities[startCity], cities[endCity]))
