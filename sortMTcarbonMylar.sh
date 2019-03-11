#/bin/bash

# Sort a run create triton tree after finished and overwrite/delete the sorted run.
# The only things to change are the runs in the array location of midas files and where to store the triton trees (which must be set in single-triton-tree-generator.cpp).

runsCarbon=(1033 1034 1035 1048 1054 1069)
runsMT=(1060 1061 1071 1075 2013 3024 3030 3034 3041 3043 3044 3045 3046 3047 3048 3049 3050 3051 3052 3053 3054 3055 3060 3064 3069 3073 3077 3081 3086 3090 3094 3098 3106 3110 3116 3122)
runsMylar=(1042 1045 1047 1050 1052 1055 1057 1058 1065 1070 1080 2016 2020 2023 2026 2029 2032 2033 2036 2039 2042 2045 2053 2059 2067 2070 2073 2076 2078 2081 3027 3033 3037 3040 3061 3065 3066 3070 3074 3078 3082 3085 3089 3093 3097 3102 3105 3111 3117 3121 3126)


echo "Carbon Array size: ${#runsCarbon[*]}"

for item in ${runsCarbon[*]}

do
    echo $item
    if [ $item -lt 10 ]
    then
       FILE="/home/wiggert/Desktop/unsorted/run0000"$item".mid.gz"
   elif [ $item -lt 100 ]
    then
       FILE="/home/wiggert/Desktop/unsorted/run000"$item".mid.gz"
   elif [ $item -lt 1000 ]
    then
       FILE="/home/wiggert/Desktop/unsorted/run00"$item".mid.gz"
   elif [ $item -lt 10000 ]
    then
       FILE="/home/wiggert/Desktop/unsorted/run0"$item".mid.gz"
   else
       echo "Unable to retrieve run file to analyse."
   fi

   echo "Preparing to sort: "
   echo $FILE
   FILE2="single-triton-tree-generator.cpp("$item")"
   echo $FILE2

   if [ -e $FILE ]
   then
        echo "Analysing run..."
       ./analyzer -i $FILE
       echo "Creating triton tree..."
       root -l -q $FILE2
       echo "Triton tree created successfully. Run $item finished."
   else
       echo "Run file not found."
   fi
done

echo "MT Array size: ${#runsMT[*]}"

for item in ${runsMT[*]}

do
    echo $item
    if [ $item -lt 10 ]
    then
       FILE="/home/wiggert/Desktop/unsorted/run0000"$item".mid.gz"
   elif [ $item -lt 100 ]
    then
       FILE="/home/wiggert/Desktop/unsorted/run000"$item".mid.gz"
   elif [ $item -lt 1000 ]
    then
       FILE="/home/wiggert/Desktop/unsorted/run00"$item".mid.gz"
   elif [ $item -lt 10000 ]
    then
       FILE="/home/wiggert/Desktop/unsorted/run0"$item".mid.gz"
   else
       echo "Unable to retrieve run file to analyse."
   fi

   echo "Preparing to sort: "
   echo $FILE
   FILE2="single-triton-tree-generator.cpp("$item")"
   echo $FILE2

   if [ -e $FILE ]
   then
        echo "Analysing run..."
       ./analyzer -i $FILE
       echo "Creating triton tree..."
       root -l -q $FILE2
       echo "Triton tree created successfully. Run $item finished."
   else
       echo "Run file not found."
   fi
done

echo "Mylar Array size: ${#runsMylar[*]}"

for item in ${runsMylar[*]}

do
    echo $item
    if [ $item -lt 10 ]
    then
       FILE="/home/wiggert/Desktop/unsorted/run0000"$item".mid.gz"
   elif [ $item -lt 100 ]
    then
       FILE="/home/wiggert/Desktop/unsorted/run000"$item".mid.gz"
   elif [ $item -lt 1000 ]
    then
       FILE="/home/wiggert/Desktop/unsorted/run00"$item".mid.gz"
   elif [ $item -lt 10000 ]
    then
       FILE="/home/wiggert/Desktop/unsorted/run0"$item".mid.gz"
   else
       echo "Unable to retrieve run file to analyse."
   fi

   echo "Preparing to sort: "
   echo $FILE
   FILE2="single-triton-tree-generator.cpp("$item")"
   echo $FILE2

   if [ -e $FILE ]
   then
        echo "Analysing run..."
       ./analyzer -i $FILE
       echo "Creating triton tree..."
       root -l -q $FILE2
       echo "Triton tree created successfully. Run $item finished."
   else
       echo "Run file not found."
   fi
done

OUTPUT="output.root"
if [ -e $OUTPUT ]
then 
    echo "Deleting..."
    rm -f $OUTPUT
    echo "Output file deleted. Sorter finished."
else
    echo "No output.root file to delete. Sorter finished."
fi