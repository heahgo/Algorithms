# euclidean_algorithm.py
# Euclidean Algorithm
# Time Complexity : O(log(min(a, b)))

def gcd(a, b): # Greatest Common Divisor with Euclidean Algorithm
    while b != 0:
        r = a % b
        a, b = b, r
    return a

if __name__ == '__main__':
    first_int, second_int = map(int, input("Input two integers (example 12 18) : ").split(' '))
    print(f'gcd({first_int}, {second_int}) = {gcd(first_int, second_int)}')
