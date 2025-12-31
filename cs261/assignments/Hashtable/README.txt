      ___                        ___           ___           ___           ___           ___               
     /  /\           ___        /  /\         /  /\         /  /\         /  /\         /  /\      __      
    /  /:/          /__/\      /  /::|       /  /::\       /  /::\       /  /::\       /  /:/     |  |\    
   /  /:/           \__\:\    /  /:|:|      /  /:/\:\     /  /:/\:\     /  /:/\:\     /  /:/      |  |:|   
  /  /::\____       /  /::\  /  /:/|:|__   /  /::\ \:\   /  /::\ \:\   /  /::\ \:\   /  /:/       |  |:|   
 /__/:/\:::::\   __/  /:/\/ /__/:/_|::::\ /__/:/\:\_\:| /__/:/\:\ \:\ /__/:/\:\_\:\ /__/:/        |__|:|__ 
 \__\/~|:|~~~~  /__/\/:/~~  \__\/  /~~/:/ \  \:\ \:\/:/ \  \:\ \:\_\/ \__\/~|::\/:/ \  \:\        /  /::::\
    |  |:|      \  \::/           /  /:/   \  \:\_\::/   \  \:\ \:\      |  |:|::/   \  \:\      /  /:/~~~~
    |  |:|       \  \:\          /  /:/     \  \:\/:/     \  \:\_\/      |  |:|\/     \  \:\    /__/:/     
    |__|:|        \__\/         /__/:/       \__\::/       \  \:\        |__|:|~       \  \:\   \__\/      
     \__\|                      \__\/            ~~         \__\/         \__\|         \__\/              
(Kimberly)


Name: Bruce Yan
ONID: yanbr@oregonstate.edu

Description: This assignment is a type of data structure called a hash table. Data structures are containers which work to store
data in various different methods. The hash table in this program consists of an array linked list pointers, which point to a linked list 
where the individual data will be stored. The difference between a hash table and other data types is that it uses a hash function to organize 
and manage the data in order to efficiently store the data for easier lookup in the future. Our hash function will assign an index value to a data key
where it will then be stored in our array of linked list pointers based on the index. For example, if my data key is 5, and I pass it through my hash 
function and I get an index of 3, I will acess my hash table at index 3, access the linked list pointer in that index and store my data in that list or bucket.
There will obviously be collisions, where some data keys will give the same index number through the hash function, we handle this by creating those lists or buckets
and grouping like data keys with the same index values. Once load factor, or the number of elements divided by the capacity of the hash table exceeds 4,
we will have to double our hash table capacity and reassign all the elements in our old table. Overall, my program is an implementation of a hash table
data structure which will simply store, remove, and look up data values.

Instructions: Assuming that you have accessed my folder and are in the same directory as all the files, you will have to compile the code by typing 
"make" into the terminal. This will compile the code. To the run the code please type in the following: "valgrind ./test_ht". This will allow you to 
check for memory leaks and other useful information while running the code. 

Limitations: There are no limitations besides the fact that once you run the code, you not able to play around with it and it will simply display information.

 __   ___   __     ___      ___  _______    _______   _______   ___       ___  ___  
|/"| /  ") |" \   |"  \    /"  ||   _  "\  /"     "| /"      \ |"  |     |"  \/"  | 
(: |/   /  ||  |   \   \  //   |(. |_)  :)(: ______)|:        |||  |      \   \  /  
|    __/   |:  |   /\\  \/.    ||:     \/  \/    |  |_____/   )|:  |       \\  \/   
(// _  \   |.  |  |: \.        |(|  _  \\  // ___)_  //      /  \  |___    /   /    
|: | \  \  /\  |\ |.  \    /:  ||: |_)  :)(:      "||:  __   \ ( \_|:  \  /   /     
(__|  \__)(__\_|_)|___|\__/|___|(_______/  \_______)|__|  \___) \_______)|___/      
                                                                                    