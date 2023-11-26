def extended_gcd(a, b):
    if b == 0:
        return a, 1, 0
    else:
        d, x, y = extended_gcd(b, a % b)
        return d, y, x - y * (a // b)

def mod_inverse(a, m):
    d, x, y = extended_gcd(a, m)
    if d != 1:
        raise ValueError("Inverse does not exist (a and m are not coprime)")
    return x % m

def visualize_extended_gcd(a, m):
    r_values = [m, a]
    x_values = [0, 1]
    y_values = [1, 0]

    while r_values[-1] != 0:
        q = r_values[-2] // r_values[-1]
        r_values.append(r_values[-2] - q * r_values[-1])
        x_values.append(x_values[-2] - q * x_values[-1])
        y_values.append(y_values[-2] - q * y_values[-1])

    print("{:<2}  {:<5}  {:<5}  {:<5}  {:<5}  {:<5}".format("i", "r_i", "x_i", "y_i", "q_i", "r_{i+1}"))
    for i in range(len(r_values)):
        print("{:<2}  {:<5}  {:<5}  {:<5}  {:<5}  {:<5}".format(i, r_values[i], x_values[i], y_values[i], "" if i == 0 else r_values[i-1] // r_values[i], r_values[i+1]))

a = 550
m = 1769

print("Extended Euclidean Algorithm Visualization:")
visualize_extended_gcd(a, m)

try:
    result = mod_inverse(a, m)
    print(f"\nThe modular inverse of {a} modulo {m} is: {result}")
except ValueError as e:
    print(e)

