## Virtual Memory

Every program has its own virtual address space


#### Goals

* **Transparency**  The fact that memory is virtualized should have no impact on a running program. As far as the program is aware it has some actual physical memory

* **Efficiency** Virtualization should us as few resources as possible.

* **Protection** The should ensure that processes are protected from each other and the OS itself is protected from processes. Processes should be **isolated**

Using IO at sizes other than the os' preferred sizes will cause problems. Reads and writes can be very slow. For example the smallest addressable bit of memory is a byte. If you want to change a single bit you need to do some combination bit shifting and a mask which takes more time.


The os has to translate between the virtual address and real physical memory. Virtual address space is potentially very large (2^64 on a 64 bit machine)
 
#### How does this translation happen

The cpu has a memory management unit. The mmu has 2 register a base and a bounds. Every user address is a virtual address you as a program have no idea where the program memory actually lives in physical memory. 

The **base** is some offset that determines where the actual physical location of the memory is. If a program has an virtual address at 10 and the os sets its base at 100 the physical address of the memory will be at 110.

The **bounds** some size value of the address space the process owns. mmu checks the address is within bound and raises an exception if its out of bounds.

 #### Advantages/Problems to Base/Bounds/Address relocation

**Advantage** It's fast and simple

**Disadvantages** It's hard to allocate. Needs large continuous blocks of memory
It's hard to expand and hard to share memory.

#### OS Involvement

This address relocation is done directly in hardware but the os must get involved at some points

* During a context switch the OS must update the base and bounds (this must be a privileged operation or any program could write arbitrary data)

* Os may want to defragment memory. The os will have to stop the running program make a non destructive copy, change the base and bounds, and make the processes runnable again.

* If the os defragments or allocates more memory for a process it needs to make sure that newly allocated memory is zeroed or another process may be able to read the freed memory of another process

#### Segmentation

* Multiple base/bounds pairs per process. One pair per logical region of address space
  - A little more for the os to do, needs to know which segment of code have which base/bounds.

#### Paging

Divide up the virtual address space into fixed-size pages. Typically 4kb

* **Problems** 
  - There is a lot of information stored in memory about each process in order to manage memory...
  -

* **VPN** Each address consists of a virtual page number and an offset

'''
00|101 < Offset
^
|
Virtual Page Number
'''

We translate the virtual page number into a (PFN) Physical Frame Number. The offset stays the same.

Translation Information: 
- Store this in memory somewhere
- Stored in a data structure called a page table
  - This is sometimes defined in hardware.



## Swaping Pages to Disk

#### Homework Questions

1. Yes  it makes sense. User time column is showing the percentage of cpu being used for a user space program. It idle's around 1 percent and when running mem goes up to around 9% running two instances of mem straightforwardly increases the user time useage by another ~8%

2. The  free column changes by approximately 1gb when running mem with ./mem 1024 and increases by around the same amount when ending the program.

3. Using around 13 gb the ./mem program takes quite a while to start up. Around 10gb of data needs to be swapped out of memory to make room for the program to run. After this is done nothing is swapped out and very little is swapped in. Presumably what's being swapped in is related to background os processes or maybe firefox playing music in the background.