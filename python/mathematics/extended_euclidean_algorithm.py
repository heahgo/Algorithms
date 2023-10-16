# extended_euclidean_algorithm.py
# Extended Euclidean Algorithm
# Time Complexity : O(log(min(a, b)))

def extended_euclidean_algorithm(a,b): # a * s + b * t = gcd(a, b)
    r0, r1 = a, b
    s0, s1, t0, t1 = 1, 0, 0, 1 

    while(r1):
        q = r0 // r1
        temp = r0 - r1 * q
        r0 = r1
        r1 = temp
        temp = s0 - s1 * q
        s0 = s1
        s1 = temp
        temp = t0 - t1 * q
        t0 = t1
        t1 = temp                       # if gcd(a, b) == 1 then s0 is modular inverse (a mod b)
                                        # r0 is gcd(a, b)
    return (a, s0, b, t0, r0)           # a * s0 + b * t0 = r0
                                       
                                        
if __name__ == '__main__':
    first_int, second_int = map(int, input("Input two integers (example 12 18) : ").split(' '))
    result = extended_euclidean_algorithm(first_int, second_int)
    print(f'{result[0]} * {result[1]} + {result[2]} * {result[3]} = {result[4]}')
    print(f'gcd({first_int}, {second_int}) = {result[4]}')
    if result[4] == 1:
        print(f'modular inverse (a mod b) : ', end = '')
        print(result[1]) if result[1] > 0 else print(result[2] + result[1])

    


