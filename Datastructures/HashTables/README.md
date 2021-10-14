### HASHING && HASHTABLES

#### APPLICATIONS
    - programming languages - dict(python), hashmap(java)
    - file systems - filename & path and disk physical location 
    - Password verification - mapping hashed value to hashed value of stored password
    - Storage Optimization - google cloud, dropbox, yandex

#### DIRECT ADDRESSING
    - one to one correspondence
    - tries to store something for each possible input, too much memory.
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
