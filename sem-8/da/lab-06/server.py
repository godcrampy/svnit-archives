import rpyc
import math
from rpyc.utils.server import ThreadedServer

class CalculatorService(rpyc.Service):
    def exposed_is_palindrome(self, s):
        print(s)
        return s[::-1] == s

    def exposed_is_leap_year(self, year):
        return year % 4 == 0 and (year % 100 != 0 or year % 400 == 0)
    
    def exposed_gcd(self, a, b):
        return math.gcd(a, b)
    
    def exposed_sqrt(self, a):
        return a**0.5
    
    def exposed_swap_variables(self, a, b):
        a ^= b
        b ^= a
        a ^= b
        return [a, b]
    
    def exposed_min_max_avg(self, l):
        sum = 0
        for x in l:
            sum += x
        
        avg = sum / len(l)
        return [max(l), min(l), avg]
    
    def exposed_compare_strings(self, s1, s2):
        return s1 < s2
    
    def exposed_is_substring(self, s1, s2):
        return s1 in s2

    def exposed_concat_strings(self, s1, s2):
        return s1 + s2

    def exposed_reverse_array(self, l):
        return l[::-1]


if __name__ == "__main__":
    server = ThreadedServer(CalculatorService, port = 12345)
    print("Server started")
    server.start()