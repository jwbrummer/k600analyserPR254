### Improved bash code for the K600 analyser's crappy sorter. Written by JWB on 31/07/2016.
### This shell script selectively chooses carbon background runs to sort.

#bin/bash
runs=(1033 1034 1035 1048 1054 1069 3101)

echo "Array size: ${#runs[*]}"

###for item in ${runs[*]}
###do
###    printf "   %s\n" $item
###done

for item in ${runs[*]}
do
  echo $item
  if [ $item -lt 10 ]
  then
      FILE="/media/wiggert/Lenovo/PR254/unsortedRuns/run0000"$item".mid.gz"
  elif [ $item -lt 100 ]
  then
      FILE="/media/wiggert/Lenovo/PR254/unsortedRuns/run000"$item".mid.gz"
  elif [ $item -lt 1000 ]
  then
      FILE="/media/wiggert/Lenovo/PR254/unsortedRuns/run00"$item".mid.gz"
  elif [ $item -lt 10000 ]
  then
      FILE="/media/wiggert/Lenovo/PR254/unsortedRuns/run0"$item".mid.gz"
  else
      echo "Unable to retrieve raw data files from Lenovo external HDD. Sucker."
  fi
  echo $FILE
  if [ $item -lt 10 ]
  then
      FILE2="/media/wiggert/Lenovo/PR254/sortedRuns/sorted0000"$item".root"
  elif [ $item -lt 100 ]
  then
      FILE2="/media/wiggert/Lenovo/PR254/sortedRuns/sorted000"$item".root"
  elif [ $item -lt 1000 ]
  then
      FILE2="/media/wiggert/Lenovo/PR254/sortedRuns/sorted00"$item".root"
  elif [ $item -lt 10000 ]
  then
      FILE2="/media/wiggert/Lenovo/PR254/sortedRuns/sorted0"$item".root"
  else
      echo "Unable to move sorted data files Lenovo external HDD. Wuss."
  fi
  echo $FILE2
  if [ -e $FILE ]
  then
      if [ ! -e $FILE2 ]
      then
      echo $FILE
      echo $FILE2
      ./analyzer -i $FILE
      mv output.root $FILE2
      fi
  fi
done
