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

        -> Time = O(1) - direct access
        -> Memory = O(10^L) - exponential, 1TB -> to store a phone book

    - CHAINING:
        -> Select hash function with cardinality m
        -> Create array Name[m]
        -> Store chains in each cell based on hash value as discussed above
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
