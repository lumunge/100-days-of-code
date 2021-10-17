### HASHING && HASHTABLES

#### APPLICATIONS
    - programming languages - dict(python), hashmap(java)
    - file systems - filename & path and disk physical location 
    - Password verification - mapping hashed value to hashed value of stored password
    - Storage Optimization - google cloud, dropbox, yandex

#### Problem: Ip Address Logging** to prevent DDOS by counting access counts of an ip

#### Approach (1) -> DIRECT ADDRESSING
    - one to one correspondence
    - tries to store ip for each possiblility 2^32 ips, too much memory.
    - Direct address table:
    - Involves building an array arr[0...n-1] where element with k is placed arr[k] and
      arr[i] == NULL if there is nor element in array with key i.
    - SEARCH(arr, k) O(1)
        return arr[k]
    - INSERT(arr, x)  O(1)
        arr[x.key] = x
    - DELETE(arr, x)  O(1)
        arr[x.key] = NULL
    - uses O(N) memory, N = |S| -> set of all objects that might be stored in data 
      structure(universe), it relies on string assumptions about the input.
    - Works well when the universe is smaller

#### Approach (2) -> LIST-BASED MAPPING
    - Storing only active input data, to optimize memory.
    - Sorted by time of access
    - Ip addresses for a time span of 1 hour will be stored in the list at each moment
    - Pop ip addresses that used a service more than 1 hour ago
    - Memory is O(n) -> currently ips and times of access stored
    - Time for append, top, pop is O(1) -> per log line 
    - AccessLastHr, AccessCountLastHr is O(n) -> need for traversal of the whole list

#### HASH FUNCTION
    - Direct addressing worked but used alot of memory to store large intergers representing
      ip addresses.
    - Solution: Encode ips with small numbers
    - Hash Function -> A function that encodes an object from set S as a number from 
                       {0 ... m-1}. m > 0;
                       m --> cardinality of the hash function
    - Properties of hash Function:
        -> Hash function should be fast to compute
        -> Different values for different objects
        -> Direct addressing with O(m) memory --> (bottleneck)
        -> Small cardinality m, but impossible to have different values if |S| is more than
           m. -> will lead to collisions.
    - Collisions -> Whereby values of hash functions are same but encoded objects are different
    - Collisions are handled by:
        -> Separate Chaining - making each cell of hash table point to list with same hash value
        -> Open Addressing - All elements are stored in hash table, table size must be >= number of keys

##### CHAINING
    - Technique for store mappings from one type to another object type.
    - Map:
        -> filename- file on disk
        -> contact name -> phone number
    - Map from S to V os a DS with methods hasKey(O), get(O), set(O, v),
        - Object O belongs to set S, value v belongs to set V
    - How chaining works:
        Create an array of size m -> (m is cardinality of hash function)
        Objects = ip addresses
        Values = counters

        Sample:                                 Input Logs:
        m = 7       h = hash function           -> h(167.89.94.100) = 6 -> value of hash function
                                                -> h(132.99.23.76) = 6 
        | 0 |                                   -> h(167.89.94.100) = 6
        | 1 |->(45.120.66.78|1)                 -> h(45.120.66.78) =  1
        | 2 |
        | 3 |
        | 4 |                  2 is the count 
        | 5 |                 /
        | 6 |->(167.89.94.100|2) -> (132.99.23.76|1) 
        | 7 |

    - A chain may be empty or non-empty, we can remove objects from a chain
    - The array size is m = cardinality of hash function
    - In each cell we store a list of pair with hash value same and value of cell
    
    - PSEUDOCODE:
        
        hasKey(O):
            L <- arr[h(O)]       //compute hash value
            for (O^, v^) in L:   //go through list looking at pairs O prime V prime 
                if O^ == O:      //O prime is equal to O in list
                    return true
            return false

        Get(O):
            L <- arr[h(O)]
            for (O^, v^) in L:
                if O^ == O:
                    return v^
            return n/a          //not found

        set(O, v):
            L <- arr[h(O)]
            for p in L:             //go throught list pairs
                if p.O == O
                    p.v <- v        //rewrite value of pair
                    return
            L.append(O, v)          // not in list create a new pair
        
    - Time == Big Theta(c+1) iff c is length of longest chain in arr
    - Memory == Big Theat(n + m) where n = number of different keys in map
                                       m = cardinality of hash function

                                       HOW TO MAKE m and c SMALL???? --> clever hash function

#### HASH TABLES
    - A hashtable is an implementation of set/map using hashing
    - Set a DS with the methods, Add(O), Remove(O), Find(O)
    - Set implementation:
        -> Store objects instead of object pairs
    - PSEUDOCODE
        
        Find(O):
            l <- arr[h(O)]
            for O^ in L:
                if O^ == O:
                    return true
            return false

        Add(O):
            L <- ar[h(O)]
            for O^ in L:
                if O^ == O:
                    return
            L.append(O)

        Remove(O):
            if not Find(O):
                return
            L <- arr[h(O)]
            L.Erase(O)

##### HASHFUNCTIONS
    - Speed of hashtable depends on choice of hash function
    - Good hash functions are deterministic
    - Fast to compute
    - Distributes keys well to different cells in terma of chaingin method
    - Few collisions

###### Phonebook Problem;
    - PROBLEM STATEMENT:
        -> Design a data structure to store contacts, names of people along with phone
           numbers.
           The data structure should do the following quicky
                Add and delete contacts
                Lookup phone number by name and vice versa
                Determine who is calling given phone number

    - Mappings 1: phone number to name 2: name to phone number 
    
    - DIRECT ADDRESSING:
        -> Create an array Name[10^L] L = max length of phone number
        -> Store name corresponding to phone number Name[int(P)]
        -> If no contact Name[int(P)] == NULL
                                            
                                             ______
                                            |      |
        john 138-908-367 --> 138908367   -> | john |
                                            | NULL |
                                            | NULL |
                                            | ...  |
        doe 138-908-370 -->  138908370  ->  | doe  |
                                            | NULL |
                                            | ...  |

        -> Time = O(1) - direct access
        -> Memory = O(10^L) - exponential, 1TB -> to store a fairly large phone book

    - CHAINING:
        -> Select hash function with cardinality m
        -> Create array Name[m]
        -> Store chains in each cell based on hash value as discussed above

          m -> cardinality of hash function, if to numbers have same cardinality, chain them
        | 0 | 
        | 1 |
        | 2 | -> John: 138908367 -> meg: 138908366 
        | 3 |
        | 4 |
        | 5 | -> Doe: 138908370
        | 6 |

        -> Chain Name[h(int(p))] contains name for phone number p
        -> n phone numbers stored
        -> m cardinality of hash function, size of array
        -> c length of longest chain
        -> O(n+m) memory
        -> O(c+1) time
        -> Alpha = n/m = load factor
        -> Need small c and m

        -> Hashfunctions:
            Sample 1: (First Digits) -> take first digits of phone number
                m = 1000
                -> Problem: similar area code, hash values will be same
            Sample 2: (Last Digits(
                m = 1000
                -> Problem: similar ending numbers
            Sample 3: (Random Number)
                m = 1000
                Good distribution but cannot find value because of randomizing, not deterministic
                must return same value when given same value as input
        
        - UNIVERSAL FAMILY
            - For any deterministic hash function there is a bad input for which there will
              be alot of collisions.
            - Define a family (set) of hash functions and choose a random function from the
              family.
            - U -> set of all possible keys (universe).
            - Universal family -> a set of hash functions whereby any two keys in the universe
              have a small probability of collision.(deterministic)
            - Selecting random hash functions from the set of deterministic hash functions and select
              on function and use it through out the whole algorithms
            - Time = O(1 + load factor(alpha)) == constant time!!
              load factor -> ratio of number of keys to size of allocated hash table(cardinality)
            - Choosing size of hash table:
                load factor  =  0.5 < alpha < 1 O(n) memory
                                                O(1+alpha) time
                What about dynamic tables:
                    - Dymanic arrays idea -> resize hash table when alpha becomes too large
                                          -> choose new hash function to rehash all objects

            - PSEUDOCODE:
               //keeping load factor below n
                Rehash(T): Time == O(n) 
                    loadFactor <- T.numberOfKeys / T.size
                    if loadFactor > n:
                        create Tnew of size*2 * T.size
                        choose newHash with Tnew.size cardinality
                        For each object O in T:
                        insert O in Tnew using newHash
                    T <- Tnew
                    hash <- newHash

            - Rehashing happens rarely so armotized runnng time for each operation in the
              hash table is still constant.
        
        - HASHING INTEGERS
            - Sample phone numbers with length 7
            - 148-23-90 --> 1482390
            - Choose big prime number 10^7 (1000023) (p)
            - Choose hash table size m = 1000 (m)
            - Create a universe of hash functions. (universal family)
            - Hp = {    a, b
                      h      (x) = ((ax + b) mod p) mod m 
                        p                                  }

                        a, b: 1 <= a <= p - 1
                              0 <= b <= p - 1
            - p(p - 1) --> size of universal family.

            - Eg:
                hashing 148-25-67 --> 1482567

                     34, 2              a = 34
                h = h                   b = 2
                      10 000 019        x = 1482567
                                        m = 1000

                soln:
                    (34 * 1482567 + 2) mod 10000019 = 407185
                    407185 mod 1000 = 185

                    h(x) = 185

                    -> any value of hash function will be between 0 - 999

            - General Case:
                -> define max length of phone number
                -> convert phone number to integers from 0 - 10^L - 1
                -> Choose p > 10^L
                - Choose hash table size m
                -> Choose random hash function from universal family
                -> a - random number [1, p-1]
                -> b - random number [-, p-1] a, b define hash function.
                
        - HASHING STRINGS
            - Map names to phone numbers
            - Hash abitrary string of characters
            - |S| -> length of string
            - Use all caharcters to avoid collisions
            - Convert each character to ASCII / UniCode
            - Choose big prime number p
            - Create universal family of hash functions using Polynomial Hashing
            
            - PSEUDOCODE:
                PolyHash(S, p, x): O(|S|) time, O(1) if string is bounded
                    hash <- 0
                    for i from |S|-1 down to 0:
                        hash <- (hash * x + S[i]) mod p
                    return hash

            Iterations:
                |S| = 3
                
                hash = 0
                hash = S[2] mod p
                hash = S[1] + S[2]x mod p
                hash = S[0] + S[1]x + S[2]x^2 mod p // polyminial hash function

            - All hash functions in the universal family will have the cardinality p which
              is a very large number.
            - Make cardinality of hash function to be small because it will be size of hash table
            - Fixing Cardinaltity
                -> Take string and apply random function from polynimial family
                -> Apply random function from universal family for integers to result
                -> Use the two functions through out the algorithm
                -> More formally...
                -> Choose cardinality m and prime number p>m
                -> Choose a random hash function h from the polynomial hash family Pp
                -> Choose a random hash function h_int the universal family Hp for integers
                   between 0 and p−1 .
                -> Use hash function hm(x) = h_int(h(x))
