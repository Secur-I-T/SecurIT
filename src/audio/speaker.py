import time
import grovepi
import pygame

buzzer = 3
grovepi.pinMode(buzzer,"OUTPUT")

pygame.mixer.init()
pygame.mixer.music.load("audioCAT.wav")
pygame.mixer.music.play()
while pygame.mixer.music.get_busy() == True:
    continue