# push_swap
A program in C called push_swap which calculates and displays on the standard output the smallest program using its own instruction language that sorts the integer arguments received.

This project will sort data on a stack, with a limited set of instructions, using the lowest possible number of actions.

Part of the basic curriculum at <a href='http://42sp.org.br'> 42 São Paulo</a>.

## work_history

<details>
  <summary>Click to expand </summary>


  **June 6th 2021** - I set up the project structure and Makefile. It doesn't do anything right now, except for compiling, asking for an input, and reading your input back to you. Gotta start somewhere.

   **June 7th 2021** - Set up a basic error message function and created the structs that will hold my stacks. I will use circular doubly linked lists, as I think it'll make it easier to implement the stack rotation rules. I'm trying to make my code as human-readable as possible, as this is one of the skills I feel like I need to improve on. My next step will be to validate the input, and then to insert it into the list.

  **June 8th 2021** - Working on verifying if the input is valid. Current challenge is finding where is the best moment to verify if the input is above or below int limit.

  **August 19th 2021** - After a little 2-month break to focus on minishell, we're back to push_swap! All error handling is done, and the setup for my stacks is ready. I chose to use circular doubly linked lists to make rotation operations easier. I've also implemented basic stack operations, like pop, push and swap. Next step is to implement the push_swap moves.

  **August 22nd 2021** - Implemented all the rules described on the push_swap subject document. Next up is figuring out my sorting algorithm.

  **August 26nd 2021** - The sorting algorithms are working! I've implemented a bitwise radix sort for larger stacks and a selection sort for smaller stacks. Still gotta test it extensively, and see what I can optimize.
