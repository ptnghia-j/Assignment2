### Duties

Alex
- main (user input, threading)

Nghia
- GitHub repo
- Memory allocation

Evan
- Memory address translation

Christos
- Coding assistance
- Makefile
- PDF assembly

### App Flow

**1. User Input**

Allocation (Q2-4)
- Free spaces available, separated by commas  
- Size of memory blocks we want to place  
- Strategy

Memory Address (Q5)
- Table information (base-length pairs)
- Desired segment and offset

Create Question objects based on these inputted data

**2. Threads kick off**
- Each solver will work in their own threads, called by their `solve()` method
- Whatever thread finishes first will lock the mutex, print, then unlock
