#!/usr/bin/python3

def minOperations(n):
    
    currentChars = 1
    copyChars = 1
    counter = 1
    
    if (n < 2)
        return (0);
    
    if (currentChars == 1):
        currentChars += copyChars
        counter += 1
    
    while (currentChars < n):
        if (n % currentChars == 0 and copyChars + currentChars <= n):
            copyChars = currentChars
            counter += 1
            currentChars += copyChars
        else:
            currentChars += copyChars
        counter +=1
            
    return (counter);
