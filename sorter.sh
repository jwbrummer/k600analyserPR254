### Looks like in these scripts the general consensus is to use three hash signs to denote a comment. Anyway, this sorter.sh
### has been modified specifically for PR254 so that it looks for the unsorted data on my Lenovo external HDD and moves the
### sorted data onto Lenovo as well. JWB

#/bin/bash

for COUNT in {63..1080}

do
  echo $COUNT
  if [ $COUNT -lt 10 ]
  then
      FILE="/media/wiggert/Lenovo/PR254/unsortedRuns/run0000"$COUNT".mid.gz"
  elif [ $COUNT -lt 100 ]
  then
      FILE="/media/wiggert/Lenovo/PR254/unsortedRuns/run000"$COUNT".mid.gz"
  elif [ $COUNT -lt 1000 ]
  then
      FILE="/media/wiggert/Lenovo/PR254/unsortedRuns/run00"$COUNT".mid.gz"
  elif [ $COUNT -lt 10000 ]
  then
      FILE="/media/wiggert/Lenovo/PR254/unsortedRuns/run0"$COUNT".mid.gz"
  else
      echo "Unable to retrieve raw data files from Lenovo external HDD. Sucker."
  fi
  echo $FILE
  if [ $COUNT -lt 10 ]
  then
      FILE2="/media/wiggert/Lenovo/PR254/sortedRuns/sorted0000"$COUNT".root"
  elif [ $COUNT -lt 100 ]
  then
      FILE2="/media/wiggert/Lenovo/PR254/sortedRuns/sorted000"$COUNT".root"
  elif [ $COUNT -lt 1000 ]
  then
      FILE2="/media/wiggert/Lenovo/PR254/sortedRuns/sorted00"$COUNT".root"
  elif [ $COUNT -lt 10000 ]
  then
      FILE2="/media/wiggert/Lenovo/PR254/sortedRuns/sorted0"$COUNT".root"
  else
      echo "Unable to move sorted data files Lenovo external HDD. Wuss."
  fi
  echo $FILE2
  if [ -e $FILE ]
  then
      if [ ! -e $FILE2 ]
      then
      echo $FILE
      ./analyzer -i $FILE
      mv output.root $FILE2
      fi
  fi
done
