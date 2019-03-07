#/bin/bash

# Sort a run  create triton tree after finished and overwrite/delete the sorted run.
# The only things to change are the runs in the array  location of midas files and where to store the triton trees (which must be set in single-triton-tree-generator.cpp).

### Run numbers: 1040 1041 1043 1044 1046 1049 1051 1053 1056 1059 1062 1063 1064 1066 1067 1068 1072 1073 1076 1077 1078 1079 2012 2014 2015 2017 2018 2019 2021 2022 2024 2025 2027 2028 2030 2031 2034 2035 2037 2038 2040 2041 2043 2044 2056 2057 2058 2060 2061 2062 2063 2066 2068 2069 2071 2072 2074 2075 2077 2079 2080 2082 2083 2085 3025 3026 3031 3032 3035 3036 3038 3039 3042 3056 3059 3062 3063 3067 3068 3071 3072 3075 3076 3079 3080 3083 3084 3087 3088 3091 3092 3095 3096 3099 3100 3103 3104 3107 3108 3109 3112 3113 3115 3118 3119 3120 3123 3124 3125

runs=(3118 3119 3120 3123 3124 3125)

echo "Array size: ${#runs[*]}"

for item in ${runs[*]}

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