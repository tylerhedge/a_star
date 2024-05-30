from matplotlib import pyplot as plt

f = open("graph.txt", "r")
startLine = f.readline().split('_')
startX = startLine[0]
startY = startLine[1]

goalLine = f.readline().split('_')
goalX = goalLine[0]
goalY = goalLine[1]

plt.plot(float(startX), float(startY), "g^", markersize=20)
plt.plot(float(goalX), float(goalY), "y*", markersize=20)

line = f.readline() 
while line.strip() != "PATH":
    line = line.split()
    x = []
    y = []
    for point in line:
        x.append(float(point.split('_')[0]))
        y.append(float(point.split('_')[1]))
    x.append(x[0])
    y.append(y[0])
    plt.plot(x, y, 'b')
    
    plt.xlim(0, 12)
    plt.ylim(0, 12)
    line = f.readline()

x = []
y = []
for line in f.readlines():
    line = line.split('_')
    x.append(float(line[0]))
    y.append(float(line[1]))

plt.plot(x, y, 'r--')

plt.show()
