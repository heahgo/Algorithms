# miller_rabin_primality_test.py
# Miller-Rabin Primality Test 
# Time Complexity : O(k * log^3(n))

from random import randrange
    
def miller_rabin_primality_test(n):
    d, r = n - 1, 0
    while d % 2 != 0: d //= 2; r += 1   # n - 1 = 2^r * d
    for repeat in range(10):
        break_flag = 0
        a = randrange(2, n - 2)
        x = pow(a, d, n)
        if x == 1 or x == n - 1:
            continue
        for j in range(r):
            x  = pow(x, 2, n)
            if x == 1:
                return False
            if x == n - 1:
                break_flag = 1
                break
        if break_flag == 1:
            break    
        return False
    return True    

def is_prime(n):
    if n == 2 or n == 3:          # 2 is prime
        return True
    if n % 2 == 0 or n < 2:
        return False
    if miller_rabin_primality_test(n):
        return True
    return False

def test():
    prime_list = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997]
    for prime in prime_list:
        if is_prime(prime) == False:
            print('Test Failed')
            return
    print('Test Passed')    


if __name__ == '__main__':
    number = int(input("Input number : "))
    print(f'{number} is Prime') if is_prime(number) else print(f'{number} is not Prime')
    test()
