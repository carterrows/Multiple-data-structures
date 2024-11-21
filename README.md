Carter Rows - 1170615
October 13, 2023

IMPLEMENTATION:

- "arraydouble" is functional
- "llheadonly" is functional
- "llheadtail" is functional

EXCECUTION TIMES:

"arraydouble" - On average: 0 minutes, 0.317199 second per run
"llheadonly" - On average: 0 minutes, 22.836988 second per run
"llheadtail" - On average: 0 minutes, 0.356470 second per run

As seen above, the arraydouble program is the fastest of the 3, being slightly faster than llheadtail. This is because we dont have to traverse any lists like in the llheadonly program, or update any pointers. We simply get a new record ID and insert it into the next index in our array. Doubling the size of the array every time we overflow does not seem to have a major affect on the execution speed.

The big difference comes between the llheadtail and llheadonly programs. The huge time discrepancy here is due to the nature of only having a pointer to the head of the list, and the fact we are appending. Every time we add a node to the list, the time it will take for the next node to be added is increased linearly. So, when processing huge data sets with 100,000 nodes needing to be added, the llheadonly program has to traverse all the way to the end of the list every time a new node is added. This problem is solved by having a tail pointer along with the head pointer. The tail pointer allows us to teleport to the end of the list to append the new node, meaning adding a new node to the list does not take longer depending on the current size of the list.

VALGRIND:

All 3 programs correctly free all allocations, and no leaks are possible.