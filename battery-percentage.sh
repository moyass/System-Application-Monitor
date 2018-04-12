#!/bin/bash

# Get battery percentage

BATTERY_DIRECTORIES=()
while IFS= read -r line; do
    BATTERY_DIRECTORIES+=( "$line" )
done < <( upower -e |grep battery )

for i in "${BATTERY_DIRECTORIES[@]}"
do
        #echo $i
        percentage=$(upower -i ${i} | grep "percentage" |awk {'print $2'} | sed 's/\%//g')
        sum=`expr $sum + $percentage`
done

avg=`echo "$sum / ${#BATTERY_DIRECTORIES[@]}" | bc -l`
printf '%0.2f' "$avg"

