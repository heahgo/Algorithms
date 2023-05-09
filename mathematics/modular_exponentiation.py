# modular_exponentiation.py 
# Modular Exponentiation
# Time Complexity : O(logn)

def mod_exp_r2l(a, n, m):           # right to left (r2l)
    n = bin(n)[2:]
    A, B = 1, a
    for i in range(len(n) - 1, -1, -1):
        if n[i] == '1':
            A = pow(A*B, 1, m)
        B = pow(B, 2, m)
    return A

def mod_exp_l2r(a, n, m):           # left to right (l2r)
    if (n < 2):
        return a ** n % m
    n = bin(n)[3:]                  # Use less memory than r2l
    A = a
    for i in n:
        A = pow(A, 2, m)
        if i == '1':
            A = pow(A * a, 1, m)
    return A

if __name__ == "__main__":
    first_int, second_int, third_int = map(int, input("Input a, n, m (example 17 9 31) : ").split(' '))
    print('a ^ n mod m')
    print(f'mod_exp_r2l : {mod_exp_r2l(first_int, second_int, third_int)}')
    print(f'mod_exp_l2r : {mod_exp_l2r(first_int, second_int, third_int)}')
    print(f'python  pow : {pow(first_int, second_int, third_int)}' )
    
   
    
    

