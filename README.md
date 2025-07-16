# Student-capital

Distributed Lab test task. 

## Description

The program helps a student maximize their capital over the summer by simulating the process of buying, fixing, and selling laptops.

The program takes as input:
- The maximum number of laptops the student can buy (N)
- The initial amount of capital (C)
- A list of expected gains from selling each laptop
- A list of corresponding purchase prices

The algorithm works as follows:
- Sort all profitable laptops in ascending order by price.
- Iterate over this list and add all affordable laptops to a priority queue.
- From the queue, always pick the laptop with the maximum profit (gain - price).
- Repeat up to N times or until no more laptops can be bought.

As output, the program prints the final capital after at most N purchases.

## Technologies
- **Language:** C++17  
- **Build system:** GNU Make on Ubuntu (Linux)  

## How to run
1. Clone the project to a folder on your device:
   
   ```bash
   git clone https://github.com/kamawui/Student-capital.git
   ```
   
2. Navigate to the project folder:
   
   ```bash
   cd Student-capital
   ```
   
3. Compile the program:
   
   ```bash
   make
   ```
   
4. Run the program:
   ```bash
   ./calculate_capital
   ```

## Usage
After running the program provide required inputs when prompted: 
```bash
Enter number of laptops N to buy: <N>
Enter capital amount C: <C>
Enter laptops gains array: g_1 g_2 g_n
Enter laptops price array: p_1 p_2 p_n
```

## Output
The program will display the capital after summer ends:
```bash
Capital at the end of the summer: <C>
```

## Example
<img width="1156" height="273" alt="{C8053DA9-3331-461E-9B4A-3F2586D63494}" src="https://github.com/user-attachments/assets/9106d89c-57c9-4c9b-a1ea-14343cdfbe71" />

## Efficiency and complexity
1) Getting laptops from terminal — O(K), K - number of laptops.
2) Sorting laptops by price increase — O(KlogK)
3) Adding all affordable laptops to priority queue where the top element has the best profit — O(KlogK)
4) Getting laptops with the best profit from priority queue — O(NlogK), N - number of laptops to buy

In total:
O(KlogK + NlogK) = O(KlogK)

## Time to implement the task
Up to 4 hours.

