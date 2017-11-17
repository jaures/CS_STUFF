import serial   # Needed for serial Communication
import time     # Needed for sleep function
import smtplib  # Needed for emailing
#import imaplib  # Needed for emailing (receiving)

/* MODFIY THIS SECTION */
usr = "cs101f17@gmail.com"      # Your Username
psw = "learning4lyfe"           # Your Password
rcp = "jauresade@gmail.com"     # The recipient
msg = "Someone is too close!"   # The Message to Send
com = "COM10"                   # The Com your Arduino Is on
/* END OF MODIFY SECTION */

msg_sent = 1

ser = serial.Serial(com, 9600, timeout=1)
while 1:
    try:
        # Read the Distance from Serial as an int
        distance = int(ser.readline());
        print(distance)
        if(distance < 10) and msg_sent is 0:
            server = smtplib.SMTP_SSL("smtp.gmail.com",465)
            server.login(usr, psw)
            server.sendmail(usr, rcp, msg)
            server.close()
            print("MSG SENT!")
            time.sleep(1)
        msg_sent = (msg_sent + 1) % 20 # Used to limit number of messages sent at once

    except :#ser.SerialTimeoutException:
        print('Data could not be read')
        time.sleep(1)
