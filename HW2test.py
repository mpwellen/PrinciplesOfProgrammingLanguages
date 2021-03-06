#Michael Wellen
import csv

totalDistance=float(0)
shotDistance=float(0)
numIndexError=int(0)
numValueError=int(0)
numZeroError=int(0)
average=float(0)
shotDistance=float(0)
madeShots=int(0)
result=int(0)
name=str("")
date=str("")
match=str("")
totalRecords=int(-1)
line_number=int(0)

csv_reader=csv.reader('test-data.csv',delimiter=',')

line=infile.readline(line_number)
for line in csv_reader:
    if(totalRecords==-1):
        totalRecords+=1
        continue
    try:
        row=line.split(',')
        totalRecords+=1
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
        print("Value Error",totalRecords)
        numValueError+=1
        pass
    except IndexError:
        print("Index Error",totalRecords)
        numIndexError+=1
        pass
try:
    average=float(totalDistance/madeShots);
    average=str(round(average,2))
    
except ZeroDivisionError:
    print("There were no shots made, get new data")
    madeShots="No shots were made"
    average="No shots were made, so this calculation does not work"
    
    numZeroError+=1
finally:
    print("Total number of records:",totalRecords)
    print("Number of records used:",madeShots)
    print("The average made shot is at meters:",average)
    print("numValueErrors:",numValueError)
    print("numIndexError:",numIndexError)
    print("num of Divide by zero errors:",numZeroError) 
    

                     
                
