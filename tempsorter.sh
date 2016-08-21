#bin/bash
runs=(3042 3056 3059 3062 3063 3067 3068 3071 3072 3075 3076 3079 3080 3083 3084 3087 3088 3091 3092 3095 3096 3099 3100 3103 3104 3107 3108 3109 3112 3113 3115 3118 3119 3120 3123 3124 3125)
echo "Array size: ${#runs[*]}"

for item in ${runs[*]}
do
  echo $item
  if [ $item -lt 10 ]
  then
      FILE="/home/wiggert/Documents/pr254/run0000"$item".mid.gz"
  elif [ $item -lt 100 ]
  then
      FILE="/home/wiggert/Documents/pr254/run000"$item".mid.gz"
  elif [ $item -lt 1000 ]
  then
      FILE="/home/wiggert/Documents/pr254/run00"$item".mid.gz"
  elif [ $item -lt 10000 ]
  then
      FILE="/home/wiggert/Documents/pr254/run0"$item".mid.gz"
  else
      echo "Unable to retrieve raw data files from Lenovo external HDD."
  fi
  echo $FILE
  if [ $item -lt 10 ]
  then
      FILE2="/home/wiggert/Desktop/offset-sorted/sorted0000"$item".root"
  elif [ $item -lt 100 ]
  then
      FILE2="/home/wiggert/Desktop/offset-sorted/sorted000"$item".root"
  elif [ $item -lt 1000 ]
  then
      FILE2="/home/wiggert/Desktop/offset-sorted/sorted00"$item".root"
  elif [ $item -lt 10000 ]
  then
      FILE2="/home/wiggert/Desktop/offset-sorted/sorted0"$item".root"
  else
      echo "Unable to move sorted data files."
  fi
  echo $FILE2
  if [ -e $FILE ]
  then
      if [ ! -e $FILE2 ]
      then
      ./analyzer -i $FILE
      mv /home/wiggert/Desktop/output.root $FILE2
      else
      echo "Destination file location not found."
      fi
  else
  echo "Source file location not found. Exiting shell script."
  break
  fi
done
