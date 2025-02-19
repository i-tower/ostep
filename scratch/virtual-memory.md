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

 #### Advantages/Problems to Base/Bounds

**Advantage** It's fast and simple

**Disadvantages** It's hard to allocate. Needs large continuous blocks of memory
It's hard to expand and hard to share memory.
