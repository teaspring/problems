from reportlab.pdfgen import canvas
from reportlab.lib.units import inch
import os

name = "hello.pdf"
if os.path.exists(name):  os.system("rm " + name)
c = canvas.Canvas(name)

# move the origin up and to the left
c.translate(inch, inch)
# define a large font
c.setFont("Helvetica", 80)
# choose some color
c.setStrokeColorRGB(0.2, 0.5, 0.3)
c.setFillColorRGB(0.3,0,0.5)
# draw a rectangle. (x,y) is its left down point
c.rect(inch, inch, 6*inch, 9*inch, fill=1)
# rotate x and y coordinate axis in counter-clockwise!
# make text go straight up
c.rotate(90)
# change text color
c.setFillColorRGB(0,0,0.5)
# say hello. text is drawn from left to right in area I of coordinate system 
# note after rotate the y coord needs to be negative
c.drawString(1*inch, -2*inch, "hello") 
c.showPage()
c.save()
