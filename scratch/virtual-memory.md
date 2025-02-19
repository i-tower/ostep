## Virtual Memory

Every program has its own virtual address space


#### Goals

* **Transparency**  The fact that memory is virtualized should have no impact on a running program. As far as the program is aware it has some actual physical memory

* **Efficiency** Virtualization should us as few resources as possible.

* **Protection** The should ensure that processes are protected from each other and the OS itself is protected from processes. Processes should be **isolated**

Using IO at sizes other than the os' preferred sizes will cause problems. Reads and writes can be very slow. For example the smallest addressable bit of memory is a byte. If you want to change a single bit you need to do some combination bit shifting and a mask which takes more time.


The os has to translate between the virtual address and real physical memory. Virtual address space is potentially very large (2^64 on a 64 bit machine)


