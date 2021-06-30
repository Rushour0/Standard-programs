a = input()
print('Yes is palindrome' if a == ''.join(reversed(a)) else 'No')
