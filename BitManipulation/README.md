# Bit Manipulation
* Data in computers is stored in bits, 0s, 1s
* Length of bit representation of a number is dependent on its data type e.g int = 32-bit
* Signed -> can be represented both as a -ve and a +ve
         -> first digit in bits of a signed int is the sign, 0 for -ve, 1 for +ve
* Unsigned -> only represents negative numbers, larger upper bounds
```c++
int x = -45;
unsigned int y = x;
cout << x << endl;
cout << y << endl;
```

* Overflows - caused by a number being larger than upper bound of its bit representation
```c++
int x = 2147483647;
cout << x << endl;
cout << x + 1 << endl;
```

## Bit operations
#### AND
1 & 1 = 1
1 & 0 = 0
0 & 0 = 0
0 & 1 = 0

#### OR
1 | 1 = 1
1 | 0 = 1
0 | 1 = 1
0 | 0 = 0

#### XOR
1 ^ 1 = 0
0 ^ 0 = 0
1 ^ 0 = 1
0 ^ 1 = 1

#### NOT
-> Inverts bits e.g 1001 = 0110

### Bit shifts
Left Shift << : x << k appends k zero bits to number
Right Shift >> x << k removes last k bits from number
