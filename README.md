This reposity contains my linux driver development source code. Previously, I had learned about the linux operating system as a whole, and wanted to find out more about the linux kernel. This project enabled me to do that, as while I understand it is basic, there are a lot of components within these 50 some-odd lines of code which enabled me deepen my understanding of the user-kernel relationship.

Within the driver there is the basic init() and exit() function, however there are also read and write functions that I have implemented in order to observe communication between the user and the kernel. 

In the processing of developing this, I gained a much deeper understanding of the linux file system, as I got to use /proc/ (virutal file) to store my driver in (and using proc_ops to set up my read and write). For debugging, I used lsmod to check the current state of the module (if active) and dmesg in order to check the kernel log buffer. I used a makefile in order to modularize the runtime setup. 

In terms of the tech stack, I used Multipass in order to host my VM, which has Ubuntu injected into it. 

In this repository, you'll find my source code, a makefile, as well as a small python script I wrote that activates a read from the user space (activating my driver). 
