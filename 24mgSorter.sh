#bin/bash
###1040 1041 1043 1044 1046 1049 1051 1053 1056 1059 1062 1063 1064 1066 1067 1068 1072 1073 1076 1077 1078 1079 2012 2014 2015 2017 2018 2019 2021 2022 2024 2025 2027 2028 2030 2031 
runs=(3099 3100 3103 3104 3107 3108 3109 3112 3113 3115 3118 3119 3120 3123 3124 3125)

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
	FILE="/home/wiggert/Desktop/mapping/unsorted/run0000"$item".mid.gz"
    elif [ $item -lt 100 ]
    then
	FILE="/home/wiggert/Desktop/mapping/unsorted/run000"$item".mid.gz"
    elif [ $item -lt 1000 ]
    then
	FILE="/home/wiggert/Desktop/mapping/unsorted/run00"$item".mid.gz"
    elif [ $item -lt 10000 ]
    then
	FILE="/home/wiggert/Desktop/mapping/unsorted/run0"$item".mid.gz"
    else
	echo "Unable to retrieve raw data files from Lenovo external HDD. Sucker."
    fi
    echo $FILE
    if [ $item -lt 10 ]
    then
	FILE2="/home/wiggert/Desktop/mapping/sorted/sorted0000"$item".root"
    elif [ $item -lt 100 ]
    then
	FILE2="/home/wiggert/Desktop/mapping/sorted/sorted000"$item".root"
    elif [ $item -lt 1000 ]
    then
	FILE2="/home/wiggert/Desktop/mapping/sorted/sorted00"$item".root"
    elif [ $item -lt 10000 ]
    then
	FILE2="/home/wiggert/Desktop/mapping/sorted/sorted0"$item".root"
    else
	echo "Unable to move sorted data files Lenovo external HDD. Wuss."
    fi
    echo $FILE2
    if [ -e $FILE ]
    then
	if [ ! -e $FILE2 ]
	then
	    ./analyzer -i $FILE
	    mv /home/wiggert/Desktop/output.root $FILE2
	fi
    else
	echo "Source file location not found. Exiting shell script."
	break
    fi
done
