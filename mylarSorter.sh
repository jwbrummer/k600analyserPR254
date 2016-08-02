### Improved bash code for the K600 analyser's crappy sorter. Written by JWB on 31/07/2016.
### This shell script selectively chooses Mylar background runs to sort.

#bin/bash
runs=(1042 1045 1047 1050 1052 1055 1057 1058 1065 1070 1080 2016 2020 2023 2026 2029 2032 2033 2036 2039 2042 2045 2053 2059 2067 2070 2073 2076 2078 2081 3027 3033 3037 3040 3061 3065 3066 3070 3074 3078 3082 3085 3086 3089 3093 3097 3102 3105 3111 3117 3121 3126)

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
