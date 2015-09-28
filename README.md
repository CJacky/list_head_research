# list_head_research

Because I feel amazing about "struct list_head", I destructure the macro in list.h to research the list_head.

I still don'h know why a user-define struct can minus a offset and then can get the struct.



===============================================================================
9/28

I got it.

The struct elements next and prev records the list_head address.
When we get the address, we need do some subtraction to get the struct address we want.

&((strcut \<your struct name\>\*)0)->\<list_head name in struct\>

Above formula can get the offset of list_head in the struct you define.



