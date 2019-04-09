#Michael Wellen

totalDistance=float(0)
shotDistance=float(0)
numIndexError=int(0)
numValueError=int(0)
numZeroError=int(0)
numCorrectValue=int(0)
average=float(0)
madeShots=int(0)
result=int(0)
name=str("")
date=str("")
match=str("")

totalRecords=int(-1)
line_number=int(0)

infile=open('test-data.csv','r')

line=infile.readline(line_number)
for line in infile:
    if(totalRecords==-1):
        totalRecords+=1
        continue
    try:
        totalRecords+=1
        row=line.split(',')
        result=int(row[4])
        shotDistance=float(row[2])
        date=str(row[0])
        match=str(row[1])
        name=str(row[3])
        if (name==""):
            raise IndexError
        if (date==""):
            raise IndexError
        if (match==""):
            raise IndexError
       
        if(result==1):
            totalDistance=totalDistance+shotDistance
            madeShots+=1
    except ValueError:
      #  print("Value Error",totalRecords)
        numValueError+=1
        pass
    except IndexError:
      #  print("Index Error",totalRecords)
        numIndexError+=1
        pass
    else:
        numCorrectValue+=1
try:
    average=float(totalDistance/madeShots);
    average=str(round(average,2))
    
except ZeroDivisionError:
    print("There were no shots made, get new data")
    numZeroError+=1
finally:
    print("Total number of records:",totalRecords)
    print("Number of records used:",madeShots)
    print("The average made shot is at meters:",average)
    print("numValueErrors:",numValueError)
    print("numIndexError:",numIndexError)
    print("num of Divide by zero errors:",numZeroError)
    print("num of correct entries in csv:",numCorrectValue)
    

                     
                
