# The push swap project

Welcome to **push_swap**! This project challenges you to implement a sorting algorithm using only two stacks. The goal is to sort a list of integers in the most efficient way possible.

You are only allowed to use the two stacks and a limited set of operations to manipulate the integers:

- **push (pa, pb)**: Pushes the top element from one stack to the other.
- **swap (sa, sb, ss)**: Swaps the top two elements of a stack.
- **rotate (ra, rb, rr)**: Rotates all the elements of a stack up by one position.
- **reverse rotate (rra, rrb, rrr)**: Rotates all the elements of a stack down by one position.

The challenge of the project lies not only in correctly implementing these operations but also in doing so efficiently—minimizing the number of operations required to sort the data.

In the following sections, I will explain how I used data structures (specifically linked lists, which I implemented in my project) and algorithms (with a focus on the **Turk algorithm**, which I used to solve the problem) to optimize the sorting process. I will also provide a detailed explanation of the code I wrote to implement this logic and achieve the minimal number of operations required to score **100/100**!

# Table of Contents

[1. Data Structures - Linked Lists](https://github.com/gongabriela/push_swap/new/main?filename=README.md#data-structures---linked-lists)

  [1.1. What is a Linked List?](https://github.com/gongabriela/push_swap/new/main?filename=README.md#what-is-a-linked-list)
       
   [1.1.1. Advantages of Linked Lists](https://github.com/gongabriela/push_swap/new/main?filename=README.md#advantages-of-linked-lists)
       
   [1.1.2. Disadvantages of Linked Lists](https://github.com/gongabriela/push_swap/new/main?filename=README.md#disadvantages-of-linked-lists)
      
   [1.1.3. Linked Lists operations](https://github.com/gongabriela/push_swap/new/main?filename=README.md#linked-list-operations)
       
   [1.1.4. Creating a Linked List: About Structs](https://github.com/gongabriela/push_swap/new/main?filename=README.md#creating-a-linked-list-about-structs)

[2. Algorithms in a Nutshell](https://github.com/gongabriela/push_swap/new/main?filename=README.md#algorithms-in-a-nutshell)
   
  [2.1. What makes something an algorithm?](https://github.com/gongabriela/push_swap/new/main?filename=README.md#what-makes-something-an-algorithm)
   
  [2.2. Types of Algorithms](https://github.com/gongabriela/push_swap/new/main?filename=README.md#types-of-algorithms)
   
  [2.3. Complexity Analysis: Big O Notation](https://github.com/gongabriela/push_swap/new/main?filename=README.md#complexity-analysis-big-o-notation)

[3. Understanding the Turk Algorithm](https://github.com/gongabriela/push_swap/new/main?filename=README.md#understanding-the-turk-algorithm)
   
  [3.1. Phase 1: Pushing to Stack B](https://github.com/gongabriela/push_swap/new/main?filename=README.md#phase-1-pushing-to-stack-b)
       
   [3.1.1. Find its "best friend" in B](https://github.com/gongabriela/push_swap/new/main?filename=README.md#1-find-its-best-friend-in-b)
       
   [3.1.2. Calculate the cost](https://github.com/gongabriela/push_swap/new/main?filename=README.md#2-calculate-the-cost)
      
   [3.1.3. Sort the last three in A](https://github.com/gongabriela/push_swap/new/main?filename=README.md#3-sort-the-last-three-in-a)
  
  [3.2. Phase 2: Pushing Back to A](https://github.com/gongabriela/push_swap/new/main?filename=README.md#phase-2-pushing-back-to-a)
  
  [3.3. Final Step: Rotate A one last time](https://github.com/gongabriela/push_swap/new/main?filename=README.md#final-step-rotate-a-one-last-time)

[4. Explaining my projects code](https://github.com/gongabriela/push_swap/new/main?filename=README.md#explaining-my-projects-code)
   
   [4.1. Part I - Parsing the arguments and initializing the stacks](https://github.com/gongabriela/push_swap/new/main?filename=README.md#part-i---parsing-the-arguments-and-initializing-the-stacks)
   
   [4.2. Part II - Writing the functions for the movements](https://github.com/gongabriela/push_swap/new/main?filename=README.md#part-ii---writing-the-functions-for-the-movements)
   
   [4.3. Part III - Writing the algorithm](https://github.com/gongabriela/push_swap/new/main?filename=README.md#part-iii---writing-the-algorithm)

[5. Conclusion](https://github.com/gongabriela/push_swap/new/main?filename=README.md#conclusion)

# Data Structures - Linked Lists

In computer science, a data structure is a way of storing and organizing data on a machine to allow for efficient access and manipulation. You’re already familiar with one type of data structure: an array. An array is a collection of elements, each identified by an index. Arrays are simple but have fixed sizes, which makes them inflexible for tasks where the number of elements changes dynamically.

Choosing the correct data structure for your implementation is essential for efficient processing of data and memory usage. The right data structure for a specific task can significantly reduce time complexity and make algorithms run faster.

Data structures can be classified in several ways based on how the data is stored and accessed. They are generally divided into **linear data structures** (arrays, lists, stacks, and queues) and **non-linear data structures** (trees and graphs). If you want to deepen your understanding of data structures, I highly recommend watching this masterclass by FreeCodeCamp, available for free on YouTube: [Data Structures Masterclass](https://www.youtube.com/watch?v=B31LgI4Y4DQ&t=3170s). They also have an excellent class on algorithms that I recommend checking out: [Algorithms Masterclass](https://www.youtube.com/watch?v=8hly31xKli0).

Arrays are great for certain use cases but aren’t ideal for others. In the case of the **push_swap** project, I chose to implement **Linked Lists** for the stacks because of their flexibility. The masterclass linked above does a great job of explaining linked lists and how to perform basic operations (such as inserting a node, removing a node, and traversing a list), so I strongly encourage you to check it out. However, here’s a brief overview to get you started:

## What is a Linked List?

A linked list is a data structure used to store a collection of elements, where each element (or **node**) contains at least two components:

1. **Data**: The value to be stored in the node (e.g., an integer or a string).
2. **Pointer**: A reference to the next node in the list.

To better understand the difference between arrays and linked lists, think about how they store data:

- **Arrays** store elements in contiguous blocks of memory. We can access the elements directly by their index, which is very efficient.
- **Linked Lists** work a bit differently. Each node in the list contains not just data, but also a pointer to the next node. This means the nodes are not stored in contiguous memory locations. To access a node, we must traverse the list from the start (or from the end if it’s a doubly linked list).

In a **singly linked list**, each node has a pointer to the next node, and the last node points to `NULL` to signify the end of the list. In contrast, a **doubly linked list** has two pointers: one pointing to the next node and another pointing to the previous node. This allows for easier traversal in both directions.

### Advantages of Linked Lists

- **Dynamic Size**: Unlike arrays, linked lists can grow and shrink in size dynamically, which is ideal when the number of elements isn’t known ahead of time or can change frequently.
- **Efficient Insertions/Deletions**: Adding or removing elements, especially from the beginning or middle of the list, is efficient and doesn't require shifting other elements as arrays do.
- **Memory Efficiency**: Linked lists only allocate memory when needed, so they avoid the fixed-size limitation of arrays.

### Disadvantages of Linked Lists

- **Random Access is Not Possible**: Linked lists cannot be accessed randomly like arrays. To access an element, you must start from the head (or tail) and traverse through the nodes sequentially.
- **Overhead**: Each node in a linked list requires extra memory to store the pointer(s), making it less memory-efficient compared to arrays.
- **Complexity**: While linked lists are great for dynamic data storage, they introduce some complexity in terms of implementation and maintenance (e.g., managing pointers correctly).

### Linked List Operations

Before jumping into your **push_swap** implementation, it’s essential to understand how linked lists work. You can practice by coding some fundamental linked list operations that you'll use in **push_swap**. These include:

**Creation:**

- Start by creating a node. You’ll need to declare the node, allocate memory for it, and initialize its data.

**Insertion:**

You can insert elements at the **beginning**, **end**, or **middle** of the list.

- Inserting at the beginning of the list is **O(1)**, because it only involves modifying the head pointer.
- Inserting at the end in a **singly linked list** requires traversing the whole list, which is **O(n)** unless you maintain a pointer to the tail node.

**Deletion:**

Deleting an element from the **beginning**, **end**, or **middle** of the list can also be done efficiently:

- Removing from the head is **O(1)** since you just need to change the head pointer.
- Removing from the tail (in a singly linked list) requires finding the second-to-last node, which is **O(n)**.

**Traversal:**

To traverse a linked list, you start from the head and follow the **next** pointers until you reach `NULL` (end of the list). In a **doubly linked list**, you can also traverse backwards using the **prev** pointers.

**Searching:**

Searching for a specific value in a linked list requires checking each node one by one. In the worst case, this is **O(n)** since you have to check every node.

**Reversing:**

Reversing a linked list involves swapping the **next** (and **prev**, for doubly linked lists) pointers for each node. This operation can be done in **O(n)** time.

### Creating a Linked List: About Structs

In C, a **`struct`** (short for **structure**) is a user-defined data type that allows you to group multiple data types together into a single unit. In the case of a linked list, a `struct` is used to define the structure of each node. Here’s an example:

```c
typedef struct s_node
{
    int value;           // Data stored in the node (e.g., an integer)
    struct s_node *next; // Pointer to the next node in the list
    struct s_node *prev; // Pointer to the previous node (for doubly linked lists)
} t_node;
```

In this example:

- **Data** (`value`): Stores the actual data for the node (in this case, an integer).
- **Next Pointer** (`next`): Points to the next node in the list, enabling traversal.
- **Previous Pointer** (`prev`): Points to the previous node in the list, which is especially useful for doubly linked lists.

The `typedef` keyword is used to create an alias for the struct type. Instead of using `struct s_node` every time, you can simply use `t_node` to declare new nodes.

Once you’re comfortable with linked lists and their operations, you’re ready to dive into the next topic: algorithms! By understanding how linked lists work, you’ll be better equipped to efficiently implement sorting algorithms in the **push_swap** projec

# Algorithms in a Nutshell

An **algorithm** is a well-defined, step-by-step procedure or formula for solving a problem or performing a task. We use algorithms in real-life situations all the time—for example, a cake recipe is essentially an algorithm. It has a strict set of instructions, and if the steps are done out of order or with incorrect measurements, the result won’t be the cake the recipe intended.

In computer science, algorithms are fundamental to creating efficient solutions for various problems such as sorting, searching, and traversing graphs. They are typically designed to process data, solve computational problems, or automate processes in a way that minimizes time and resources. The goal of an algorithm is to produce the correct output for a given input—ideally in the most efficient way possible.

### What Makes Something an Algorithm?

To be considered a proper algorithm, it must satisfy all of the following characteristics:

- **Correctness**: Produces the correct output for every possible input.
- **Efficiency**: Minimizes resource consumption, such as time (time complexity) and memory (space complexity).
- **Finiteness**: Terminates after a finite number of steps.
- **Definiteness**: Each step must be clearly and unambiguously defined.
- **Input and Output**: Accepts input and produces output based on it.

## Types of Algorithms

Algorithms can be grouped based on the problems they solve or the techniques they use. Some common types include:

- **Sorting algorithms**
- **Searching algorithms**
- **Graph algorithms**
- **Greedy algorithms**

For the purpose of `push_swap`, you’ll primarily be focusing on **sorting algorithms**. Here are a few common ones:

- **Bubble Sort**: A simple comparison-based algorithm that repeatedly swaps adjacent elements if they’re in the wrong order. It's easy to understand but inefficient for large datasets (O(n²) time complexity).
- **Merge Sort**: A divide-and-conquer algorithm that splits the data into smaller parts, sorts them, and merges the results. More efficient than Bubble Sort with a time complexity of O(n log n).
- **Quick Sort**: Another divide-and-conquer algorithm that selects a pivot and partitions the data around it. Average time complexity is O(n log n), though the worst case can be O(n²).
- **Insertion Sort**: Builds the final sorted list one item at a time—much like sorting cards in your hand. It has a worst-case time complexity of O(n²), but it’s efficient for small or nearly sorted datasets.

For `push_swap`, the goal is to sort using only stack operations, so you'll need to adapt or create algorithms that are optimized for that structure and for minimizing the number of operations.

## Complexity Analysis: Big O Notation

You don’t need to *master* Big O notation for this project, but it’s useful to have a basic understanding.

Big O notation describes how an algorithm's time or space requirements grow as the input size increases. Some common complexities:

- **O(1)** – Constant time: performance doesn’t change with input size.
- **O(n)** – Linear time: performance scales directly with input size.
- **O(log n)** – Logarithmic time: performance increases slowly even as input size grows.
- **O(n²)** – Quadratic time: performance slows down dramatically as input grows, typical of algorithms with nested loops.

Knowing this can help you evaluate how well your algorithm might perform, especially when working with larger input sizes.

# Understanding the Turk Algorithm

The **Turk Algorithm** is a custom strategy widely used by 42 students to solve the *push_swap* project efficiently. It was first implemented by **A. Yigit Ogun**, who explains it in detail in [this Medium article](https://medium.com/@ayogun/push-swap-c1f5d2d41e97). I highly recommend checking it out — especially for the visual explanations, which really help everything click.

I personally tried several different implementations to meet the minimum movement requirements, and the Turk algorithm was the only one I could get to work well. I think the key to its success is that when you’re only **rotating** the stacks, the nodes that are meant to stay close to each other do stay close — which drastically reduces the number of moves needed when you’re reinserting everything at the end.

Yigit used a circular linked list in his implementation, but I was able to apply the same logic using just a **doubly linked list**.

The algorithm works by strategically pushing elements between the two stacks (**A** and **B**), always considering **cost** and **position**. Here’s how it goes:

## Phase 1: Pushing to Stack B

1. **Start by pushing the first two elements from Stack A to Stack B.**
2. After that, continue pushing elements from A to B **until only three elements remain in A**.

But from now on, we’re no longer pushing blindly — we analyze **every element in Stack A**, calculate the cost to move it, and always push the **cheapest** one next.

Here is a step by step process to calculate the cheapest number in A:

### 1. Find Its "Best Friend" in B

For each number in **A**, we look for its **best friend** in **B**. This is the number in B that is the **smallest number with the least difference than the one in A**.

For example, if we’re analyzing the number `4` in A, and B contains `7, 3, 9, 0` (with `7` at the top and `0` at the bottom), then the best friend of `4` is 3 — because 3 is the **smallest number than 4** in B, with the least difference. Note that there is also 0, which is also smaller than 4, but the difference between 4 and 0 is bigger than 4 and 3.

If there’s **no number in B greater than 4**, that means 4 would become the **smallest number** in B — and in that case, its best friend becomes the **biggest number in B**. This ensures that when 4 is pushed, it wraps around and maintains sort order.

### 2. Calculate the Cost

Now we calculate the cost of:

- Rotating **Stack B** so the best friend is at the top,
- Rotating **Stack A** so the number being pushed is also at the top,
- And finally pushing it from A to B.

We repeat this process for **each number in A**, and then choose the one with the **lowest cost** to push next.

Repeat this whole analysis after each push, until **only three numbers remain in Stack A**.

### 3. Sort the Last Three in A

Once you’re down to three numbers in Stack A, use a simple 3-element sort. This is easy and can be done in just a few moves.

## Phase 2: Pushing Back to A

Now that Stack A is sorted and Stack B contains the rest of the numbers, we start moving elements back **from B to A** — but using the **same logic in reverse**.

We analyze every number in **Stack B**, and again look for its **best friend** — but this time, it’s the **smallest number in A that is bigger than the number in B**.

For example, if we’re analyzing `3` in B and Stack A contains `1, 4, 6`, then the best friend of `3` is `4`.

If there’s **no bigger number in A**, it means the number in B would be the biggest if pushed to A, and its best friend becomes the **smallest number in A** — because it should be inserted after that.

As before, we calculate the cost to:

- Rotate A to bring the best friend to the top,
- Rotate B to bring the analyzed number to the top,
- And push the number from B to A.

Repeat this process until **B is empty**.

---

## Final Step: Rotate A One Last Time

After all elements are back in Stack A, it’s almost sorted — you just need to **rotate A** until the **smallest number is at the top**, and you're done!

# Explaining my project’s code

During the implementation of this project, what really slowed me down was the lack of organization while writing it. I recommend you to structure a pseudo-code first, and also to try and divide the functions as much as possible. The code is big, and nothing will fit in 25 lines anyway.

I divided my code in three parts. Let’s see how it goes:

## Part I - Parsing the Arguments and Initializing the Stacks

As per the subject guidelines, the list of integers can be received either as a single string or as separate arguments. If it’s passed as a single string, we need to split it into individual numbers. **Tip:** you can use `ft_split` from Libft for this — it makes your life easier.

Once the arguments are correctly split, we need to **validate** each one. Specifically, we check:

- Whether the argument is a valid number
- Whether it fits within the **integer** range (`INT_MIN` to `INT_MAX`)

As I was validating the arguments, I also started building the stack: for each valid number, I created a node, stored the integer in its `value` field, and added it to the end of my `stack_a` linked list.

After all the nodes are created, there are a couple more checks to do:

- **Duplicate check:** we must make sure there are no repeated numbers.
- **Sorted check:** if the list is already sorted, the program should exit silently — no need to do anything.

However, if any of the validations fail (invalid input, out-of-range values, or duplicates), we need to:

1. Print `"Error\n"` to `stderr`
2. Free all allocated memory
3. Exit the program gracefully

Always run your program through `valgrind` during development to ensure there are no memory leaks — especially when handling dynamic memory allocation!

To represent a stack, I created a custom `struct`, where I stored not only the `value`, but also several helper variables that I’ll use later in the algorithm, like `index`, `cost_a`, `cost_b`, etc.

## Part II - Writing the functions for the movements

Next, we need to implement the functions for the stack movements. I highly recommend doing this **before** starting the algorithm itself. It keeps things clean, focused, and way more organized.

Start by writing **each movement function individually**, and test them thoroughly — seriously, test them *a lot*. Make sure that your pointers are behaving exactly as expected, especially if you're using a doubly linked list. Verify that:

- `next` and `prev` pointers are updated correctly
- Edge cases (like moving the first or last node) are handled safely
- The list remains intact after multiple operations

Getting this part right is crucial because your entire algorithm depends on the correctness of these basic operations. If the movements break your list, the whole program falls apart — so it’s worth spending extra time here.

## Part III - Writing the algorithm

Okay, now for the main part: writing the algorithm itself. I’ll walk you through the pseudo-code I used, because I think it’s really clean and makes the step-by-step process easy to understand.

```c
//pseudo-code 

sorting_algorithm()
{
	while (ft_lstsize(*stack_a) > 3)
	{
		update_cost_a(); //cost of nodes in A to reach the top
		update_cost_b(); //cost of nodes in B to reach the top
		update_targets_of_stack_a(); //find the best friend of each A node in stack B
		find_cheaper_node(); //get the cheapest node in A to send to B
		node_to_top_a(); //bring cheapest node to top
		ft_pb(); 
	}
	sort_3(stack_a);
	while (ft_lstsize(*stack_b) > 0)
	{
		update_cost_a(); //cost of nodes in A to reach the top
		update_cost_b(); //cost of nodes in B to reach the top
		update_targets_of_stack_b(); //find the best friend of each B node in A
		find_cheaper_node(); //get the cheapest node in B to send to A
		node_to_top_b(); //bring cheapest node to top
		ft_pb();
	}
	update_cost_a(); //final check: what's cheaper - ra or rra?
	node_to_top_a(); //bring the smallest number to the top
}
```

**Important reminder:** we only bring nodes to the top by **rotating**. This ensures that each node and its bestie stay close to each other — which helps keep the final moves efficient and minimal.

# Conclusion

And that's a wrap! By breaking things down into manageable steps — parsing the input, creating the movement functions, and then tackling the algorithm — you'll have a solid and efficient `push_swap` solution. The Turk Algorithm might seem tricky at first, but once you get the hang of calculating the costs and keeping the "best friend" system tight, it really starts to make sense.

Don’t forget to test everything like crazy, keep things clean, and use tools like Valgrind to catch those sneaky memory leaks. It’ll save you headaches later.

Hopefully, this guide helped clear things up. If you hit a wall, just take a step back, simplify, and work through it one piece at a time. You've got this!
