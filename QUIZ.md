### How does the DevBoard handle received serial messages? How does this differ from the naïve approach? It is managed now by the LockSerial. Also helps with control the LED from our computer. The naive approach can send bytes from the DevBoard to our computer but not the other way around. In order to do the other way around we send bytes from the DevBoard to our computer

### What does `detached_callback` do? What would happen if it wasn't used? The call bacl will hold the function to get excuted later in another function when we call it there, and it helps passing a function to another function. 

### What does `LockedSerial` do? Why is it _necessary_? Because wihtout it, it will be possible that multiple threads could try to use the serial port at once, this would cause undefined behavior. In order to solve this problem we need to wrap the Serial object in a lock.
