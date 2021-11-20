# Alejandro Valencia
# Python-Projects:Animation for dat files
# Update: 20 November, 2021


#/***********************************************************************
#*  This program reads .dat files created by another programming        *
#*    langauge and plots an animation                                   *
#***********************************************************************/


import os
import numpy as np
import matplotlib.pyplot as plt


#/***********************************************************************
#*  Read 2 Column file Function                                         *
#***********************************************************************/

 
def ReadTwoColumnFile(filename):
  with open(filename,"r") as data:
    x = []
    y = []

    for line in data:
      p = line.split()
      x.append(float(p[0]))
      y.append(float(p[1]))

  return x, y


#/***********************************************************************
#*  Main Program                                                        *
#***********************************************************************/

## []:Grab data
path = './Output'           # Path where forces.h5 files are located
entities = os.listdir(path)   # Grab files in path
entities.sort()               # Sort entities in order

# []:Loop through data files
i = 1
for fname in entities:

  # []:Read Data
  x, u = ReadTwoColumnFile(path + "/" +fname)

  # []:Plot
  plt.plot(x,u)
  plt.pause(0.02)
  if (i < entities.__len__()):
      plt.gcf().clear()
  
  i = i + 1

#end k
 
plt.show()
 
