from reportlab.lib import colors
from reportlab.graphics.shapes import *
from reportlab.graphics import renderPDF

data = [
    # Year  Month Predicted High  Low
     (2014, 6,    79.5,     80.5, 78.5),
     (2014, 7,    78.4,     80.4, 76.4),
     (2014, 8,    76.6,     79.6, 73.6),
     (2014, 9,    74.3,     79.3, 69.3),
     (2014, 10,   72.6,     77.6, 67.6),
     (2014, 11,   71.5,     77.5, 65.5),
     (2014, 12,   70.8,     77.8, 63.8),
     (2015, 1,    70.0,     77.0, 63.0),
     (2015, 2,    69.0,     77.0, 61.0),
     (2015, 3,    67.2,     76.2, 58.2),
     (2015, 4,    65.9,     74.9, 56.9)
]

# reportlab.graphics.shapes.Drawing(width=400, height=200)
drawing = Drawing(200, 150)

pred = [row[2]-40 for row in data]
high = [row[3]-40 for row in data]
low  = [row[4]-40 for row in data]
times = [200*((row[0] + row[1]/12.0) - 2014)-110 for row in data]

# reportlab.graphics.shapes.PolyLine
drawing.add(PolyLine(zip(times, pred), strokeColor=colors.blue))
drawing.add(PolyLine(zip(times, high), strokeColor=colors.red))
drawing.add(PolyLine(zip(times, low), strokeColor=colors.green))
# reportlab.graphics.shapes.String(x,y), beginning of left down point
drawing.add(String(65, 115, 'Sunspots', fontSize=18, fillColor=colors.red))

renderPDF.drawToFile(drawing, 'report1.pdf', 'Sunspots')
