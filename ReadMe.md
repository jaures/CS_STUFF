Setting Up Emailing Script
---

So you've just finished your arduino hardware and you want to make it able to email. 

### Installing PySerial

First thing we need to do is make sure we have pySerial install on the computer so our program
can talk with our arduino

![alt text](https://github.com/jaures/CS_STUFF/raw/master/installSerial.JPG "Install PySerial")

### Checking Our COM

Next we need to know what com port the arduino is speaking to our computer from. You can easily
check it by opening up your arduino ide and looking under the tools menu

![alt text](https://github.com/jaures/CS_STUFF/raw/master/noteComNumber.jpg "Check Your COM")

### Modifying the Script

Now we have all the information we need to modify our script to work with the code. Looking at the
full script, there is a section that is labeled for modifying
![alt text](https://github.com/jaures/CS_STUFF/raw/master/fullscript.JPG "Full Script")

Focusing in on that modify section, we see the different things we can change, such as the user,
their password, the recipient, the message to send, and the COM port your are on.

![alt text](https://github.com/jaures/CS_STUFF/raw/master/modscript.JPG "Modifiable Section")

If we change those, we can modify how the script sends its emails!
