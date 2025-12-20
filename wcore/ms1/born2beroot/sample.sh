#!/bin/bash

read totalMB usedMB <<< $(df -m -x tmpfs -x devtmpfs | awk '$1 ~ "^/dev/" && $6 != "/boot" && $6 != "/boot/efi" {u+=$3; t+=$2} END {print t, u}'
)

totalGB=$(echo "scale=0; $totalMB/1024" | bc)

usedGB=$(echo "scale=0; $usedMB/1024" | bc)

GBpercent=$(echo "scale=2; $usedGB/$totalGB*100" | bc)

test1=$(df -m | awk '/dev\/nvme0n1p2/ {print $2
}')
test2=$(df -m | awk '/run$/ {print $2}')
percent=$(echo "scale=2; $test1/$test2*100" | bc)

if [ $test1 -lt 1024 ]; then
	final1=$(($test1*1024));
	else 
		final1=$test1;
fi


if [ $test2 -lt 1024 ]; then
	final2=$(($test2*1024));
	else
		final2=$test2;
fi

#echo "\
#totalM: $totalMB
#usedM: $usedMB
#totalG: $totalGB
#usedG: $usedGB
#percent: $GBpercent"

echo "\
test1: $test1
test2: $test2
percent: $(printf "(%.0f%%)" $percent)"