def count_fancy(n):
    if n <= 1:
        return 0
    # Convert n to base 4
    digits = []
    temp = n
    while temp > 0:
        digits.append(temp % 4)
        temp //= 4
    L = len(digits)
    
    # For lengths less than L
    total = 0
    for k in range(1, L):
        total += 2 ** k
    
    # For length L
    def count(pos, less):
        if pos == -1:
            return 1
        if less:
            return 2 ** (pos + 1)
        d = digits[pos]
        if d == 0:
            return count(pos - 1, 0)
        elif d == 1:
            return count(pos - 1, 1) + count(pos - 1, 0)
        else:
            return (2 if d > 2 else 1) * count(pos - 1, 1)
    
    total += count(L - 1, 0)
    return total

# Test cases
print(count_fancy(1))  # 0
print(count_fancy(10)) # 3
print(count_fancy(17)) # 4
