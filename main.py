import serial
# from serial import Serial
import cv2
import cvzone
from HandTrackingModule import handDetector
#import HandTrackingModule as htm

serialcomm = serial.Serial('/dev/ttyACM0',9600)
serialcomm.timeout = 1
cap = cv2.VideoCapture(-1)
detector = handDetector(detectionCon=0.5,maxHands=1)
while True:
    success,img = cap.read()
    # if img is None:
    #     print('Wrong path:', path)
    # else:
    #     img = cv2.resize(img,(500,350))
        # pixels.append(img)
    img = cv2.resize(img,(500,350))
    img = detector.findHands(img)
    l = detector.findPosition(img)
    if l:
        f = detector.fingersUp()
        s = (list(map(int,f)))
        w = 0
        for q in s:
            w +=q
        e ='\n'
        serialcomm.write(str(w).encode())
        serialcomm.write(e.encode())
    cv2.imshow('Image',img)
    cv2.waitKey(1)
