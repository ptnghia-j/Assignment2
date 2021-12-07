__App Flow__

### 1. User Input

Allocation (Q2-4)
- Free spaces available, separated by commas  
- Size of memory blocks we want to place  
- Strategy

Memory Address (Q5)
- Table information (segment-length pairs)
- Desired segment and offset

Create Question objects based on these inputted data

### 2. Threads kick off
- Each solver will work in their own threads, called by their `solve()` method
- Whoever finishes first will lock the mutex, print, then unlock
